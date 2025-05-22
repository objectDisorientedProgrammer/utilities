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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (1024U)
#define ENORMOUS_BUF_SIZE (BUF_SIZE * 8U)

void printString(const char* str, const encoding_t* enc)
{
    int slen = strlen(str);
    char output[BUF_SIZE];

    if (CHR_get_string(str, slen, enc, output, BUF_SIZE-1))
        printf("%s\n\n", output);
    else
        fprintf(stderr, "Error creating string '%s'\n", str);
}

void print_encoding(const encoding_t* enc)
{
    // for testing character rendering
    printString("~`!@#$ %^&", enc);
    printString("_()*/-+={}", enc);
    printString("[],?.;:'\"", enc);
    printString("0987654321", enc);
    printString("abcdefghij", enc);
    printString("klmnopqrst", enc);
    printString("uvwxyz", enc);
    puts("");
}

void writeToFile(const char* filename, size_t filenameSize, const char* buffer, size_t bufferSize)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", filename);
        return;
    }

    fprintf(file, "%s", buffer);

    fclose(file);
}

int main(int argc, char *argv[])
{
    char* charmap[CHARMAP_SIZE];

    char enormousBuffer[ENORMOUS_BUF_SIZE] = {0};
    char filename[BUF_SIZE] = {0};
    size_t enormousBufferRemainingSize = ENORMOUS_BUF_SIZE;

    char input[BUF_SIZE] = {0};
    size_t inputRemainingSize = BUF_SIZE;
    int isDefault = 0;

    char outputFile[BUF_SIZE] = {0};
    strncpy(outputFile, "custom_string_default_output.txt", BUF_SIZE - 1);
    
    // process command line args
    if (argc > 1)
    {
        int a = 1;
        size_t argLen = strlen(argv[a]);
        strncpy(filename, argv[a], BUF_SIZE - 1);
        if (argLen > BUF_SIZE-1)
        {
            filename[BUF_SIZE-1]='\0';
            fprintf(stderr, "Error: Filename too long %s -> %s\n", argv[a], filename);
            return -1;
        }
        ++a;
        
        while (argv[a])
        {
            argLen = strlen(argv[a]);
            if (enormousBufferRemainingSize >= argLen + 2)
            {
                strncat(input, argv[a], inputRemainingSize);
                inputRemainingSize -= argLen;
                ++a;
                strncat(input, " ", 2);
                inputRemainingSize -= 2;
            }
            else
            {
                fprintf(stderr, "Error: ran out of buffer space. Need %ld, have %ld.\n", argLen+2, inputRemainingSize);
                break;
            }
        }
        input[(BUF_SIZE * 8) - enormousBufferRemainingSize - 1] = '\0';
    }
    else
    {
        // default values
        strcpy(filename, "encoding_example.csv"); // default file
        strcpy(input, "March 27, 2025"); // default string
        inputRemainingSize = BUF_SIZE - 16;
        isDefault = 1;
    }

    encoding_t enc;
    enc.char_map = charmap;
    enc.char_map_size = CHARMAP_SIZE;

    // initialize character map
    memset(charmap, 0, CHARMAP_SIZE * sizeof(char*));

    if (1 == CHR_read_encoding_from_csv(filename, strlen(filename), &enc))
    {
        if (CHR_get_string(input, BUF_SIZE - inputRemainingSize, &enc, enormousBuffer, BUF_SIZE))
        {
            printf("%s\n", enormousBuffer);
            writeToFile(outputFile, BUF_SIZE, enormousBuffer, ENORMOUS_BUF_SIZE);
        }
        else
            fprintf(stderr, "Error creating string '%s'\n", input);
        if (isDefault)
        {
            if (CHR_get_character('a', &enc, enormousBuffer, BUF_SIZE)) printf("\n%s\n", enormousBuffer);
            if (CHR_get_character('r', &enc, enormousBuffer, BUF_SIZE)) printf("\n%s\n", enormousBuffer);
            if (CHR_get_character('c', &enc, enormousBuffer, BUF_SIZE)) printf("\n%s\n", enormousBuffer);
            if (CHR_get_character('h', &enc, enormousBuffer, BUF_SIZE)) printf("\n%s\n", enormousBuffer);
            puts("");
        }

        //print_encoding(&enc); // DEBUG
    }
    CHR_cleanup(&enc);
    
    return 0;
}
