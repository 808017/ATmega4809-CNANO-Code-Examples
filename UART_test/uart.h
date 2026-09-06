#ifndef UART_H
#define UART_H

#include <stdint.h>

void UART_Init(void);
void UART_SendChar(char data);
void UART_SendString(const char *text);
void UART_SendUInt16(uint16_t value);
void UART_SendTemperature(int16_t temperature_x100);

#endif