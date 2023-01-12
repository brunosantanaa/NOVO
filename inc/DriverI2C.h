#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdio.h>
#include <stdint.h>

#define ADDRESS 0x0f
#define I2C_SIZE 1024

int I2C_exec(uint8_t value_per);
int I2C_ic(uint8_t addr, uint16_t value);

#endif
