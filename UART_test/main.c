#define F_CPU 3333333UL

#include <xc.h>
#include <util/delay.h>

void UART_Init(void)
{
    // PB0 = USART3 TX
    // PB1 = USART3 RX
    PORTB.DIRSET = PIN0_bm;
    PORTB.DIRCLR = PIN1_bm;

    USART3.BAUD = 1389;   // 9600 baud at 3.333 MHz

    USART3.CTRLC = USART_CMODE_ASYNCHRONOUS_gc |
                   USART_PMODE_DISABLED_gc |
                   USART_CHSIZE_8BIT_gc;

    USART3.CTRLB = USART_TXEN_bm | USART_RXEN_bm;
}

void UART_SendChar(char c)
{
    while (!(USART3.STATUS & USART_DREIF_bm))
    {
    }

    USART3.TXDATAL = c;
}

void UART_SendString(const char *text)
{
    while (*text)
    {
        UART_SendChar(*text++);
    }
}

int main(void)
{
    // Onboard LED
    PORTF.DIRSET = PIN5_bm;

    UART_Init();

    while (1)
    {
        UART_SendString("Hello World!\r\n");

        PORTF.OUTTGL = PIN5_bm;
        _delay_ms(1000);
    }
}