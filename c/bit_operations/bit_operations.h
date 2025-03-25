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

#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set a bit in an unsigned eight bit value. Bits are indexed 1 through 8.
 * @param value Pointer to the value.
 * @param bit 1-indexed bit position.
 * @return 1 if the bit is set; otherwise 0.
 */
uint8_t bitop_u8_setbit(uint8_t* const value, const uint8_t bit);

/**
 * Clear a bit in an unsigned eight bit value. Bits are indexed 1 through 8.
 * @param value Pointer to the value.
 * @param bit 1-indexed bit position.
 * @return 1 if the bit is cleared; otherwise 0.
 */
uint8_t bitop_u8_clearbit(uint8_t* const value, const uint8_t bit);

/**
 * Get a bit from an unsigned eight bit value. Bits are indexed 1 through 8.
 * @param value Pointer to the value.
 * @param bit 1-indexed bit position.
 * @return 1 if the bit it set; 0 if the bit is not set; 0xFF for any error.
 */
uint8_t bitop_u8_getbit(const uint8_t* const value, const uint8_t bit);

#ifdef __cplusplus
}
#endif

#endif

