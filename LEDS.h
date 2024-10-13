/*
 *  Module: LEDS
 *
 *  Created on: Oct 4, 2024
 *
 *  Author: Mahmoud Hashish
 */

#ifndef LEDS_H_
#define LEDS_H_

typedef enum {
	LED_PIN0_ID, LED_PIN1_ID, LED_PIN2_ID
}LED_ID;

void LEDS_init(void);

void LED_on(LED_ID id);

void LED_off(LED_ID id);

#endif /* LEDS_H_ */
