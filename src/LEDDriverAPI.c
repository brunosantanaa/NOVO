#include "LEDDriverAPI.h"
#include <stdint.h>
#include <unistd.h>

int (*driver_exec)(uint8_t);
uint8_t led_state = 0;

/****************************************************************************
 * Private Functions Prototypes
 ****************************************************************************/
void dimmer(uint8_t value);

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
* Name: LEDDriverInit
* 
* Description:
*   Initializes the API with the chosen driver
* Input:
*   type uint8_t, value [I2C | PWM], [0 | 1]
*
* Output:
*   Negative for error.
*
* ***************************************************************************/
int LEDDriverInit(uint8_t driver) {
    if (driver > 1) return -1;

    driver_exec = (driver == 0)? &I2C_exec : &PWM_exec;
    return 0;
}
/****************************************************************************
* Name: LEDDriverSetValue
* 
* Description:
*   Set the desired percentage for LED control.
* Input:
*   type uint8_t, value 0..100
*
* Output:
*   
*
* ***************************************************************************/
int LEDDriverSetValue(uint8_t value) {
    printf("val %d\n",value);
    if (value > 100) value = 100;

    dimmer(value);
    return 0;
}

/****************************************************************************
 * Private Functions
 ****************************************************************************/
/****************************************************************************
* Name: dimmer
* 
* Description:
*   LED brightness ramp control. (Obs.: It could be performed using multi-task)
* Input:
*   Percentage desired.
*
* ***************************************************************************/
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
