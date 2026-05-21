/*
 * uart.h
 *
 *  Created on: May 21, 2026
 *      Author: User
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#include <stdint.h>
void UART2_Init(void);
void UART2_SendChar(char c);
void UART2_SendString(char *str);
void UART2_SendNumber(int num);

#endif /* UART_H_ */
