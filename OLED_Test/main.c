#define F_CPU 3333333UL

#include <xc.h>
#include <util/delay.h>

#include "i2c.h"
#include "oled.h"

int main(void)
{
    PORTF.DIRSET = PIN5_bm;

    I2C_Init();
    OLED_Init();

    OLED_SetCursor(0, 0);
    OLED_WriteString("HELLO WORLD");

    OLED_SetCursor(2, 0);
    OLED_WriteString("ATMEGA4809 YASH");

    OLED_SetCursor(4, 0);
    OLED_WriteString("OLED TEST");

    while (1)
    {
        PORTF.OUTTGL = PIN5_bm;
        _delay_ms(1000);
    }
}