/*
 * button.h
 *
 *  Created on: May 21, 2026
 *      Author: User
 */


#ifndef BUTTON_H_
#define BUTTON_H_
#include "stm32f4xx.h"
#include <stdint.h>
void Button_Init(void);
uint8_t Button_Read(void);
void EXTI15_10_IRQHandler(void);

#endif /* BUTTON_H_ */
