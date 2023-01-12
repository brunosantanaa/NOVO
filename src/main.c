#include <stdio.h>
#include "LEDDriverAPI.h"

int main(int argc, char *argv[])
{
    if(LEDDriverInit(I2C) != 0) {
        printf("Error: driver configuration\n");
        return -1;
    }
    LEDDriverSetValue(57);

    if(LEDDriverInit(PWM) != 0) {
        printf("Error: driver configuration\n");
        return -1;
    }
    LEDDriverSetValue(13);

    return 0;
}
