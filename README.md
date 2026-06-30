🚀 S32K144 Low-Level Driver Development (Bare-Metal):
***Overview:
  -This repository contains low-level driver implementations and basic embedded applications developed on S32K144.
  -The project focuses on register-level programming (bare-metal) to understand MCU peripherals and build reusable drivers without relying on SDK or HAL libraries.
  => Goal: Build strong foundation in embedded systems by implementing drivers from scratch.

***Project Structure

/GPIO_Driver        → GPIO driver implementation

/Blink_LED          → LED blinking using GPIO

/Button_Interrupt   → External interrupt handling (button)

/Clock_Assignment2  → Clock configuration experiments

/Clock_Assignment5  → Advanced clock setup

***Key Features
  - Bare-metal programming (direct register access)
  - No SDK / no HAL dependency
  - Modular driver-based design
  - Focus on understanding MCU architecture
  - Multiple test applications for validation

***Implemented Drivers
   - GPIO Driver
    + Pin configuration (input/output)
    + Digital read/write
    + Port initialization
    + Register-level control
  - Interrupt Handling
    + External interrupt configuration
    + NVIC setup
    + ISR (Interrupt Service Routine)
  - Clock Configuration
    + System clock setup
    + Peripheral clock control
    + Clock source switching

**Technical Highlights
 - Direct manipulation of:
   + GPIO registers
   + NVIC (Nested Vector Interrupt Controller)
   + System clock registers
 - Understanding of:
   + MCU memory map
   + Peripheral register structure
   + Interrupt-driven design
