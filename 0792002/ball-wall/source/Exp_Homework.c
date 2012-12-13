// Free RTOS Headers
// See API reference Document in http://www.freertos.org/

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

// NDS / Sevencore Board Headers
#include <nds.h>
#include <sevencore_io.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COLOR_RED       RGB(31,  0,  0) /* Bright Red  	*/
#define COLOR_WHITE     RGB(31, 31, 31) /* Bright White */
#define COLOR_BLACK     RGB( 0,  0,  0)	/* Black : Zero	*/

#define BOX_WIDTH	8
#define BOX_HEIGHT	8
#define BOX_Y_POS	13
#define BOX_X_MAX	(SCREEN_WIDTH / BOX_WIDTH)

#define WALL_WIDTH 32
#define WALL_HEIGHT 32
#define WALL_Y_POS 3
#define WALL_X_MAX (SCREEN_WIDTH / WALL_WIDTH)

#define LEFT_DIRECTION 0
#define RIGHT_DIRECTION 1

xSemaphoreHandle semaphore;
u8 r_point;
u8 ball_x=0;

void
draw_my_box(int pos_x, int pos_y, u16 color)
{
	int i, j;
    u32 *basePoint, pixel;

    pixel = (color << 16) + color;
    for (i = 0; i < BOX_HEIGHT; i++) {
 	    basePoint = (u32 *)BG_GFX +
 	      ((((pos_y * BOX_HEIGHT) + i) * SCREEN_WIDTH) + pos_x * BOX_WIDTH) / 2;
    	for (j = 0; j < (BOX_WIDTH / 2); j++)
    		*basePoint++ = pixel;
	}
}

void
draw_my_wall(int pos_x, int pos_y, u16 color)
{
	int i, j;
	 u32 *basePoint, pixel;

	  pixel = (color << 16) + color;
	    for (i = 0; i < WALL_HEIGHT; i++) {
	 	    basePoint = (u32 *)BG_GFX +
	 	      ((((pos_y * WALL_HEIGHT) + i) * SCREEN_WIDTH) + pos_x * WALL_WIDTH) / 2;
	    	for (j = 0; j < (WALL_WIDTH / 2); j++)
	    		*basePoint++ = pixel;
		}

}

extern xTaskHandle BallTask;

void
Exp_8_Homework_A(void)
{
	u8 x=0;
	u8 prevX=0;

    while (1) {
    	if(kbhit()){
    	x=getkey();
    	if(x>=WALL_X_MAX)
    		continue;
    	draw_my_wall(prevX,WALL_Y_POS,COLOR_BLACK);
    	draw_my_wall(x,WALL_Y_POS,COLOR_WHITE);
    	prevX=x;
    }
    	if(NDS_SWITCH()&KEY_START){
    		draw_my_wall(prevX,WALL_Y_POS,COLOR_BLACK);
    		break;
    	}
    }
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);		// Wait while START KEY is being pressed
}

void
Exp_8_Homework_B(void)
{
   vSemaphoreCreateBinary(semaphore);
   u8 x=0;
   u8 prevX=0;
   int i=0;
   r_point=0;

    vTaskResume(BallTask);

	while (1) {
		if(kbhit()){
			x=getkey();
			if(x>=WALL_X_MAX)
				continue;
			for(i=0;i<prevX;i++)
				draw_my_wall(i,WALL_Y_POS,COLOR_BLACK);
			for(i=0;i<x;){
				if(xSemaphoreTake(semaphore,(portTickType)0)==pdTRUE){
					if((i+1)*4 <=ball_x-1){
						draw_my_wall(i,WALL_Y_POS,COLOR_WHITE);
						i++;
					}
					xSemaphoreGive(semaphore);
					r_point=(i*4);
					vTaskDelay((portTickType)20);
				}
			}
			r_point=(x*4);
			prevX=x;
		}
		if(NDS_SWITCH()& KEY_START){
			for(i=0;i>WALL_X_MAX;i++)
				draw_my_wall(i,WALL_Y_POS,COLOR_BLACK);
			vTaskSuspend(BallTask);
			break;
		}
	}
	while(NDS_SWITCH()&KEY_START)
		vTaskDelay(10);
}

portTASK_FUNCTION(Ball_Task, pvParameters)
{
	u8 direction= RIGHT_DIRECTION;
	portTickType xLastWakeTime= xTaskGetTickCount();
	int tick_time,until_time;

	while (1) {
		if(ball_x==r_point){
			direction = RIGHT_DIRECTION;
				tick_time = 1000 / (BOX_X_MAX - ball_x);
			} else if (ball_x == (BOX_X_MAX - 1)) {
				direction = LEFT_DIRECTION;
				until_time = 0;
			}
			draw_my_box(ball_x, BOX_Y_POS, COLOR_BLACK);
			xSemaphoreTake(semaphore, (portTickType)0);
			if (direction == LEFT_DIRECTION) {
				ball_x--;
				tick_time = (1000 - until_time) / (ball_x - r_point + 1);
			} else if (direction == RIGHT_DIRECTION) {
				ball_x++;
			}
			xSemaphoreGive(semaphore);
			draw_my_box(ball_x, BOX_Y_POS, COLOR_RED);

			until_time += tick_time;
			if(until_time >= 1000)
				until_time = 1000;

			vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(tick_time));
		}
	}

// Key Matrix Scanning Task

void
key_init(void)
{
	int i;
	u8 key;

	for (i = 0; i < MAX_KEY_LOG; i++)
		xQueueReceive(KeyQueue, &key, 0);
}

int
kbhit(void)
{
	u8 key;
	int ret = xQueuePeek(KeyQueue, &key, 0);
	return (ret == pdPASS);
}
u8
getkey(void)
{
	u8 key;
	xQueueReceive(KeyQueue, &key, portMAX_DELAY);
	return key;
}

portTASK_FUNCTION(Key_Task, pvParameters){
u8 key, key_m, scan = 0, key_s = FALSE;

while (1) {
	if (key_s && (readb_virtual_io(KEY_MATRIX) != key_m
			|| !readb_virtual_io(KEY_MATRIX)))
		key_s = FALSE;
	if (!key_s) {
		writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
		key = scan * 4;
		key_m = readb_virtual_io(KEY_MATRIX);
		switch (key_m) {
		case 8:
			key += 1;
			break;
		case 4:
			key += 2;
			break;
		case 2:
			key += 3;
			break;
		case 1:
			key += 4;
			if (key == 16)
				key = 0;
			break;
		default:
			key = 255;
			break;
		}
		scan++;
		if (scan == 4)
			scan = 0;
		if (key < 16) {
			xQueueSend(KeyQueue, &key, portMAX_DELAY);
			key_s = TRUE;
		}
	}
	vTaskDelay(MSEC2TICK(30) );
}
}
