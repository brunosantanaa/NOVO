#include "LEDDriverAPI.h"
#include <unistd.h>

int (*driver_exec)(uint8_t);
uint8_t led_state = 0;

void dimmer(uint8_t value) {
    int _rate = RATE * ((value > led_state) ? 1 : -1);
    int brightness = led_state;

    while(brightness != value) {
        driver_exec(brightness);
        usleep(INTERVAL);
        brightness += _rate;
        if((brightness > value && _rate > 0) || (brightness < value && _rate < 0)){
            driver_exec(value);
            break;
        }
    }
    led_state = value;
}

int LEDDriverInit(uint8_t driver) {
    if (driver > 1) return -1;

    driver_exec = (driver == 0)? &I2C_exec : &PWM_exec;
    return 0;
}

int LEDDriverSetValue(uint8_t value) {
    if (value < 0) value = 0;
    if (value > 100) value = 100;

    dimmer(value);
    return 0;
}

