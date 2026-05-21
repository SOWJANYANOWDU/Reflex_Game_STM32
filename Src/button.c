/*
 * button.c
 *
 *  Created on: May 21, 2026
 *      Author: User
 */



#include "button.h"

volatile uint8_t button_pressed = 0;

void Button_Init(void)
{
	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    GPIOC->MODER &= ~(3 << (13 * 2)); // input mode

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    SYSCFG->EXTICR[3] &= ~(0xF << 4);
    SYSCFG->EXTICR[3] |=  (0x2 << 4); // PC13

    EXTI->IMR |= (1 << 13);
    EXTI->FTSR |= (1 << 13);

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & (1 << 13))
    {
        EXTI->PR |= (1 << 13);
        button_pressed = 1;
    }
}

uint8_t Button_Read(void)
{
    return button_pressed;
}
