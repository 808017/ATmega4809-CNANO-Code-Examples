#include <xc.h>

#define LED_PIN PIN5_bm

int main(void)
{
    // Configure PF5 as output
    PORTF.DIRSET = LED_PIN;

    while (1)
    {
        // LED ON (active LOW)
        PORTF.OUTCLR = LED_PIN;

        // Simple delay
        for (volatile unsigned long i = 0; i < 10000UL; i++);

        // LED OFF
        PORTF.OUTSET = LED_PIN;

        // Simple delay
        for (volatile unsigned long i = 0; i < 10000UL; i++);
    }

    return 0;
}
