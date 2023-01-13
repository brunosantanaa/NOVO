#include "DriverPWM.h"

extern TIM_HandleTypeDef htim4;

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
* Name: PWM_exec
* 
* Description:
*   Execute call to I2C_ic function and set the PWM frequency.
* Input:
*   type uint8_t, value 0..100
*
* Output:
*   Negative for error.
*
* ***************************************************************************/
int PWM_exec(uint8_t value) {
    int resp = PWM_OUT(FREQUENCY_10kHz, value);
    return resp;
}
/****************************************************************************
* Name: PWM_OUT
* 
* Description:
*   Execute a representation of the board.
* Input:
*   uint32_t freq -> PWM Frequency
*   uint16_t duty -> Duty cycle
*
* Output:
*
*
* ***************************************************************************/
int PWM_OUT(uint32_t freq, uint8_t duty) {
    printf("PWM:%ld:%d\n", freq, duty);

    int value = (int) PRESCALE_COUNTER * (duty / 100.0);

    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, value);
    return 0;
}

