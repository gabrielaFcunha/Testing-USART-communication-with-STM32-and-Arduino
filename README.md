# USART Communication Between STM32 and Arduino

Documentation of a test developed to learn and practice serial communication protocols.

This project demonstrates USART communication between an STM32 Nucleo board and an Arduino. In this test, the STM32 periodically sends a message to the Arduino and can also receive messages from it.

## Hardware Requirements

- One STM32 board
  - STM32F767ZI Nucleo board was used in this project.
- One Arduino board, or another board with UART/USART peripherals.
- Jumper wires for connecting the boards.
- Resistors for voltage-level adaptation.

> **Important:** The STM32 operates at 3.3 V logic levels, while many Arduino boards operate at 5 V logic levels. Appropriate voltage-level adaptation is required to avoid damaging the STM32.

## Software

- STM32CubeIDE
- Arduino IDE

## Configuration
The communication parameters used in this test are:

- Peripheral --> USART6
- Baud rate --> 115200
- Word length --> 8 bits

### STM32

STM32CubeIDE was used to configure the STM32 peripherals and develop its firmware.

The USART peripheral must be enabled and configured according to the desired communication parameters, such as:

- Baud rate
- Word length
- Stop bits
- Parity
- Transmission mode

After configuring the peripheral, the STM32 firmware can be built and uploaded to the board.

### Arduino

The Arduino firmware was developed using the Arduino IDE.

The serial interface must be configured using the same communication parameters used by the STM32, especially the baud rate.

## Connection

The boards must be connected according to the USART/UART communication scheme:

| STM32 | Arduino |
|-------|---------|
| TX    | RX      |
| RX    | TX      |
| GND   | GND     |

TX and RX must be crossed because the transmitter of one board must be connected to the receiver of the other.

> Make sure that the logic levels of both boards are compatible before connecting their UART/USART pins.

## Communication
The STM32 periodically transmits the message:
"Recebido, Arduino!"

The STM32 can also receive data from the Arduino (it uses polling to receive the data). 
Each received byte is checked and stored in a buffer until \n indicates the end of the message.
When the complete message is received, the STM32 sends it back through USART.

- The main communication functions used in the project are:
 - HAL_UART_Transmit() for transmitting data.
 - HAL_UART_Receive() for receiving data.

## Testing

1. Build the STM32 project in STM32CubeIDE.
2. Upload the firmware to the STM32 board.
3. Build and upload the Arduino firmware using Arduino IDE.
4. Build the physical circuit. 
5. Open the Arduino Serial Monitor. It should display its own message and the message received.
6. Set the Serial Monitor to the same baud rate configured in the firmware.
7. Check whether the messages sent by the STM32 are correctly received by the Arduino.

## What I Learned

This test was developed to understand the basic operation of serial communication between two different microcontroller platforms.

The main concepts explored were:

- C programming for embedded systems
- basic electronic circuits
- USART/UART communication
- Baud rate configuration
- TX and RX signals
- Serial data transmission and reception
- Peripheral configuration using STM32CubeIDE
- Communication between different microcontroller platforms

## Possible Improvements

- Improve the timing of message transmission.
- Add commands that can be sent from the Arduino to the STM32.
- Implement error handling.
- Experiment with different baud rates.
- Use interrupts instead of polling for data reception.
- Implement DMA for data transmission and reception.