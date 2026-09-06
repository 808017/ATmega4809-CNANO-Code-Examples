#include <xc.h>
#include <stdint.h>
#include "i2c.h"

void I2C_Init(void)
{
    // PA2 = SDA, PA3 = SCL
    PORTA.DIRCLR = PIN2_bm | PIN3_bm;

    // Enable internal pull-ups temporarily for testing
    PORTA.PIN2CTRL = PORT_PULLUPEN_bm;
    PORTA.PIN3CTRL = PORT_PULLUPEN_bm;

    // I2C clock approximately 100 kHz
    TWI0.MBAUD = 12;

    TWI0.MCTRLA = TWI_ENABLE_bm;

    // Force bus to idle
    TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;
}

uint8_t I2C_StartWrite(uint8_t address)
{
    TWI0.MADDR = (address << 1);

    while (!(TWI0.MSTATUS & TWI_WIF_bm))
    {
    }

    if (TWI0.MSTATUS & TWI_RXACK_bm)
    {
        return 0;
    }

    return 1;
}

uint8_t I2C_StartRead(uint8_t address)
{
    TWI0.MADDR = (address << 1) | 1;

    while (!(TWI0.MSTATUS & TWI_RIF_bm))
    {
    }

    if (TWI0.MSTATUS & TWI_RXACK_bm)
    {
        return 0;
    }

    return 1;
}

void I2C_WriteByte(uint8_t data)
{
    TWI0.MDATA = data;

    while (!(TWI0.MSTATUS & TWI_WIF_bm))
    {
    }
}

uint8_t I2C_ReadByte(uint8_t acknowledge)
{
    while (!(TWI0.MSTATUS & TWI_RIF_bm))
    {
    }

    uint8_t data = TWI0.MDATA;

    if (acknowledge)
    {
        TWI0.MCTRLB = TWI_MCMD_RECVTRANS_gc;
    }
    else
    {
        TWI0.MCTRLB = TWI_ACKACT_NACK_gc |
                      TWI_MCMD_RECVTRANS_gc;
    }

    return data;
}

void I2C_Stop(void)
{
    TWI0.MCTRLB = TWI_MCMD_STOP_gc;
}