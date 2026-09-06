# ATmega4809 Embedded Systems Projects

This repository contains embedded-system projects developed using the
**ATmega4809 Curiosity Nano** board.

The projects cover basic microcontroller programming, GPIO control,
push-button interfacing, UART communication, temperature sensing, and
OLED display interfacing using the MCP9808 temperature sensor.

## Repository Contents

### 1. ATmega4809 LED Blink

Basic LED blinking project using the ATmega4809 microcontroller.

**Concepts covered:**
- GPIO configuration
- Digital output
- Delay generation
- LED control

### 2. ATmega4809 Push Button

Push-button interfacing project using the ATmega4809.

**Concepts covered:**
- Digital input
- Push-button interfacing
- Pull-up or pull-down configuration
- LED or output control based on button input

### 3. ATmega4809 Temperature Monitor UART (MCP9808)

Temperature-monitoring project using the MCP9808 digital temperature sensor.

The ATmega4809 communicates with the MCP9808 through I2C and sends the
measured temperature through UART.

**Concepts covered:**
- I2C communication
- MCP9808 temperature sensor
- Temperature register reading
- UART communication
- Serial monitoring

### 4. OLED Display Temperature Test (MCP9809)

OLED temperature-display test project using a temperature sensor and an
I2C OLED display.

**Concepts covered:**
- I2C communication
- OLED initialization
- Temperature data display
- Text formatting
- Sensor interfacing

### 5. OLED Temperature Monitor

Temperature-monitoring project using the ATmega4809, MCP9808 sensor, and
128×64 OLED display.

The measured temperature is displayed on the OLED using a dashboard-style
interface.

**Concepts covered:**
- MCP9808 temperature measurement
- OLED display control
- I2C communication
- Real-time data updating
- Embedded display interface

### 6. OLED Test

Basic OLED display test project.

**Concepts covered:**
- OLED initialization
- Display clearing
- Cursor positioning
- Character display
- String display

### 7. OLED Test 2

Additional OLED testing project for experimenting with display output,
text positioning, and display formatting.

**Concepts covered:**
- OLED text rendering
- Display layout
- Cursor control
- String formatting

### 8. UART Test

Basic UART communication test using the ATmega4809.

**Concepts covered:**
- UART initialization
- Serial data transmission
- Serial data reception
- Baud-rate configuration
- Serial terminal testing

### 9. ATmega4809 Curiosity Nano Getting Started with FreeRTOS

Getting-started project for exploring FreeRTOS on the
ATmega4809 Curiosity Nano board.

**Concepts covered:**
- FreeRTOS basics
- Task creation
- Task scheduling
- Delays and timing
- Embedded real-time programming

## Hardware Used

- ATmega4809 Curiosity Nano
- MCP9808 temperature sensor
- 128×64 I2C OLED display
- Push button
- LED
- USB connection for programming and debugging

## Communication Interfaces

The projects use the following communication interfaces:

| Interface | Application |
|---|---|
| GPIO | LED and push-button control |
| I2C | MCP9808 and OLED communication |
| UART | Serial data transmission and monitoring |

## Repository Structure

```text
ATmega4809-Embedded-Projects/
│
├── ATmega4809_LED_Blink.X/
├── ATmega4809_Push_Button.X/
├── ATmega4809_Temp_Monitor_UART(MCP9808)/
├── OLED_Display_Temp_Test(MCP9809)/
├── OLED_Temp_Monitor/
├── OLED_Test/
├── OLED_Test_2/
├── UART_test/
├── atmega4809-cnano-getting-started-with-freertos/
│
├── .gitattributes
├── .gitignore
├── LICENSE
└── README.md
