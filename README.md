#  Reflex Game — STM32 Reaction Timer

A **reaction timer game** developed on the **STM32 Nucleo-F446RE** board using **register-level programming** in Embedded C.

## Why I Built This

I wanted to build something interactive using only the STM32 board without extra hardware. Instead of doing another LED blinking project, I tried creating a simple reaction timer game to practice timers, UART, and interrupts using register-level programming.

This project measures **human reaction time in milliseconds** using the onboard LED, push button, UART communication, hardware timer, and interrupt system of the STM32 microcontroller.

This project uses **direct register-level programming** instead of HAL libraries to better understand how STM32 peripherals work internally.

#  Objective

The main objective of this project is to build an **interactive reaction timer game** while learning core embedded system concepts such as:

- Register-level peripheral programming
- GPIO configuration
- UART serial communication
- Hardware timers
- Interrupt handling (EXTI + NVIC)
- Real-time event measurement
- Modular embedded software structure

This project transforms a simple STM32 development board into a **playable reaction speed tester**.

---

#  How the Game Works

The STM32 board interacts with the user through a **serial terminal** and the onboard hardware.

### Step-by-step flow

1. Open a serial terminal (**Docklight**) at **115200 baud**
2. User presses **ENTER** to begin a game round
3. STM32 waits for a random duration
4. LED suddenly turns ON and `"GO!"` appears
5. User presses the onboard button as quickly as possible
6. STM32 calculates reaction time
7. Time is displayed on serial terminal

---

## Example Gameplay

```text
===================================
STM32 REFLEX GAME
===================================

Press ENTER to Start

Get Ready...
GO!

Reaction Time: 213 ms
Excellent!

Get Ready...
```
---

#  Hardware Used

| Component | Description |
|------------|-------------|
| Board | STM32 Nucleo-F446RE |
| LED | Onboard LED  |
| Button | User Button  |
| UART | USART2  |
| Terminal | Docklight |

---

#  Project Structure

```text
Reflex_Game_STM32/
├── Src/
│   ├── main.c
│   ├── game.c
│   ├── led.c
│   ├── uart.c
│   ├── timer.c
│   └── button.c
│
├── Inc/
│   ├── game.h
│   ├── led.h
│   ├── uart.h
│   ├── timer.h
│   └── button.h
│
└── README.md
```

---

#  Software Architecture

The project is organized into separate modules to keep the code clean, reusable, and easy to understand.

```text
                +----------------+
                |    main.c      |
                | System Startup |
                +--------+-------+
                         |
                         v
                +----------------+
                |    game.c      |
                |   Game Logic   |
                +--------+-------+
                         |
      ----------------------------------------
      |              |            |          |
      v              v            v          v
  +--------+    +--------+   +--------+  +---------+
  | led.c  |    |uart.c |   |timer.c |  |button.c |
  | LED    |    | UART  |   | Timer  |  | Button  |
  +--------+    +--------+   +--------+  +---------+
```

## Module Description

### `main.c`
Acts as the entry point of the program.

Responsibilities:
- Initialize peripherals
- Start the game
- Keep the system running

---

### `game.c`
Contains the main reaction timer game logic.

Responsibilities:
- Start game
- Wait for random delay
- Turn ON LED
- Measure reaction time
- Display result

---

### `led.c`
Controls the onboard LED.

Functions:
```c
LED_Init();
LED_On();
LED_Off();
```

---

### `uart.c`
Handles serial communication with the PC terminal.

Functions:
```c
UART2_Init();
UART_SendString();
UART_SendNumber();
```

Used for displaying:

```text
Get Ready...
GO!
Reaction Time: 213 ms
```

---

### `timer.c`
Handles timing operations.

Responsibilities:
- Generate 1 ms timer tick
- Create delays
- Measure reaction time

---

### `button.c`
Handles onboard button input using interrupts.

Responsibilities:
- Detect button press
- Trigger reaction event

---
Just One Board. Endless learning.  
No need to wait for a full embedded setup to build something.

