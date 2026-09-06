#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000UL

#include "i2c.h"
#include "oled.h"
#include "mcp9808.h"
#include <util/delay.h>


void Delay_ms(unsigned int ms)
{
    while (ms--)
    {
        _delay_ms(1);
    }
}


/* Draw the fixed dashboard only once */
void OLED_ShowStaticDashboard(void)
{
    OLED_Clear();

    OLED_SetCursor(0, 0);
    OLED_WriteString("    HEALTH MONITOR");

    OLED_SetCursor(1, 0);
    OLED_WriteString("========================");

    OLED_SetCursor(2, 0);
    OLED_WriteString("MCP9808 TEMP:");

    OLED_SetCursor(5, 0);
    OLED_WriteString("SENSOR: MCP9808");

    OLED_SetCursor(6, 0);
    OLED_WriteString("STATUS: NORMAL");

    OLED_SetCursor(7, 0);
    OLED_WriteString("RIT EMBEDDED CLUB");
}


/* Update only the temperature area */
void OLED_UpdateTemperature(int16_t temperature10)
{
    int16_t integer_part;
    int16_t decimal_part;

    integer_part = temperature10 / 10;
    decimal_part = temperature10 % 10;

    if (decimal_part < 0)
        decimal_part = -decimal_part;

    /*
       Clear only the old temperature characters.
       5 characters are enough for values such as -40.0.
    */
    OLED_SetCursor(3, 0);
    OLED_WriteString("       ");

    OLED_SetCursor(3, 0);
    OLED_WriteNumber(integer_part);
    OLED_WriteString(".");
    OLED_WriteNumber(decimal_part);
    OLED_WriteString(" C");
}


void main(void)
{
    int16_t temperature10;

    I2C_Init();

    OLED_Init();

    MCP9808_Init();

    /* Draw fixed text one time */
    OLED_ShowStaticDashboard();

    while (1)
    {
        temperature10 = MCP9808_ReadTemperature10();

        /* Update only temperature */
        OLED_UpdateTemperature(temperature10);

        /*
           MCP9808 temperature does not need to be
           read every millisecond.
        */
        Delay_ms(500);
    }
}