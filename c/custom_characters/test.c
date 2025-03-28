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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata
{
    int width;
    int height;
    char fill_char;
    char bg_char;
} metadata_t;

metadata_t fileinfo;
#define CHARMAP_SIZE 128
char* charmap[CHARMAP_SIZE];

void read_csv(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char line[1024];

    // read the width, height, foreground, and background character
    if (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ",");
        if (token != NULL)
            fileinfo.width = atoi(token);
        token = strtok(NULL, ",");
        if (token != NULL)
            fileinfo.height = atoi(token);
        token = strtok(NULL, ",");
        if (token != NULL)
            fileinfo.fill_char = *token;
        token = strtok(NULL, ",");
        if (token != NULL)
            fileinfo.bg_char = *token;
        token = strtok(NULL, ",");
        while (token != NULL)
            token = strtok(NULL, ",");
    }

    // Read each line in the CSV file
    while (fgets(line, sizeof(line), file))
    {
        // Tokenize the line by comma
        char *token = strtok(line, ",");
        while (token != NULL)
        {
            // special case for comma character since we use CSV
            if (strncmp(token, "comma", 6) == 0)
                *token = ',';
            //if (isdigit(*token))
            {
                char *digit=token;
                int end = fileinfo.width*fileinfo.height+1;
                char *encoding = (char*) malloc(end * sizeof(char));
                if (encoding == NULL)
                {
                    perror("failed to allocate character encoding memory");
                    return;
                }
                for (int i = 0; i < end-1; ++i)
                {
                    token = strtok(NULL, ",");
                    if (token != NULL)
                    {
                        //printf("%s ", token);
                        encoding[i] = *token;
                    }
                }
                encoding[end]='\0';
                charmap[*digit] = encoding;
            }
            token = strtok(NULL, ",");
        }
        //printf("\n");
    }

    fclose(file);
}

void printFullChar(char c)
{
    for (int i = 0; charmap[c][i] != '\0'; ++i)
    {
        if (i != 0 && i % fileinfo.width == 0)
            printf("\n");
        if (charmap[c][i] == 'b')
        {
            printf("%c", fileinfo.bg_char);
        }
        else if (charmap[c][i] == 'f')
        {
            printf("%c", fileinfo.fill_char);
        }
    }
    puts("");
}

void printCharacters(char* word)
{
    puts("");
    for (int c=0; word[c]; ++c)
        printFullChar(toupper(word[c]));
    puts("");
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
            buf[startIndex] = table[c][row * (fileinfo.width) + i] == 'b' ? fileinfo.bg_char : fileinfo.fill_char;
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

    puts("");
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

void releaseMemory(char **map, int len)
{
    for (char i = '0'; i <= 'Z'; ++i)
    {
        if (map[i] != NULL)
        {
            //printf("freeing { %c :'%s'}\n", i, charmap[i]); // DEBUG
            free(map[i]);
        }
        //else
        //    printf("%c not defined\n", i); // DEBUG
    }
}

void read_encoding_from_csv(const char *filename)
{
    read_csv(filename);
    
    #if 0 // for testing character rendering
    read_csv("encoding_example.csv");
    printString("0987654321");
    printString("abcdefghij");
    printString("klmnopqrst");
    printString("uvwxyz");
    puts("");
    #endif
}

int main(int argc, char *argv[])
{
    /*char buf[1024];

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
    */
    char enormousBuffer[8192];
    char filename[1024];
    

    // process command line args
    if (argc > 1)
    {
        int a = 1;
        strncpy(filename, argv[a], 1023);
        ++a;
        
        while (argv[a])
        {
            // TODO make this safe by checking how much buffer is used vs strlen(argv)
            strncat(enormousBuffer, argv[a], 50);
            ++a;
            strncat(enormousBuffer, " ", 2);
        }
        enormousBuffer[strlen(enormousBuffer)-1] = '\0';
    }
    else
    {
        // default values
        strcpy(filename, "encoding_example.csv"); // default file
        strcpy(enormousBuffer, "March 27th 2025"); // default string
    }

    // initialize character map
    memset(charmap, 0, CHARMAP_SIZE);

    read_encoding_from_csv(filename);

    printString(enormousBuffer);

    releaseMemory(charmap, CHARMAP_SIZE);

    return 0;
}
