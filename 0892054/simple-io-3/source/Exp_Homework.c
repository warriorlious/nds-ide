/*
 * Exp_Homework.c
 *
 *  Created on: 2011. 9. 22.
 *      Author: Minsuk Lee
 */

#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

portTickType short_timer = 0;
portTickType start_time_x = 0;
u16 barled;
u32 barled_sw = BARLED1;
int cur_led;
int
#define NUM_STATE	9
#define NUM_INPUT	4

// Actions

f_ts(void *p)
{
	start_time_x = xTaskGetTickCount();
}

end_ts(void *p)
{
	short_timer = xTaskGetTickCount();
}
static
void
S(void *p)
{
	if(cur_led != 8)
		cur_led = 0x080;
	else
		cur_led = cur_led/2;

	if(cur_led = 0xff){
		if(barled_sw == BARLED2)
			barled_sw = BARLED1;
		else
			barled_sw = BARLED2;
		cur_led = 0x080;
	}

	printf("S\n");
	writeb_virtual_io(BARLED1, cur_led);
	writeb_virtual_io(BARLED2, 0);
}

static
void
L(void *p)
{
	printf("L\n");
	writeb_virtual_io(BARLED1, 0x80);
	writeb_virtual_io(BARLED2, 0);
}
static
void
S_S(void *p)
{
	printf("SS\n");
	cur_led= cur_led *2;
	writeb_virtual_io(BARLED1, cur_led);

}
static
void
S_L(void *p)
{
	printf("SL\n");
	writeb_virtual_io(BARLED1, 0xfc);
	writeb_virtual_io(BARLED2, 0);
}
static
void
L_S(void *p)
{
	printf("LS\n");
	writeb_virtual_io(BARLED1, 0xFF);
	writeb_virtual_io(BARLED2, 0xFF);
}

static
void
L_L(void *p)
{
	printf("LL\n");
	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, 0);
}

struct state_machine_x {
	int check_timer;
	int next_state[NUM_INPUT];
	void (* action[NUM_INPUT])(void *p);
};
enum { SW_ON, SW_OFF, TO , STO};

struct state_machine_x SM[NUM_STATE] = {
		   // SW_ON              SW_OFF           TO
    { 0, { 1, 0, 0, 0 }, { f_ts, NULL, NULL, NULL },},    /* State 0 */
    { 1, { 1, 3, 2, 0 }, { NULL, end_ts, NULL, NULL },},
    { 0, { 2, 4, 0, 0 }, { NULL, end_ts, NULL, NULL },},
    { 2, { 5, 3, 0, 0 }, { NULL, f_ts, NULL, S },},
    { 2, { 6, 4, 0, 0 }, { NULL, f_ts, NULL, L },},
    { 1, { 5, 0, 7, 0 }, { NULL, S_S, NULL, NULL },},
    { 1, { 6, 0, 8, 0 }, { NULL, L_S, NULL, NULL },},
    { 0, { 7, 0, 0, 0 }, { NULL, S_L, NULL, NULL },},
    { 0, { 8, 0, 0, 0 }, { NULL, L_L, NULL, NULL },},
	// Fill here
};

void
Exp_3_Homework(void)
{
    int state;
    int input;

	printf("089054-HomeWork\n");

	state = 0;							// Initial State 0 : All LED Off
	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, 0);

	while (1) {
		/* Step 0: Generate Input Event */
		if (SM[state].check_timer==1) {
			if ((xTaskGetTickCount() - start_time_x) >= MSEC2TICK(300)) {
				input = TO;
				goto do_action;		// Input happens
			}
		}

		if (SM[state].check_timer ==2) {
			if ((xTaskGetTickCount() - short_timer) >= MSEC2TICK(200)) {
				input = STO;
				goto do_action;		// Input happens
			}
		}
		if (NDS_SWITCH() & KEY_A){
			input = SW_ON;
		}
		else
			input = SW_OFF;

		/* Step 1: Do Action */
do_action:
		if (SM[state].action[input]){
			SM[state].action[input](NULL);
		}
		/* Step 2: Set Next State */
		state = SM[state].next_state[input];
		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(MSEC2TICK(50));
	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10));		// Wait while START KEY is being pressed
}
