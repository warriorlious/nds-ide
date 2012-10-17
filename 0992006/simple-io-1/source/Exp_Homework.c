/*
 * Exp_Homework.c
 *
 *  Created on: 2011. 9. 22.
 *      Author: Minsuk Lee
 */

#include <stdio.h>			// C-Standard Header
#include <time.h>
#include <stdlib.h>

#include "FreeRTOS.h"		// Free RTOS Headers
#include "task.h"

#include <nds.h>			// NDS / Sevencore Board Headers
#include <sevencore_io.h>
#include "realio.h"

// LED Bar Left-and-Right (BARLED 1)
// LEFT key - going left, RIGHT key - going right
// 일단 A는 finish
/*
 *
 * */
void
Exp_1_Homework_A(void)
{
	u16 sw;
	u8 led_state = 0x01;
	u8  key_pressed = FALSE;
	writeb_virtual_io(BARLED1, led_state);

	while(1){
		sw = NDS_SWITCH();

		// left section
		if (((key_pressed == FALSE) && (sw & KEY_LEFT))) {
			key_pressed = TRUE;
			if((led_state == (0x01 << 7))){
				led_state = 0x01 <<7 ;
			}
			else
				led_state = led_state << 1;
			writeb_virtual_io(BARLED1, led_state);
		}
		if (((key_pressed == TRUE) && (sw & KEY_LEFT))) {
			key_pressed = FALSE;

		}

		//right section
		if (((key_pressed == FALSE) && (sw & KEY_RIGHT))) {
			key_pressed = TRUE;
			if((led_state == (0x01))){
				led_state = 0x01;}
			else{
				led_state = led_state >> 1;
			}
			writeb_virtual_io(BARLED1, led_state);
		}
		if (((key_pressed == TRUE) && (sw & KEY_RIGHT))) {
			key_pressed = FALSE;

		}

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(50);

	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);		// Wait while START KEY is being pressed
}





// LED Bar Left-and-Right & Round (BARLED 1 and BARLED 2)
// L key - going left, R key - going right
void Exp_1_Homework_B(void)
{
	u8 keypressed = FALSE;

	u16 sw;
	u16 led_state = 0x00;
	u16 location = BARLED1;

	writeb_virtual_io(BARLED1, led_state);
	writeb_virtual_io(BARLED2, 0);

while (1) {
sw = NDS_SWITCH();

	if (!keypressed && (sw & KEY_L)) {
		led_state = led_state << 1;
		keypressed = TRUE;
	}

	else if (!keypressed && (sw & KEY_R)) {
		led_state = led_state >> 1;
		keypressed = TRUE;
	}

	if (keypressed && (!(sw & KEY_L) && !(sw & KEY_R)))
		keypressed = FALSE;

	if (location == BARLED1) {
		if ((sw & KEY_L) && led_state > (0x01 << 7)) {
			led_state = 0x01;
			writeb_virtual_io(location, 0);
			location = BARLED2;
		}
		else if ((sw & KEY_R) && led_state < 0x01) {
			led_state = (0x01 << 7);
			writeb_virtual_io(location, 0);
			location = BARLED2;
		}
	}

	else if (location == BARLED2) {
		if ((sw & KEY_R) && led_state < 0x01) {
			led_state = (0x01 << 7);
			writeb_virtual_io(location, 0);
			location = BARLED1;
		}
		else if ((sw & KEY_L) && led_state > (0x01 << 7)) {
			led_state = 0x01;
			writeb_virtual_io(location, 0);
			location = BARLED1;
		}
	}

	writeb_virtual_io(location, led_state);

	if (NDS_SWITCH() & KEY_START)
		break;
	vTaskDelay(50);
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);
}

