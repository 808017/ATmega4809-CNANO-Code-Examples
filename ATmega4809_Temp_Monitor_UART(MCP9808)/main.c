#define F_CPU 3333333UL

#include <xc.h>
#include <stdint.h>
#include <util/delay.h>

#include "uart.h"
#include "i2c.h"
#include "mcp9808.h"

int main(void)
{
    uint16_t temperature;
    uint16_t whole;
    uint16_t decimal;


    PORTF.DIRSET = PIN5_bm;

    UART_Init();
    I2C_Init();

    UART_SendString("\r\nMCP9808 Temperature Monitor\r\n");
    UART_SendString("I2C Address: 0x1C\r\n");
    UART_SendString("----------------------------\r\n");

    while (1)
    {
        temperature = MCP9808_ReadTemperatureCenti();

        if (temperature == -32768)
{
    UART_SendString("MCP9808 not detected\r\n");
}
else
{
    whole = temperature / 100;
    decimal = temperature % 100;

    UART_SendString("Temperature: ");
    UART_SendNumber(whole);
    UART_SendChar('.');

    if (decimal < 10 && decimal >= 0)
    {
        UART_SendChar('0');
    }

    UART_SendNumber(decimal);
    UART_SendString(" C\r\n");
}
}
}