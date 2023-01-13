#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#include <stdio.h>
#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define ADDRESS 0x0f
#define I2C_SIZE 255

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/
int I2C_exec(uint8_t value_per);
int I2C_ic(uint8_t addr, uint8_t value);

#endif
