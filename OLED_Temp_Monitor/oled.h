#ifndef OLED_H
#define OLED_H

#include <stdint.h>

void OLED_Init(void);
void OLED_Clear(void);

void OLED_SetCursor(uint8_t page, uint8_t column);

void OLED_WriteChar(char c);
void OLED_WriteString(const char *text);
void OLED_WriteNumber(int16_t number);

#endif