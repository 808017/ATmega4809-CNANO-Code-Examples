#include <xc.h>

#define LED_PIN     PIN5_bm
#define BUTTON_PIN  PIN6_bm

int main(void)
{
    // PF5 = LED output
    PORTF.DIRSET = LED_PIN;

    // PF6 = Button input
    PORTF.DIRCLR = BUTTON_PIN;

    // Enable internal pull-up on PF6
    PORTF.PIN6CTRL = PORT_PULLUPEN_bm;

    // LED initially OFF
    PORTF.OUTSET = LED_PIN;

    while (1)
    {
        // Button pressed = PF6 LOW
        if ((PORTF.IN & BUTTON_PIN) == 0)
        {
            // LED ON
            PORTF.OUTSET = LED_PIN;
        }
        else
        {
            // LED OFF
            PORTF.OUTCLR = LED_PIN;
        }
    }

    return 0;
}