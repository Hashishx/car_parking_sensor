/*
 *  Project: car_Parking_Sensor
 *
 *  Created on: Oct 11, 2024
 *
 *  Author: Mahmoud Hashish
 */

#include "Ultrasonic.h"
#include "lcd.h"
#include "Buzzer.h"
#include "LEDS.h"
#include <avr/io.h>
#include "icu.h"
#include <util/delay.h>


int main(void) {

	uint16 Distance = 0;
	LCD_init();			/* initialize LCD */
	Buzzer_init();		/* initialize BUZZER */
	LEDS_init();		/* initialize LEDS */
	/* display this string only once on the screen */
	LCD_displayString("Distance =    cm");
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	/* initialize ultrasonic sensor */
	Ultrasonic_init();
	while (1) {
		/* Send the trigger pulse to begin to receive the echo pulse from Ultrasonic sensor */
		Ultrasonic_Trigger();
		/* Calculate the distance */
		Distance = Ultrasonic_readDistance();
		/* display the actual distance value on screen */
		LCD_moveCursor(0, 11);
		if (Distance >= 100) {
			LCD_intgerToString(Distance);
		} else {
			LCD_intgerToString(Distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* conditions for implementing LEDS and buzzer according to the distance measured */
		if (Distance <= 5) {
			Buzzer_on();
			LCD_moveCursor(1,7);
			LCD_displayString("STOP");
			LED_on(LED_PIN0_ID);
			LED_on(LED_PIN1_ID);
			LED_on(LED_PIN2_ID);
			_delay_ms(500);
			LED_off(LED_PIN0_ID);
			LED_off(LED_PIN1_ID);
			LED_off(LED_PIN2_ID);
			_delay_ms(500);
		}
		else if (Distance >=6 && Distance <= 10) {
			Buzzer_off();
			LCD_moveCursor(1,7);
			LCD_displayString("    ");
			LED_on(LED_PIN0_ID);
			LED_on(LED_PIN1_ID);
			LED_on(LED_PIN2_ID);
		}
		else if (Distance >=11 && Distance <= 15) {
			Buzzer_off();
			LCD_moveCursor(1,7);
			LCD_displayString("    ");
			LED_off(LED_PIN2_ID);
			LED_on(LED_PIN0_ID);
			LED_on(LED_PIN1_ID);
		}
		else if (Distance >= 16 && Distance <= 20) {
			Buzzer_off();
			LCD_moveCursor(1,7);
			LCD_displayString("    ");
			LED_off(LED_PIN1_ID);
			LED_off(LED_PIN2_ID);
			LED_on(LED_PIN0_ID);
		}
		else if (Distance > 20) {
			Buzzer_off();
			LCD_moveCursor(1,7);
			LCD_displayString("    ");
			LED_off(LED_PIN0_ID);
			LED_off(LED_PIN1_ID);
			LED_off(LED_PIN2_ID);
		}
	}
}
