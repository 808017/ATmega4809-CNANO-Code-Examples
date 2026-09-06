#include <xc.h>
#include <stdint.h>

#include "i2c.h"
#include "mcp9808.h"

#define MCP9808_TEMP_REG  0x05
#define MCP9808_ERROR     (-32768)

int16_t MCP9808_ReadTemperatureCenti(void)
{
    uint8_t msb;
    uint8_t lsb;
    int16_t raw;
    int32_t temperature_centi;

    /* Select the temperature register */
    if (!I2C_StartWrite(MCP9808_ADDR))
    {
        I2C_Stop();
        return MCP9808_ERROR;
    }

    I2C_WriteByte(MCP9808_TEMP_REG);

    /* Restart I2C and read the temperature register */
    if (!I2C_StartRead(MCP9808_ADDR))
    {
        I2C_Stop();
        return MCP9808_ERROR;
    }

    msb = I2C_ReadByte(1);   /* ACK after first byte */
    lsb = I2C_ReadByte(0);   /* NACK after last byte */

    I2C_Stop();

    /*
     * MCP9808 temperature format:
     *
     * MSB:
     * bit 4     = sign
     * bits 3:0  = temperature bits 11:8
     *
     * LSB:
     * bits 7:0  = temperature bits 7:0
     */

    raw = (int16_t)(((uint16_t)(msb & 0x1F) << 8) | lsb);

    /* Convert 13-bit two's-complement temperature */
    if (raw & 0x1000)
    {
        raw -= 8192;
    }

    /*
     * MCP9808 resolution = 0.0625 °C
     *
     * Centi-degrees:
     * raw × 0.0625 × 100
     * raw × 6.25
     * raw × 25 / 4
     */

    temperature_centi = ((int32_t)raw * 25) / 4;

    return (int16_t)temperature_centi;
}