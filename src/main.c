#include <stdio.h>
#include "LEDDriverAPI.h"

int main(int argc, char *argv[])
{
    LEDDriverInit(I2C);
    LEDDriverSetValue(86);

    LEDDriverInit(PWM);
    LEDDriverSetValue(73);

    return 0;
}
