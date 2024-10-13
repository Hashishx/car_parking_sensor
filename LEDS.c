/*
 * LEDS.c
 *
 *  Created on: Oct 4, 2024
 *      Author: mahmo
 */

#include "LEDS.h"
#include "gpio.h"

void LEDS_init(void) {
	/* Initializes all LEDS (red, green, blue) pins direction */
	GPIO_setupPinDirection(PORTC_ID, LED_PIN0_ID, LOGIC_HIGH);
	GPIO_setupPinDirection(PORTC_ID, LED_PIN1_ID, LOGIC_HIGH);
	GPIO_setupPinDirection(PORTC_ID, LED_PIN2_ID, LOGIC_HIGH);
	/* Turns off all the LEDS */
	GPIO_writePin(PORTC_ID, LED_PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, LED_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, LED_PIN2_ID, LOGIC_LOW);
}
void LED_on(LED_ID id) {
	/* Turns on the specified LED */
	GPIO_writePin(PORTC_ID, id, LOGIC_HIGH);
}
void LED_off(LED_ID id) {
	/* Turns off the specified LED */
	GPIO_writePin(PORTC_ID, id, LOGIC_LOW);
}
