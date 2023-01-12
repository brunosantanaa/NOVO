#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include <unistd.h>
#include "DriverI2C.h"
#include "DriverPWM.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define I2C         0
#define PWM         1
#define RATE        10
#define INTERVAL    50000 //us

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/
int LEDDriverInit(uint8_t driver);
int LEDDriverSetValue(uint8_t value);

#endif
