/*
 *  Module: Ultrasonic
 *
 *  Created on: Oct 11, 2024
 *
 *  Author: Mahmoud Hashish
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "icu.h"
#include "gpio.h"
#include "std_types.h"



void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

void Ultrasonic_edgeProcessing(void);

uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
