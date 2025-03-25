/*
   Copyright 2025 objectDisorientedProgrammer

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "bit_operations.h"
#include <assert.h>
#include <stdint.h>

void run_u8_tests(void);

int main(int argc, char const *argv[])
{
    run_u8_tests();

    return 0;
}

void run_u8_tests(void)
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
}
