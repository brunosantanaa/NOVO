#include "DriverI2C.h"

int I2C_exec(uint8_t value_per) {
    uint16_t value = (uint16_t)(I2C_SIZE * (value_per / 100.0));
    
    int resp = I2C_ic(ADDRESS, value);

    return resp;
}

int I2C_ic(uint8_t addr, uint16_t value) {
    printf("I2C:%d:%d\n", addr, value);
    return 0;
}
