#define F_CPU 3333333UL

#include <xc.h>
#include <stdint.h>
#include "uart.h"

void UART_Init(void)
{
    // Curiosity Nano:
    // PB0 = USART3 TX
    // PB1 = USART3 RX

    PORTB.DIRSET = PIN0_bm;
    PORTB.DIRCLR = PIN1_bm;

    // 9600 baud at 3.333 MHz
    USART3.BAUD = 1389;

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

void UART_SendNumber(int16_t number)
{
    char buffer[8];
    uint8_t i = 0;

    if (number == 0)
    {
        UART_SendChar('0');
        return;
    }

    if (number < 0)
    {
        UART_SendChar('-');
        number = -number;
    }

    while (number > 0)
    {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    }

    while (i > 0)
    {
        UART_SendChar(buffer[--i]);
    }
}