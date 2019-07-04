/*
    Copyright (c) 2019 Douglas Chidester

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

#include "characters.h"
#include "config.h"

// minimum character array; height * width + height (for newlines) + 1 (null terminator)
#define MIN_ARRAY_SIZE    CFG_CHAR_HEIGHT * CFG_CHAR_WIDTH + CFG_CHAR_HEIGHT + 1

// defines for zero
#define CH_ZERO_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_ZERO_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_ZERO_2    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_ZERO_3    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_ZERO_4    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_ZERO CH_ZERO_0, '\n',\
                     CH_ZERO_1, '\n',\
                     CH_ZERO_2, '\n',\
                     CH_ZERO_3, '\n',\
                     CH_ZERO_4, '\n', '\0'
const char zero[MIN_ARRAY_SIZE] =  { CH_FULL_ZERO };

// defines for one
#define CH_ONE_0    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_ONE_1    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_ONE_2    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_ONE_3    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_ONE_4    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_FULL_ONE CH_ONE_0, '\n',\
                    CH_ONE_1, '\n',\
                    CH_ONE_2, '\n',\
                    CH_ONE_3, '\n',\
                    CH_ONE_4, '\n', '\0'
const char one[MIN_ARRAY_SIZE] =  { CH_FULL_ONE };

// defines for two
#define CH_TWO_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_TWO_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_TWO_2    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_TWO_3    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_TWO_4    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_FULL_TWO CH_TWO_0, '\n',\
                    CH_TWO_1, '\n',\
                    CH_TWO_2, '\n',\
                    CH_TWO_3, '\n',\
                    CH_TWO_4, '\n', '\0'
const char two[MIN_ARRAY_SIZE] =  { CH_FULL_TWO };

// defines for three
#define CH_THREE_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_THREE_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_THREE_2    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_THREE_3    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_THREE_4    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_THREE CH_THREE_0, '\n',\
                      CH_THREE_1, '\n',\
                      CH_THREE_2, '\n',\
                      CH_THREE_3, '\n',\
                      CH_THREE_4, '\n', '\0'
const char three[MIN_ARRAY_SIZE] =  { CH_FULL_THREE };

// defines for four
#define CH_FOUR_0    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FOUR_1    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FOUR_2    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FOUR_3    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_FOUR_4    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_FOUR CH_FOUR_0, '\n',\
                     CH_FOUR_1, '\n',\
                     CH_FOUR_2, '\n',\
                     CH_FOUR_3, '\n',\
                     CH_FOUR_4, '\n', '\0'
const char four[MIN_ARRAY_SIZE] =  { CH_FULL_FOUR };

// defines for five
#define CH_FIVE_0    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_FIVE_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_FIVE_2    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FIVE_3    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_FIVE_4    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_FIVE CH_FIVE_0, '\n',\
                     CH_FIVE_1, '\n',\
                     CH_FIVE_2, '\n',\
                     CH_FIVE_3, '\n',\
                     CH_FIVE_4, '\n', '\0'
const char five[MIN_ARRAY_SIZE] =  { CH_FULL_FIVE };

// defines for six
#define CH_SIX_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_SIX_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_SIX_2    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_SIX_3    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_SIX_4    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_SIX CH_SIX_0, '\n',\
                     CH_SIX_1, '\n',\
                     CH_SIX_2, '\n',\
                     CH_SIX_3, '\n',\
                     CH_SIX_4, '\n', '\0'
const char six[MIN_ARRAY_SIZE] =  { CH_FULL_SIX };

// defines for seven
#define CH_SEVEN_0    CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_SEVEN_1    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_SEVEN_2    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_SEVEN_3    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_SEVEN_4    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_SEVEN CH_SEVEN_0, '\n',\
                     CH_SEVEN_1, '\n',\
                     CH_SEVEN_2, '\n',\
                     CH_SEVEN_3, '\n',\
                     CH_SEVEN_4, '\n', '\0'
const char seven[MIN_ARRAY_SIZE] =  { CH_FULL_SEVEN };

// defines for eight
#define CH_EIGHT_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_EIGHT_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_EIGHT_2    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_EIGHT_3    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_EIGHT_4    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_FULL_EIGHT CH_EIGHT_0, '\n',\
                     CH_EIGHT_1, '\n',\
                     CH_EIGHT_2, '\n',\
                     CH_EIGHT_3, '\n',\
                     CH_EIGHT_4, '\n', '\0'
const char eight[MIN_ARRAY_SIZE] =  { CH_FULL_EIGHT };

// defines for nine
#define CH_NINE_0    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_EMPTY_CHAR
#define CH_NINE_1    CFG_FILLR_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_NINE_2    CFG_EMPTY_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR, CFG_FILLR_CHAR
#define CH_NINE_3    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_NINE_4    CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_EMPTY_CHAR, CFG_FILLR_CHAR
#define CH_FULL_NINE CH_NINE_0, '\n',\
                     CH_NINE_1, '\n',\
                     CH_NINE_2, '\n',\
                     CH_NINE_3, '\n',\
                     CH_NINE_4, '\n', '\0'
const char nine[MIN_ARRAY_SIZE] =  { CH_FULL_NINE };

static void decodeChar(const char c);
static const char* numeric(const char c);
static char* alphabetic(char c);

const char* CHR_getCharacter(const char c)
{
    const char* pStr;
    // if c is 0-9
    //      numeric(c)
    // else if c is A-Za-z
    //      alphabetic(c)
    // else ??
    return numeric(c);
}

const char* CHR_getPartialCharacter(const char c, const int row, char* out, const int len)
{
    int i;
    const char* pStr = numeric(c);
    const char* begin = &pStr[(row * CFG_CHAR_WIDTH)];
    const char* end= &pStr[(row * CFG_CHAR_WIDTH) + CFG_CHAR_WIDTH + 1]; // TODO is +1 actually needed?

    // copy the partial character into the output buffer
    for(i = 0; i < len && begin != end; ++i)
    {
        out[i] = *begin;
        ++begin;
    }

    return pStr;
}

static void decodeChar(const char c)
{

}

static const char* numeric(const char c)
{
    const char* pStr;
    switch(c)
    {
        case '0': pStr = zero; break;
        case '1': pStr = one; break;
        case '2': pStr = two; break;
        case '3': pStr = three; break;
        case '4': pStr = four; break;
        case '5': pStr = five; break;
        case '6': pStr = six; break;
        case '7': pStr = seven; break;
        case '8': pStr = eight; break;
        case '9': pStr = nine; break;
        default:
            //pStr = space;
            break;
    }
    return pStr;
}

