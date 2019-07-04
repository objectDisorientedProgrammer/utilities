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
#include <stdio.h>

int main(void)
{
    char buf[100];

    for (char i = '0'; i <= '9'; ++i)
    {
        printf("%s\n", CHR_getCharacter(i));
    }
#if 0
// TODO combine 2 characters
    for (int i = 0; i < 5; ++i)
    {
         CHR_getPartialCharacter('2', i, buf + (i * 5), 100);
         CHR_getPartialCharacter('5', i, buf + (i * 5), 100);
         buf[i * 5 * 2] = '\n';
    }
#endif
#if 0
// TODO read one character with getPartial() in another change
    CHR_getPartialCharacter('2', 0, buf, 5);
    printf("\n%s\n", buf);
    CHR_getPartialCharacter('2', 1, buf+5, 10);
    buf[11] = '\0';
    printf("\n%s\n", buf);
#endif
    return 0;
}
