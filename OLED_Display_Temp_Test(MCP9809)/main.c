#define F_CPU 16000000UL

#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

#include "i2c.h"
#include "oled.h"
#include "mcp9808.h"

int main(void)
{
    char display_text[20];
    int16_t temperature;

    I2C_Init();
    OLED_Init();

    OLED_Clear();
    OLED_SetCursor(0, 0);
    OLED_WriteString("Temperature");

    while (1)
    {
        temperature = MCP9808_ReadTemperatureCenti();

        sprintf(display_text, "%d.%02d C",
                temperature / 100,
                temperature % 100);

        OLED_SetCursor(0, 1);
        OLED_WriteString("                ");

        OLED_SetCursor(0, 1);
        OLED_WriteString(display_text);

        _delay_ms(100);
    }
}