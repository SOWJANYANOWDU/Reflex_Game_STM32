/*
 * game.c
 *
 *  Created on: May 21, 2026
 *      Author: User
 */



#include "game.h"
#include "uart.h"
#include "led.h"
#include "timer.h"
#include "button.h"

extern volatile uint8_t button_pressed;

void Game_Init(void)
{
    UART2_SendString("\r\n===== REACTION TIMER GAME =====\r\n");
}

static int random_delay()
{
    return 2000 + (millis() % 3000); // 2–5 sec
}

void Game_Run(void)
{
    char c;

    UART2_SendString("\r\nPress ENTER to start...\r\n");

    while (1)
    {
    	if (USART2->SR & USART_SR_RXNE)
    	{
    	    c = USART2->DR;

            if (c == '\r')
            {
                button_pressed = 0;

                UART2_SendString("\r\nGet Ready...\r\n");

                delay_ms(random_delay());

                UART2_SendString("GO!\r\n");
                LED_On();

                uint32_t start = millis();

                while (!button_pressed);

                uint32_t reaction = millis() - start;

                LED_Off();

                UART2_SendString("Reaction Time: ");
                UART2_SendNumber(reaction);
                UART2_SendString(" ms\r\n");

                if (reaction < 200)
                    UART2_SendString("Excellent!\r\n");
                else if (reaction < 350)
                    UART2_SendString("Good!\r\n");
                else
                    UART2_SendString("Slow!\r\n");
            }
        }
    }
}
