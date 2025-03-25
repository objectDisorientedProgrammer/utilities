// TODO add header

#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t bitop_u8_setbit(uint8_t* const value, const uint8_t bit);
uint8_t bitop_u8_clearbit(uint8_t* const value, const uint8_t bit);
uint8_t bitop_u8_getbit(const uint8_t* const value, const uint8_t bit);

#ifdef __cplusplus
}
#endif

#endif

