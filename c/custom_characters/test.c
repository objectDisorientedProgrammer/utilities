/*
    Copyright (c) 2019 objectDisorientedProgrammer

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
#include <stdio.h>

int main(int argc, char *argv[])
{
    char buf[1024];

    for (char i = '0'; i <= '9'; ++i)
    {
        printf("%s\n", CHR_getCharacter(i));
    }

    #define BIG_STR_SIZE 2048
    char bigString[BIG_STR_SIZE];
    int next = 0;
    for (int row = 0; row < CFG_CHAR_HEIGHT; ++row)
    {
        next = CHR_getPartialCharacter('2', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('0', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('2', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('5', row, bigString, BIG_STR_SIZE, next);
        bigString[next-1] = '\n'; // end line
    }
    // add null terminator to string at last index
    bigString[next] = '\0';
    printf("%s", bigString);


    next = 0;
    for (int row = 0; row < CFG_CHAR_HEIGHT; ++row)
    {
        next = CHR_getPartialCharacter('0', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('1', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('2', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('3', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('4', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('5', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('6', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('7', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('8', row, bigString, BIG_STR_SIZE, next);
        next = CHR_getPartialCharacter('9', row, bigString, BIG_STR_SIZE, next);
        bigString[next-1] = '\n'; // end line
    }
    // add null terminator to string at last index
    bigString[next] = '\0';
    printf("%s", bigString);

    return 0;
}
