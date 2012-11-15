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
	//while (pdPASS != xQueueReceive(KeyQueue, &key, 0))
	//		vTaskDelay(MSEC2TICK(5));
	return key;
}

void
Exp_5_Homework_A(void)
{
	u8 keyQue[8];
	int keyQueFlag = 0;
	int i;

	for (i=0; i<8; i++)              //led 표시값 배열 초기화
	    	keyQue[i] = 0x80;
	while(1){
		keyQue[keyQueFlag%8]=getkey();
		if(keyQue[keyQueFlag%8]==0)
			break;
		keyQueFlag++;
		for(i=0; i<8; i++){
			u8 ledPos = 0x00+(0x10*i);
			u8 ledNum = keyQue[(keyQueFlag+i)%8];
			writeb_virtual_io(SEG7LED, ledPos + ledNum);
		}
	}
}

void
Exp_5_Homework_B(void)
{
	u8  keyQue[8];
	u8  barled = 1;
	int tickCount = 0;
	int keyQueFlag = 0;
	int i;
	portTickType xLastWakeTime = xTaskGetTickCount();

	for (i=0; i<8; i++)              //led 표시값 배열 초기화
	    keyQue[i] = 0x80;
	for(i=0; i<8; i++){              //led 화면 초기
		u8 ledPos = 0x00+(0x10*i);
		u8 ledNum = 0x80;
		writeb_virtual_io(SEG7LED, ledPos + ledNum);
	}
	while(1){
		tickCount++;
		if(tickCount == 50){
			tickCount = 0;
			writeb_virtual_io(BARLED1, barled);
			if(barled!=128)
				barled=barled*2;
			else
				barled=1;
		}
		if(kbhit()==1){
			keyQue[keyQueFlag%8]=getkey();
			keyQueFlag++;
			for(i=0; i<8; i++){
				u8 ledPos = 0x00+(0x10*i);
				u8 ledNum = keyQue[(keyQueFlag+i)%8];
				writeb_virtual_io(SEG7LED, ledPos + ledNum);
			}
		}
		if (NDS_SWITCH() & KEY_START){
			for(i=0; i<8; i++){              //led 화면 초기
					u8 ledPos = 0x00+(0x10*i);
					u8 ledNum = 0x80;
					writeb_virtual_io(SEG7LED, ledPos + ledNum);
				}
			break;
		}
		vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(10));
	}
}

portTASK_FUNCTION(Key_Task, pvParameters)
{
	u8 key, scan=0;
	u8  bKey[4] = {255,255,255,255};

	while(1){
		writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
		key = scan * 4;
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
		if (key < 16){
			if(key != bKey[scan]){
				xQueueSend(KeyQueue,&key,0);
				bKey[scan] = key;
			}
		}
		else
			bKey[scan] = key;

		vTaskDelay(MSEC2TICK(30));
	}
}