# Reflex Game STM32

A bare-metal reaction timer game built on STM32F446RE Nucleo board.  
No HAL. No RTOS. Just pure register-level C.

> One board. One cable. One PC. Endless learning.

---

## How It Works

1. Open a serial terminal (Docklight / PuTTY) at **115200 baud**
2. Press **Enter** to start a round
3. Wait for the **"GO!"** message and LED to glow
4. Press the **onboard button** as fast as you can
5. Your reaction time prints in milliseconds

```
===== REACTION TIMER GAME =====

Press ENTER to start...

Get Ready...
GO!
Reaction Time: 213 ms
Excellent!
```

---

## Scoring

| Result    | Reaction Time |
|-----------|---------------|
| Excellent | < 200 ms      |
| Good      | 200 – 349 ms  |
| Slow      | ≥ 350 ms      |

---

## Hardware

| Component   | Details                        |
|-------------|--------------------------------|
| Board       | STM32F446RE Nucleo-64          |
| LED         | Onboard LED — PA5              |
| Button      | Onboard Button — PC13          |
| UART        | USART2 — PA2 (TX), PA3 (RX)   |

---

## Project Structure

```
Reflex_Game_STM32/
├── Src/
│   ├── main.c       — Entry point
│   ├── button.c     — EXTI interrupt for button
│   ├── game.c       — Game logic
│   ├── led.c        — LED control
│   ├── timer.c      — TIM2 1ms tick
│   └── uart.c       — USART2 serial communication
├── Inc/
│   ├── button.h
│   ├── game.h
│   ├── led.h
│   ├── timer.h
│   └── uart.h
├── Startup/
│   └── startup_stm32f446retx.s
├── STM32F446RETX_FLASH.ld
└── .gitignore
```

---

## What I Learned

- GPIO — controlling LED and reading button at register level
- UART — serial communication from scratch
- Timers — generating precise 1ms tick using TIM2
- Interrupts — EXTI, NVIC, ISR handlers
- Bare-metal debugging — baud rate, clock speed, register differences
- Porting code between STM32 families (F303 → F446)

---

## Tools

- STM32CubeIDE
- Docklight (Serial Terminal)
- STM32F446RE Nucleo Board
- Git / GitHub

---

## Author

**SOWJANYANOWDU**  
[GitHub](https://github.com/SOWJANYANOWDU)
