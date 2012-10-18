#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

void
Exp_4_Homework_A(void)
{
	// Variables
	u8 key, scan = 0;
	u8 key_arr[NUM_7SEG_LED];
	u8 key_pressed = FALSE;
	u8 cnt = 0;
	u8 sw1 = FALSE;	// SCROLL DIRECTION / FALSE = (RIGHT->LEFT) : TRUE = (LEFT->RIGHT)
	int i;

	for (i = 0; i < NUM_7SEG_LED; i++)					// Turn Off All
		writeb_virtual_io(SEG7LED, 0x80 + (i << 4));

	while (1) {

		// Fill Here

		writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
		key = scan * 4;

		if (readb_virtual_io(PUSH_SW) == VIRTUAL_SW_1) {
			sw1 = !sw1;
			cnt = 0;

			for (i = 0; i < NUM_7SEG_LED; i++)					// Turn Off All
				writeb_virtual_io(SEG7LED, 0x80 + (i << 4));
		}

		switch (readb_virtual_io(KEY_MATRIX)) {
			case 8 :  key += 1; break;
			case 4 :  key += 2; break;
			case 2 :  key += 3; break;
			case 1 :  key += 4; if (key == 16) key = 0; break;
			default : key = 255; break;
		}

		scan++;
		if (scan == 4)
			scan = 0;

		if ((key_pressed == TRUE) && (key != key_arr[cnt - 1]))
			key_pressed = FALSE;

		if ((key < 16) && (key_pressed == FALSE)) {
			key_pressed = TRUE;

			if (cnt == NUM_7SEG_LED) {
				for(i = 0; i < cnt - 1; i++)
					key_arr[i] =  key_arr[i + 1];
				key_arr[cnt - 1] = key;
			}
			else {
				cnt++;
				key_arr[cnt - 1] = key;
			}

			if(sw1 == FALSE) {
				for(i = 0; i < cnt; i++)
					writeb_virtual_io(SEG7LED, (0x70 - (i << 4)) + key_arr[cnt - i - 1]);
			}
			else {
				for(i = 0; i < cnt; i++)
					writeb_virtual_io(SEG7LED, (i << 4) + key_arr[cnt - i - 1]);
			}
		}

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(MSEC2TICK(20));
	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10));		// Wait while START KEY is being pressed
}

