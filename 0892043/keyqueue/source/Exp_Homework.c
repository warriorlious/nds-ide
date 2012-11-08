#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

extern xQueueHandle KeyQueue;
#define MAX_KEY_LOG		10

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
	//while (pdPASS != xQueueReceive(KeyQueue, &key, 0))
	//		vTaskDelay(MSEC2TICK(5));
	return key;
}

void Exp_5_Homework_A(void) {
	int i;
	u8 key;
	u8 led[8];

	for (i = 0; i < 8; i++) {
		led[i] = 0x80;
	}

	writeb_virtual_io(SEG7LED, 0x70 + led[0]);
	writeb_virtual_io(SEG7LED, 0x60 + led[1]);
	writeb_virtual_io(SEG7LED, 0x50 + led[2]);
	writeb_virtual_io(SEG7LED, 0x40 + led[3]);
	writeb_virtual_io(SEG7LED, 0x30 + led[4]);
	writeb_virtual_io(SEG7LED, 0x20 + led[5]);
	writeb_virtual_io(SEG7LED, 0x10 + led[6]);
	writeb_virtual_io(SEG7LED, 0x00 + led[7]);

	while (1) {
		key = getkey();

		if (key == 0) {
			break;
			vTaskDelay(MSEC2TICK(10) );
		}

		for (i = 7; i > 0; i--) {
			led[i] = led[i - 1];
		}
		led[0] = key;

		writeb_virtual_io(SEG7LED, 0x70 + led[0]);
		writeb_virtual_io(SEG7LED, 0x60 + led[1]);
		writeb_virtual_io(SEG7LED, 0x50 + led[2]);
		writeb_virtual_io(SEG7LED, 0x40 + led[3]);
		writeb_virtual_io(SEG7LED, 0x30 + led[4]);
		writeb_virtual_io(SEG7LED, 0x20 + led[5]);
		writeb_virtual_io(SEG7LED, 0x10 + led[6]);
		writeb_virtual_io(SEG7LED, 0x00 + led[7]);
	}
}

void Exp_5_Homework_B(void) {
	int i;
	int lr = 0;
	int timecnt = 0;
	u8 key;
	u8 led[8];
	u8 barled = 0x80;
	portTickType xLastWakeTime = xTaskGetTickCount();

	key_init();

	for (i = 0; i < 8; i++) {
		led[i] = 0x80;
	}

	writeb_virtual_io(SEG7LED, 0x70 + led[0]);
	writeb_virtual_io(SEG7LED, 0x60 + led[1]);
	writeb_virtual_io(SEG7LED, 0x50 + led[2]);
	writeb_virtual_io(SEG7LED, 0x40 + led[3]);
	writeb_virtual_io(SEG7LED, 0x30 + led[4]);
	writeb_virtual_io(SEG7LED, 0x20 + led[5]);
	writeb_virtual_io(SEG7LED, 0x10 + led[6]);
	writeb_virtual_io(SEG7LED, 0x00 + led[7]);

	while (1) {
		vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(1) );
		timecnt++;

		writeb_virtual_io(BARLED1, barled);

		if (timecnt == 500) {
			if (barled == 0x80) {
				barled = barled >> 1;
				lr++;
			}
			else if (barled == 0x01) {
				barled = barled << 1;
				lr--;
			}
			else {
				if (lr > 0)
					barled = barled >> 1;
				else
					barled = barled << 1;
			}
			timecnt = 0;
		}

		if (kbhit()) {
			key = getkey();

			for (i = 7; i > 0; i--) {
				led[i] = led[i - 1];
			}
			led[0] = key;

			writeb_virtual_io(SEG7LED, 0x70 + led[0]);
			writeb_virtual_io(SEG7LED, 0x60 + led[1]);
			writeb_virtual_io(SEG7LED, 0x50 + led[2]);
			writeb_virtual_io(SEG7LED, 0x40 + led[3]);
			writeb_virtual_io(SEG7LED, 0x30 + led[4]);
			writeb_virtual_io(SEG7LED, 0x20 + led[5]);
			writeb_virtual_io(SEG7LED, 0x10 + led[6]);
			writeb_virtual_io(SEG7LED, 0x00 + led[7]);
		}

		if (NDS_SWITCH() & KEY_START)
			break;
	}
	vTaskDelay(MSEC2TICK(10) );
}

portTASK_FUNCTION(Key_Task, pvParameters) {
	u8 key, scan = 0;
	u8 pressed = FALSE;

	while (1) {
		if (!pressed) {
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

			if (key < 16) {
				xQueueSend(KeyQueue, &key, 0);
				pressed = TRUE;
			}

			vTaskDelay(MSEC2TICK(1) );
		}

		if (pressed && readb_virtual_io(KEY_MATRIX) == 0) {
			pressed = FALSE;
		}

		vTaskDelay(MSEC2TICK(1) );
	}
}
