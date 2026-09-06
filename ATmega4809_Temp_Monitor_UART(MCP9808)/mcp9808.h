#ifndef MCP9808_H
#define MCP9808_H

#include <stdint.h>

#define MCP9808_ADDR 0x1C

int16_t MCP9808_ReadTemperatureCenti(void);

#endif