#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000UL

#include "i2c.h"
#include "oled.h"
#include <util/delay.h>

/* Simple delay */
void Delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 1000; j++)
        {
            _delay_ms(1);
        }
    }
}


/* Print a horizontal line */
void OLED_Line(void)
{
    OLED_WriteString("------------------------");
}


/* Display dashboard */
void OLED_ShowDashboard(void)
{
    OLED_Clear();

    /* Header */
    OLED_SetCursor(0, 0);
    OLED_WriteString("  HEALTH MONITOR");

    OLED_SetCursor(1, 0);
    OLED_WriteString("========================");

    /* Temperature */
    OLED_SetCursor(2, 0);
    OLED_WriteString("TEMP : ");

    OLED_WriteNumber(36);
    OLED_WriteString(".");
    OLED_WriteNumber(7);
    OLED_WriteString(" C");

    /* Heart rate */
    OLED_SetCursor(3, 0);
    OLED_WriteString("HR   : ");

    OLED_WriteNumber(78);
    OLED_WriteString(" BPM");

    /* SpO2 */
    OLED_SetCursor(4, 0);
    OLED_WriteString("SpO2 : ");

    OLED_WriteNumber(98);
    OLED_WriteString(" %");

    /* Battery */
    OLED_SetCursor(5, 0);
    OLED_WriteString("BATT : [");

    OLED_WriteString("||||||||");

    OLED_WriteString("]");

    /* Status */
    OLED_SetCursor(6, 0);
    OLED_WriteString("STATUS: NORMAL");

    OLED_SetCursor(7, 0);
    OLED_WriteString("RIT EMBEDDED CLUB");
}


/* Main program */
void main(void)
{
    I2C_Init();

    OLED_Init();

    while (1)
    {
        OLED_ShowDashboard();

        Delay_ms(1000);
    }
}