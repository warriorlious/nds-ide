/*
 * Exp_Sample.c
 *
 *  Created on: 2011. 11. 9.
 *      Author: Minsuk Lee
 */

// Free RTOS Headers
// See AI reference Document in http://www.freertos.org/
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

#include <nds.h>
#include <sevencore_io.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COLOR_RED		RGB(31,  0,  0) /* Bright Red  	*/
#define COLOR_WHITE	RGB(31, 31, 31) /* Bright White */
#define COLOR_BLACK	RGB( 0,  0,  0)
#define COLOR_GREEN	RGB(0,  31,  0)

#define BOX_WIDTH		16
#define BOX_HEIGHT	16
#define MAX_X		(SCREEN_WIDTH / BOX_WIDTH)
#define MAX_Y		(SCREEN_HEIGHT / BOX_HEIGHT)

// define added 11/10/2011
#define BG_GFX			((u16*)0x6000000)
#define SCREEN_WIDTH	256

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

struct parameters{
	char *taskname;
	int direction;
	int basePoint;
	int color;
	int delay;
};

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
Exp_Homework(struct parameters *p)
{
    u8 key, old_key = -1;

    while (1) {
    	switch(p->direction){
    	case RIGHT:
    		if(key < BOX_WIDTH-1){
				draw_my_box(old_key, p->basePoint, COLOR_BLACK);	// Erase the Previous Box
				draw_my_box(key, p->basePoint, p->color);	// Erase the Previous Box
				vTaskDelay(300);
				old_key = key;
				key++;
    		}else{
    			p->direction = LEFT;
    		}
			break;
    	case LEFT:
    		if(key > 0){
    			draw_my_box(old_key, p->basePoint, COLOR_BLACK);	// Erase the Previous Box
    			draw_my_box(key, p->basePoint, p->color);	// Erase the Previous Box
    			vTaskDelay(300);
    			old_key = key;
    			key--;
    		}else{
    			p->direction = RIGHT;
    		}
    		break;
    	case UP:
    		if(key > 0){
    			draw_my_box(p->basePoint, old_key, COLOR_BLACK);	// Erase the Previous Box
    			draw_my_box(p->basePoint, key, p->color);	// Erase the Previous Box
    			vTaskDelay(300);
    			old_key = key;
    			key--;
    		}else{
    			p->direction = DOWN;
    		}
    		break;
    	case DOWN:
    		if(key < BOX_HEIGHT-5){
    			draw_my_box(p->basePoint, old_key, COLOR_BLACK);	// Erase the Previous Box
    			draw_my_box(p->basePoint, key, p->color);	// Erase the Previous Box
    			vTaskDelay(300);
    			old_key = key;
    			key++;
    		}else{
    			p->direction = UP;
    		}
    		break;
    	}
    	vTaskDelay(p->delay);
     }
}
