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

// defines for one

// defines for two

// defines for three

// defines for four

// defines for five

// defines for six

// defines for seven

// defines for eight

// defines for nine

const char zero[MIN_ARRAY_SIZE] =  { CH_FULL_ZERO };

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

static const char* numeric(const char c)
{
    const char* pStr;
    switch(c)
    {
        case '0':
            pStr = zero;
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        default:
            break;
    }
    return pStr;
}

