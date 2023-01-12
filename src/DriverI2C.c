#include "DriverI2C.h"
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

int I2C_ic(uint8_t addr, uint16_t value) {
    printf("I2C:%d:%d\n", addr, value);
    return 0;
}
