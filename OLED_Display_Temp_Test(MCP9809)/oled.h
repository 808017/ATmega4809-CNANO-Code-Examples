#ifndef OLED_H
#define OLED_H

void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(unsigned char row, unsigned char column);
void OLED_WriteString(const char *text);

#endif