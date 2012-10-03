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
void
Exp_1_Homework_A(void)
{
	u16 sw;
	u8 LEFT_key_pressed = FALSE;
	u8 RIGHT_key_pressed = FALSE;
	short int curr_led = 0x0001;

	writeb_virtual_io(BARLED1, curr_led);
	writeb_virtual_io(BARLED2, 0);

	while (1) {
			sw = NDS_SWITCH();

			if((LEFT_key_pressed == FALSE) && (sw & KEY_LEFT) && (curr_led < 0x080)){
				LEFT_key_pressed = TRUE;
				curr_led = curr_led*2;
				writeb_virtual_io(BARLED1, curr_led);
			}

			if((LEFT_key_pressed == TRUE) && !(sw & KEY_LEFT))
				LEFT_key_pressed = FALSE;

			if((RIGHT_key_pressed == FALSE) && (sw & KEY_RIGHT) && (curr_led > 0X001)){
				RIGHT_key_pressed = TRUE;
				curr_led = curr_led/2;
				writeb_virtual_io(BARLED1, curr_led);
			}

			if((RIGHT_key_pressed == TRUE) && !(sw & KEY_RIGHT))
				RIGHT_key_pressed = FALSE;


			if (NDS_SWITCH() & KEY_START)
				break;
			vTaskDelay(50);
		}
		while (NDS_SWITCH() & KEY_START)
			vTaskDelay(10);
}

// LED Bar Left-and-Right & Round (BARLED 1 and BARLED 2)
// L key - going left, R key - going right
void
Exp_1_Homework_B(void)
{
	u16 sw;
	u8 L_key_pressed = FALSE;
	u8 R_key_pressed = FALSE;
	short int curr_led = 0x0001;
	u32 barled_sw = BARLED2;			// BARLED1 or BARLED2


	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, curr_led);

	while (1) {
			sw = NDS_SWITCH();

			if((L_key_pressed == FALSE) && (sw & KEY_L)){
				if(curr_led >= 0x080){
					writeb_virtual_io(barled_sw, 0);
					if(barled_sw == BARLED2)
						barled_sw = BARLED1;
					else
						barled_sw = BARLED2;
					curr_led = 0x001;
					writeb_virtual_io(barled_sw, curr_led);
				}
				else{
					L_key_pressed = TRUE;
					curr_led = curr_led*2;
					writeb_virtual_io(barled_sw, curr_led);
				}
			}

			if((L_key_pressed == TRUE) && !(sw & KEY_L))
				L_key_pressed = FALSE;

			if((R_key_pressed == FALSE) && (sw & KEY_R)){
				if(curr_led <= 0X001){
					writeb_virtual_io(barled_sw, 0);
					if(barled_sw == BARLED2)
						barled_sw = BARLED1;
					else
						barled_sw = BARLED2;
					curr_led = 0x080;
					writeb_virtual_io(barled_sw, curr_led);
				}
				else{
					R_key_pressed = TRUE;
					curr_led = curr_led/2;
					writeb_virtual_io(barled_sw, curr_led);
				}
			}

			if((R_key_pressed == TRUE) && !(sw & KEY_R))
				R_key_pressed = FALSE;


			if (NDS_SWITCH() & KEY_START)
				break;
			vTaskDelay(50);
		}
		while (NDS_SWITCH() & KEY_START)
			vTaskDelay(10);
}


