/*
 * timer.h
 *
 *  Created on: May 21, 2026
 *      Author: User
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"
#include <stdint.h>
void Timer2_Init(void);
void delay_ms(int ms);
uint32_t millis(void);

#endif /* TIMER_H_ */
