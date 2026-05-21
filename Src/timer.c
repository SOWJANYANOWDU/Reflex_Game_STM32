/*
 * timer.c
 *
 *  Created on: May 21, 2026
 *      Author: User
 */



#include "timer.h"

volatile uint32_t tick = 0;

void Timer2_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->PSC = 16 - 1;      // APB1 timer clock = 90 MHz → 1 MHz tick
    TIM2->ARR = 1000 - 1;    // 1 ms overflow

    TIM2->DIER |= TIM_DIER_UIE;
    TIM2->CR1  |= TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;
        tick++;
    }
}

uint32_t millis(void)
{
    return tick;
}

void delay_ms(int ms)
{
    uint32_t start = millis();
    while ((millis() - start) < ms);
}
