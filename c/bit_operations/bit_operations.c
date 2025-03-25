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

