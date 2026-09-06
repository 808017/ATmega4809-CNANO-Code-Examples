#include <xc.h>
#include <stdint.h>
#include <util/delay.h>

#define F_CPU 3333333UL
#define UART_BAUD 9600UL

void UART_Init(void)
{
    /*
     * Development-board schematic:
     * PB1 = USART3 TX
     * PB0 = USART3 RX
     */

    PORTB.DIRSET = PIN1_bm;
    PORTB.DIRCLR = PIN0_bm;

    USART3.BAUD = (uint16_t)((64UL * F_CPU) /
                             (16UL * UART_BAUD));

    USART3.CTRLC = USART_CHSIZE_8BIT_gc |
                   USART_PMODE_DISABLED_gc;

    USART3.CTRLB = USART_TXEN_bm |
                   USART_RXEN_bm;
}

void UART_SendChar(char data)
{
    while (!(USART3.STATUS & USART_DREIF_bm))
    {
    }

    USART3.TXDATAL = data;
}

void UART_SendString(const char *text)
{
    while (*text != '\0')
    {
        UART_SendChar(*text);
        text++;
    }
}

int main(void)
{
    UART_Init();

    while (1)
    {
        UART_SendString("UART3 working\r\n");
        _delay_ms(1000);
    }
}