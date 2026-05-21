/*
 * uart.c
 *
 *  Created on: May 21, 2026
 *      Author: User
 */



#include "uart.h"

void UART2_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;   // AHB1 not AHB
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // PA2 -> TX, PA3 -> RX (same pins)
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2)));
    GPIOA->MODER |=  ((2 << (2 * 2)) | (2 << (3 * 2)));

    GPIOA->AFR[0] |= (7 << (2 * 4)) | (7 << (3 * 4)); // AF7 same

   // USART2->BRR = 45000000 / 115200;  // APB1 = 45 MHz
    USART2->BRR = 16000000 / 115200;   // HSI default = 16MHz

    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void UART2_SendChar(char c)
{
    while (!(USART2->SR & USART_SR_TXE));   // ISR → SR
    USART2->DR = c;                          // TDR → DR
}

void UART2_SendString(char *str)
{
    while (*str)
        UART2_SendChar(*str++);
}

void UART2_SendNumber(int num)
{
    char buf[10];
    int i = 0;

    if (num == 0)
    {
        UART2_SendChar('0');
        return;
    }

    while (num > 0)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
        UART2_SendChar(buf[i]);
}
