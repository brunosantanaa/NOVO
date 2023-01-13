#include "DriverI2C.h"

extern I2C_HandleTypeDef hi2c1;
/****************************************************************************
 * Public Functions
 ****************************************************************************/
/****************************************************************************
* Name: I2C_exec
* 
* Description:
*   Convert value and execute call to I2C_ic function.
* Input:
*   type uint8_t, value 0..100
*
* Output:
*   Negative for error.
*
* ***************************************************************************/
int I2C_exec(uint8_t value_per) {
    uint16_t value = (uint16_t)(I2C_SIZE * (value_per / 100.0));
    
    int resp = I2C_ic(ADDRESS, value);

    return resp;
}
/****************************************************************************
* Name: I2C_ic
* 
* Description:
*   Execute a representation of the board.
* Input:
*   uint8_t addr -> I2C Address
*   uint16_t value -> 0..1024
*
* Output:
*
*
* ***************************************************************************/

int I2C_ic(uint8_t addr, uint8_t value) {
    printf("I2C:%d:%d\n", addr, value);

    HAL_I2C_Master_Transmit(&hi2c1, addr, &value, sizeof(value), 50);

    return 0;
}
