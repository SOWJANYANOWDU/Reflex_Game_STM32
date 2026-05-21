/*
 * led.h
 *
 *  Created on: May 21, 2026
 *      Author: User
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"
#include <stdint.h>
void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif /* LED_H_ */
