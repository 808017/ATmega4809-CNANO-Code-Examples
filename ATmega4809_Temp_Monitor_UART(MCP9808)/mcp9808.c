#include <xc.h>
#include <stdint.h>

#include "i2c.h"
#include "mcp9808.h"

#define MCP9808_TEMP_REG 0x05

int16_t MCP9808_ReadTemperatureCenti(void)
{
    uint8_t msb;
    uint8_t lsb;
    uint16_t raw;
    int16_t temperature;

    // Select temperature register
    if (!I2C_StartWrite(MCP9808_ADDR))
    {
        I2C_Stop();
        return -32768;
    }

    I2C_WriteByte(MCP9808_TEMP_REG);

    // Read two temperature bytes
    if (!I2C_StartRead(MCP9808_ADDR))
    {
        I2C_Stop();
        return -32768;
    }

    msb = I2C_ReadByte(1);   // ACK first byte
    lsb = I2C_ReadByte(0);   // NACK last byte

    I2C_Stop();

    /*
     * MCP9808 temperature format:
     *
     * MSB:
     * bit 4 = sign
     * bits 3:0 = temperature bits 11:8
     *
     * LSB:
     * bits 7:0 = temperature bits 7:0
     */

    raw = ((uint16_t)(msb & 0x1F) << 8) | lsb;

    // Negative temperature
    if (msb & 0x10)
    {
        raw -= 8192;
    }

    // 1 LSB = 0.0625 °C
    // centi-degrees = raw × 6.25 = raw × 25 / 4
    temperature = (int32_t)raw * 25 / 4;

    return temperature;
}