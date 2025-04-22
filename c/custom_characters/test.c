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
//#include "config.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

metadata_t fileinfo;

char* charmap[CHARMAP_SIZE];

void read_csv(const char *filename)
{
    return;
}

int bufferChar(char c, int startIndex, char *buf, int buf_size, int row)
{
    char **table = charmap;
    if (startIndex + fileinfo.width < buf_size && table[c] != NULL)
    {
        // if the character is space and not the first character in the string
        // go back on index in the buffer since each normal character ends
        // with an extra space appended
        if (c == ' ' && startIndex > 0)
            --startIndex;
        int i;
        for (i = 0; i < fileinfo.width; ++i)
        {
            buf[startIndex] = table[c][row * (fileinfo.width) + i];
            ++startIndex;
        }
        // if the character is not space, add padding between characters
        if (c != ' ')
        {
            buf[startIndex] = fileinfo.bg_char;
            ++startIndex;
        }
    }
    return startIndex;
}

void printString(char* str)
{
    int len = strlen(str);
    
    // create space to store the Nth row of all characters in the string plus space and \0
    int linebufferSize = len * (fileinfo.width+1) + 1;
    char linebuffer[linebufferSize];
    int bufferIndex = 0;

    //puts("");
    for (int row = 0; row < fileinfo.height; ++row)
    {
        bufferIndex = 0;
        // buffer each character's encoding
        for (int c=0; str[c]; ++c)
        {
            bufferIndex = bufferChar(toupper(str[c]), bufferIndex, linebuffer, linebufferSize, row);
        }
        // send buffer to stdout
        linebuffer[bufferIndex-1] = '\0';
        printf("%s\n", linebuffer);
    }
}

// void print_encoding(void)
// {
    
//     #if 0 // for testing character rendering
//     printString("~`!@#$%^&_");
//     printString("()*/-+={}[]");
//     printString(",?.;:'\"");
//     printString("0987654321");
//     printString("abcdefghij");
//     printString("klmnopqrst");
//     printString("uvwxyz");
//     puts("");
//     #endif
// }

int main(int argc, char *argv[])
{
    #define BUF_SIZE 1024
    char enormousBuffer[BUF_SIZE * 8];
    char filename[BUF_SIZE];
    size_t enormousBufferRemainingSize = BUF_SIZE * 8;
    
    // process command line args
    if (argc > 1)
    {
        int a = 1;
        size_t argLen = strlen(argv[a]);
        strncpy(filename, argv[a], BUF_SIZE - 1);
        if (argLen > BUF_SIZE-1)
        {
            filename[BUF_SIZE-1]='\0';
            printf("%s -> %s\n", argv[a], filename);
            perror("Filename too long");
            return -1;
        }
        ++a;
        
        while (argv[a])
        {
            argLen = strlen(argv[a]);
            if (enormousBufferRemainingSize >= argLen + 2)
            {
                strncat(enormousBuffer, argv[a], enormousBufferRemainingSize);
                enormousBufferRemainingSize -= argLen;
                ++a;
                strncat(enormousBuffer, " ", 2);
                enormousBufferRemainingSize -= 2;
            }
            else
            {
                printf("Error ran out of buffer space. Need %ld, have %ld.", argLen+2, enormousBufferRemainingSize);
                break;
            }
        }
        enormousBuffer[(BUF_SIZE * 8) - enormousBufferRemainingSize - 1] = '\0';
    }
    else
    {
        // default values
        strcpy(filename, "encoding_example.csv"); // default file
        strcpy(enormousBuffer, "March 27, 2025"); // default string
    }

    encoding_t enc;
    enc.char_map = charmap;
    enc.char_map_size = CHARMAP_SIZE;

    // initialize character map
    memset(charmap, 0, CHARMAP_SIZE * sizeof(char));

    if (1 == CHR_read_encoding_from_csv(filename, strlen(filename), &enc))
    {
        fileinfo = enc.meta;
        printString(enormousBuffer);
        if (CHR_getCharacter('a', &enc, enormousBuffer, BUF_SIZE)) printf("%s\n", enormousBuffer);
        if (CHR_getCharacter('r', &enc, enormousBuffer, BUF_SIZE)) printf("%s\n", enormousBuffer);
        if (CHR_getCharacter('c', &enc, enormousBuffer, BUF_SIZE)) printf("%s\n", enormousBuffer);
        if (CHR_getCharacter('h', &enc, enormousBuffer, BUF_SIZE)) printf("%s\n", enormousBuffer);
        puts("");
    }
    CHR_cleanup(&enc);
    
    return 0;
}
