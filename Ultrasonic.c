/*
 *  Module: Ultrasonic
 *
 *  Created on: Oct 11, 2024
 *
 *  Author: Mahmoud Hashish
 */

#include "Ultrasonic.h"
#include "icu.h"
#include <util/delay.h>
#include "lcd.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 distance = 90;

void Ultrasonic_init(void) {
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	ICU_init(&ICU_Configurations);

	GPIO_setupPinDirection(PORTD_ID, PIN7_ID, LOGIC_HIGH);
	GPIO_setupPinDirection(PORTD_ID, PIN6_ID, LOGIC_HIGH);
	//GPIO_writePin(PORTD_ID, PIN6_ID, LOGIC_HIGH);
}

void Ultrasonic_Trigger(void) {
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_LOW);
}
void Ultrasonic_edgeProcessing(void) {
	/* This is the call-back function */
	g_edgeCount++;
	if (g_edgeCount == 1) {
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	} else if (g_edgeCount == 2) {
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		ICU_clearTimerValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
	}

}
uint16 Ultrasonic_readDistance(void) {

	if(g_edgeCount == 2) {
		//ICU_deInit();
		g_edgeCount = 0;
		distance = (g_timeHigh / 118) + 1;
	}
	return distance;
}
