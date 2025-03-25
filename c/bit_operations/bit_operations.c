#include "bit_operations.h"
#include <stdlib.h>

uint8_t bitop_u8_setbit(uint8_t* const value, const uint8_t bit)
{
    uint8_t status = 0;
    if (value != NULL && 0 < bit && bit <= 8)
    {
        *value |= 1 << (bit - 1);
        status = 1;
    }
    return status;
}

uint8_t bitop_u8_clearbit(uint8_t* const value, const uint8_t bit)
{
    uint8_t status = 0;
    if (value != NULL && 0 < bit && bit <= 8)
    {
        *value &= ~(1 << (bit - 1));
        status = 1;
    }
    return status;
}

uint8_t bitop_u8_getbit(const uint8_t* const value, const uint8_t bit)
{
    uint8_t ret = 0xFF;
    if (value != NULL && 0 < bit && bit <= 8)
    {
        ret = (*value & (1 << (bit - 1))) >> (bit - 1);
    }
    return ret;
}

