#include <xc.h>
#include <stdint.h>

#include "i2c.h"
#include "mcp9808.h"

#define MCP9808_ADDR       0x1C
#define MCP9808_TEMP_REG   0x05


void MCP9808_Init(void)
{
    /*
       MCP9808 does not require a special initialization
       for normal temperature measurement.
    */
}


/*
   Read temperature in 0.1 °C units.

   Example:
   36.7 °C returns 367
   25.0 °C returns 250
*/
int16_t MCP9808_ReadTemperature10(void)
{
    uint8_t msb;
    uint8_t lsb;
    uint16_t raw;
    int16_t temperature10;

    /*
       Write temperature register address
    */
    if (!I2C_StartWrite(MCP9808_ADDR))
    {
        I2C_Stop();
        return 0;
    }

    I2C_WriteByte(MCP9808_TEMP_REG);
    I2C_Stop();

    /*
       Read two temperature bytes
    */
    if (!I2C_StartRead(MCP9808_ADDR))
    {
        I2C_Stop();
        return 0;
    }

    msb = I2C_ReadByte(1);
    lsb = I2C_ReadByte(0);

    I2C_Stop();

    raw = ((uint16_t)msb << 8) | lsb;

    /*
       Check negative temperature
    */
    if (raw & 0x1000)
    {
        raw &= 0x0FFF;

        /*
           Convert to 0.1 °C
           MCP9808 resolution = 0.0625 °C
        */
        temperature10 = -((int16_t)((raw * 10) / 16));
    }
    else
    {
        raw &= 0x0FFF;

        temperature10 = (int16_t)((raw * 10) / 16);
    }

    return temperature10;
}