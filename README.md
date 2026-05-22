# ⚡ Reflex Game — STM32 Reaction Timer

A **reaction timer game** developed on the **STM32 Nucleo-F446RE** board using **register-level programming** in Embedded C.

This project measures **human reaction time in milliseconds** using the onboard LED, push button, UART communication, hardware timer, and interrupt system of the STM32 microcontroller.

Unlike beginner STM32 projects that rely on HAL libraries or CubeMX-generated peripheral configuration, this implementation uses **direct register programming**, providing a deeper understanding of embedded systems and microcontroller architecture.

> No HAL. No RTOS. No middleware.  
> Just registers, interrupts, timers, and embedded logic.

---

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

1. Open a serial terminal (**Docklight / PuTTY**) at **115200 baud**
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
Wait...
Wait...

GO!

Reaction Time: 213 ms
Excellent Reflexes!

Press ENTER to play again
