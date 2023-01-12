#ifndef DRIVER_PWM_H
#define DRIVER_PWM_H

#include <stdint.h>
#include <stdio.h>

#define FREQUENCY_10kHz 10000

int PWM_exec(uint8_t value);
int PWM_OUT(uint32_t freq, uint8_t duty);

#endif
