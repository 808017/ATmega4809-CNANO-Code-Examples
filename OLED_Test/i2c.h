#ifndef I2C_H
#define I2C_H

#include <stdint.h>

void I2C_Init(void);
uint8_t I2C_StartWrite(uint8_t address);
uint8_t I2C_StartRead(uint8_t address);
void I2C_WriteByte(uint8_t data);
uint8_t I2C_ReadByte(uint8_t acknowledge);
void I2C_Stop(void);

#endif