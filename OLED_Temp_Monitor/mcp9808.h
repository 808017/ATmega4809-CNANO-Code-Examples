#ifndef MCP9808_H
#define MCP9808_H

#include <stdint.h>

void MCP9808_Init(void);
int16_t MCP9808_ReadTemperature10(void);

#endif