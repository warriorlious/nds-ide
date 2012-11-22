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

#define BOX_WIDTH 	8
#define BOX_HEIGHT	8
#define BOX_Y_POS	   13
#define BOX_X_MAX	(SCREEN_WIDTH / BOX_WIDTH)

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT 2

int wall = -1;
int x = 0, y, prevX, prevY;

void draw_my_box(int pos_x, int pos_y, u16 color) {
	int i, j;
	u32 *basePoint, pixel;

	pixel = (color << 16) + color;
	for (i = 0; i < BOX_HEIGHT; i++) {
		basePoint = (u32 *) BG_GFX
				+ ((((pos_y * BOX_HEIGHT) + i) * SCREEN_WIDTH)
						+ pos_x * BOX_WIDTH) / 2;
		for (j = 0; j < (BOX_WIDTH / 2); j++)
			*basePoint++ = pixel;
	}
}

void draw_my_wall(int pos_x, int pos_y, u16 color) {
	// draw big white box
	int i;

	for (i = 0; i <= pos_x; i++) {
		draw_my_box(i, pos_y, color);
		draw_my_box(i, pos_y + 1, color);
		draw_my_box(i, pos_y + 2, color);
		draw_my_box(i, pos_y - 1, color);
		draw_my_box(i, pos_y - 2, color);
	}
}

extern xTaskHandle BallTask;

void Exp_8_Homework_A(void) {
	while (1) {

	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);		// Wait while START KEY is being pressed
}

void Exp_8_Homework_B(void) {

	u8 key;
	int preWall;
	xSemaphoreHandle xSemaphore;

	vSemaphoreCreateBinary(xSemaphore);

	vTaskResume(BallTask);

	key_init();

	while (1) {

		key = getkey();

		if (key == 15) {
			break;
		}
		else if (key > 7)
			continue;

		wall = key * 4;

		if (x <= wall) {
			while (!xSemaphoreTake(xSemaphore, (portTickType)0));
		}

		draw_my_wall(preWall, BOX_Y_POS, COLOR_BLACK);
		draw_my_wall(wall, BOX_Y_POS, COLOR_WHITE);

		if (x <= wall)
			xSemaphoreGive(xSemaphore);

		preWall = wall;
	}
}

portTASK_FUNCTION(Ball_Task, pvParameters) {

	int direction = DIRECTION_LEFT;

	x = BOX_X_MAX - 1;
	y = BOX_Y_POS;

	prevX = 0;
	prevY = 0;

	while (1) {

		draw_my_box(prevX, prevY, COLOR_BLACK);
		draw_my_box(x, y, COLOR_RED);
		vTaskDelay(MSEC2TICK((1000 / (BOX_X_MAX - wall + 3))) );

		prevX = x;
		prevY = y;

		if (direction == DIRECTION_RIGHT) {
			x++;
			if (x == BOX_X_MAX - 1)
				direction = DIRECTION_LEFT;

		} else if (direction == DIRECTION_LEFT) {
			x--;
			if (x <= wall + 1)
				direction = DIRECTION_RIGHT;
		}
	}
}
// Key Matrix Scanning Task

void key_init(void) {

	int i;
	u8 key;

	for (i = 0; i < MAX_KEY_LOG; i++)
		xQueueReceive(KeyQueue, &key, 0);
}

int kbhit(void) {

	u8 key;
	int ret = xQueuePeek(KeyQueue, &key, 0);
	return (ret == pdPASS);
}

u8 getkey(void) {

	u8 key;
	xQueueReceive(KeyQueue, &key, portMAX_DELAY);
	return key;
}

portTASK_FUNCTION(Key_Task, pvParameters) {

	u8 key, scan = 0;
	u8 key_pressed = FALSE;

	key_init();

	while (1) {

		if (key_pressed == FALSE) {

			writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
			key = scan * 4;

			switch (readb_virtual_io(KEY_MATRIX)) {
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

			if ((key < 16)) {
				key_pressed = TRUE;
				xQueueSend(KeyQueue, &key, 0);
			}
		}

		if ((key_pressed == TRUE) && (readb_virtual_io(KEY_MATRIX) == 0))
			key_pressed = FALSE;

		vTaskDelay(MSEC2TICK(30) );
	}
}
