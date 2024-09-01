# STM32 Fan Control System

This project implements a fan control system on an STM32 microcontroller, providing two methods of control: potentiometer-based (ADC) and terminal-based (UART). The user can select the desired control method to set the fan speed, offering flexibility and a hands-on approach to learning embedded systems programming and peripheral integration.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Structure](#project-structure)
- [Setup and Usage](#setup-and-usage)
- [Control Methods](#control-methods)

## Overview

The STM32 Fan Control System allows users to control a fan's speed through two methods:
1. **Potentiometer Control (ADC)**: Adjust the fan speed using a potentiometer, reading the values via ADC and converting them into PWM signals for fan control.
2. **Terminal Control (UART)**: Control the fan speed by entering a percentage value through a UART interface like hTerm. The entered value directly sets the fan's PWM duty cycle.

This project demonstrates advanced usage of STM32 peripherals, including ADC, UART, and PWM, providing a robust learning experience for embedded system enthusiasts.

## Features

- **Dual Control Methods**: Choose between potentiometer-based or terminal-based control.
- **Real-Time Control**: Adjust fan speed in real-time using both control methods.
- **User Feedback**: Receive feedback through UART to confirm actions and fan speed settings.
- **Modular Code**: Well-organized code with modular libraries (`uart_read_app.h`, `uart_send_app.h`, `adc_read_app.h`, `conversions.h`) for reusability and easier maintenance.
- **Error Handling**: Robust error handling mechanisms are included to manage out-of-bound readings and system errors.

## Hardware Requirements

- STM32 Microcontroller (e.g., STM32F4 series)
- Fan with PWM control
- Potentiometer
- UART interface (e.g., hTerm, Putty)
- STM32 development board (e.g., Nucleo, Discovery)
- Breadboard and connecting wires

## Software Requirements

- STM32CubeMX for configuration
- STM32CubeIDE or other compatible IDE (e.g., Keil, IAR)
- STM32 HAL Library
- Serial terminal software (e.g., hTerm, Putty)

## Project Structure

- **main.c**: Contains the main logic of the program and peripheral initialization.
- **uart_read_app.h / .c**: Handles reading data from UART.
- **uart_send_app.h / .c**: Handles sending data over UART.
- **adc_read_app.h / .c**: Manages ADC readings from the potentiometer.
- **conversions.h / .c**: Provides utility functions for data conversion (e.g., integer to string).

## Setup and Usage

### Hardware Setup

1. Connect the potentiometer to the ADC pin of the STM32 board.
2. Connect the fan to a PWM-enabled GPIO pin.
3. Set up UART connections for terminal control (TX, RX).
4. Ensure the microcontroller is properly powered and grounded with all components connected.

### Software Setup

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/stm32-fan-control.git
   cd stm32-fan-control
   ```
2. Open the project in STM32CubeIDE.
3. Generate the necessary peripheral initialization code using STM32CubeMX.
4. Compile and upload the code to your STM32 board.
5. Open your preferred serial terminal software (e.g., hTerm) and connect to the correct COM port with a baud rate of 115200.

### Running the Project

1. **Select Control Method**: Upon starting the program, choose the control method:
   - Enter `1` for terminal control.
   - Enter `2` for potentiometer control.
   
2. **Terminal Control**:
   - Enter the desired fan speed as a percentage (0-100%) through the terminal.
   - The program sets the fan speed accordingly and provides feedback.

3. **Potentiometer Control**:
   - Adjust the potentiometer to set the fan speed.
   - The program continuously reads the ADC value and adjusts the fan speed in real-time.

## Control Methods

### 1. Potentiometer Control

- Uses the onboard ADC to read analog values from the potentiometer.
- Converts the ADC value to a PWM signal to control the fan speed.
- Provides feedback through UART if the potentiometer reading is out of bounds.

### 2. Terminal Control

- Accepts speed percentage inputs via UART.
- Converts the input to a PWM signal and adjusts the fan speed accordingly.
- A confirmation message is sent through UART after setting the fan speed.
