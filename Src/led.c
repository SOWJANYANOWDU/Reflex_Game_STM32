/*
 * led.c
 *
 *  Created on: May 21, 2026
 *      Author: User
 */


#include "led.h"

void LED_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER |=  (1 << (5 * 2));     // PA5 output
}

void LED_On(void)
{
    GPIOA->BSRR = (1 << 5);
}

void LED_Off(void)
{
    GPIOA->BSRR = (1 << (5 + 16));       // F4 has no BRR, use BSRR upper bits
}

void LED_Toggle(void)
{
    GPIOA->ODR ^= (1 << 5);
}
