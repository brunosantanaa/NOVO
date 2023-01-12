#include "DriverPWM.h"

int PWM_exec(uint8_t value) {
    int resp = PWM_OUT(FREQUENCY_10kHz, value);
    return resp;
}

int PWM_OUT(uint32_t freq, uint8_t duty) {
    printf("PWM:%d:%d\n", freq, duty);
    return 0;
}
