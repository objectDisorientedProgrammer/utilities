#include "bit_operations.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

void runTest_setbit(uint8_t* const val, const uint8_t bit, const uint8_t expected)
{
    //if (val != NULL)
        uint8_t orig_val = *val; // assume val is not NULL...
    if (bitop_u8_setbit(val, bit))
    {
        printf("Setting bit %d of value %d -> %d\n", bit, orig_val, *val);
        assert(*val == expected);
    }
    else
    {
        printf("Failed to set bit %d\n", bit);
    }
}

int main(int argc, char const *argv[])
{
    uint8_t val = 0;
    uint8_t bit = 1;

    assert(bitop_u8_setbit(&val, bit) == 1);
    assert(val == 1);
    
    bit = 3;
    assert(bitop_u8_setbit(&val, bit) == 1);
    assert(val == 5);
    
    bit = 9; // expected to return 0; out of range
    assert(bitop_u8_setbit(&val, bit) == 0);
    assert(val == 5);

    bit = 0; // expected to return 0; out of range
    assert(bitop_u8_setbit(&val, bit) == 0);
    assert(val == 5);
    
    bit = 8;
    assert(bitop_u8_setbit(&val, bit) == 1);
    assert(val == 133);

    // expected to return 0; NULL value
    assert(bitop_u8_setbit(NULL, 3) == 0);
    assert(val == 133);

    bit = 1;
    assert(bitop_u8_clearbit(&val, bit) == 1);
    assert(val == 132);

    // test out of range bits fpr clear bit
    bit = 0;
    assert(bitop_u8_clearbit(&val, bit) == 0);
    assert(val == 132);
    bit = 9;
    assert(bitop_u8_clearbit(&val, bit) == 0);
    assert(val == 132);
    // test NULL for clear bit
    bit = 6;
    assert(bitop_u8_clearbit(NULL, bit) == 0);
    assert(val == 132);

    // test already cleared bit
    bit = 1;
    assert(bitop_u8_clearbit(&val, bit) == 1);
    assert(val == 132);

    assert(bitop_u8_getbit(&val, bit) == 0);
    assert(val == 132);

    bit = 3;
    assert(bitop_u8_getbit(&val, bit) == 1);
    assert(val == 132);

    bit = 0; // expected to return error; out of range
    assert(bitop_u8_getbit(&val, bit) == 0xFF);
    assert(val == 132);
    bit = 9; // expected to return error; out of range
    assert(bitop_u8_getbit(&val, bit) == 0xFF);
    assert(val == 132);

    bit = 8;
    assert(bitop_u8_clearbit(&val, bit) == 1);
    assert(val == 4);

    bit = 8;
    assert(bitop_u8_getbit(&val, bit) == 0);
    assert(val == 4);
    // test NULL value for get bit
    assert(bitop_u8_getbit(NULL, bit) == 0xFF);
    assert(val == 4);

    return 0;
}