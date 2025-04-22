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


static const char* decodeChar(const char c);
static const char* numeric(const char c);
static char* alphabetic(char c);
static char* generate_space(void);

int CHR_getCharacter(const char ch, const encoding_t* enc, char *buffer, const int buffer_size)
{
    /* Required length is larger than charWidth*charHeight since we add a newline
       to the end of each letter segment so it displays propperly and a +1 for \0.
    */
    //                                 newline                 null terminator
    int requiredLen = ((enc->meta.width + 1) * enc->meta.height) + 1;
    int ch_index = (int) toupper(ch);

    // validate input pointers
    if (enc == NULL || buffer == NULL)
        return 0;
    // check for valid character index in map
    else if (ch_index < VALID_ASCII_RANGE_BEGIN || ch_index > VALID_ASCII_RANGE_END)
        return 0;
    // ensure the buffer is big enough to hold a character
    else if (buffer_size < requiredLen)
        return 0;

    // Populate the buffer
    int buf_index = 0;
    for (int i = 0; buf_index < requiredLen && enc->char_map[ch_index][i] != '\0'; ++i, ++buf_index)
    {
        // add a newline at the end of each letter row segment
        if (i != 0 && i % enc->meta.width == 0)
        {
            buffer[buf_index] = '\n';
            ++buf_index;
        }
        buffer[buf_index] = enc->char_map[ch_index][i];
    }
    buffer[buf_index] = '\0';
    return 1;
}

int CHR_getPartialCharacter(const char c, const int row, char* out, const int len, int offset)
{
    return 0;
}

int CHR_read_encoding_from_csv(const char *filename, const int length, encoding_t* encode)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        int size = 23 + strlen(filename);
        char errorMsg[size];
        int written = snprintf(errorMsg, size, "Failed to open file: '%s'", filename);
        if (written >= 0 && written < size)
        {
            perror(errorMsg);
        }
        else
            perror("Failed to create error message");
        return 0;
    }

    char line[1024];

    // read the width, height, foreground, and background character
    if (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ",");
        if (token != NULL)
            encode->meta.width = atoi(token);
        token = strtok(NULL, ",");
        if (token != NULL)
            encode->meta.height = atoi(token);
        token = strtok(NULL, ",");
        if (token != NULL)
            encode->meta.fill_char = *token;
        token = strtok(NULL, ",");
        if (token != NULL)
            encode->meta.bg_char = *token;
        token = strtok(NULL, ",");
        while (token != NULL)
            token = strtok(NULL, ",");
    }

    // Read each line in the CSV file
    int lineNumber = 1; // starts at 1 since the 1st line is metadata
    while (fgets(line, sizeof(line), file))
    {
        ++lineNumber;
        // Tokenize the line by comma
        char *token = strtok(line, ",");
        while (token != NULL)
        {
            // verify the token is within the valid ASCII range
            if (*token < VALID_ASCII_RANGE_BEGIN || *token >= VALID_ASCII_RANGE_END)
            {
                fprintf(stderr, "Error line %d: character %c (UTF-8 0x%X) not recognized.\n", lineNumber, *token, (int)(*token)&0xFF);
                break;
            }
            // special case for comma character since we use CSV
            if (strncmp(token, "comma", 6) == 0)
                *token = ',';
            //if (isdigit(*token))
            {
                char *digit=token;
                int end = encode->meta.width * encode->meta.height + 1;
                char *encoding = (char*) malloc(end * sizeof(char));
                if (encoding == NULL)
                {
                    perror("Failed to allocate character encoding");
                    return 0;
                }
                for (int i = 0; i < end-1; ++i)
                {
                    token = strtok(NULL, ",");
                    if (token != NULL)
                    {
                        //printf("%s ", token);
                        // decode and store character
                        encoding[i] = (*token == BACKGROUND_CHARACTER) ? encode->meta.bg_char : encode->meta.fill_char;
                    }
                }
                encoding[end]='\0';
                encode->char_map[(int)*digit] = encoding;
            }
            token = strtok(NULL, ",");
        }
        //printf("\n");
    }

    fclose(file);
    return 1;
}

void CHR_cleanup(const encoding_t* enc)
{
    for (int i = VALID_ASCII_RANGE_BEGIN; i < enc->char_map_size; ++i)
    {
        if (enc->char_map[i] != NULL)
        {
            // printf("freeing %d { %c :'%s'}\n", i, i, enc->char_map[i]); // DEBUG
            free(enc->char_map[i]);
        }
        // else
        //    printf("%d %c not defined\n", i, i); // DEBUG
    }
}

static const char* decodeChar(const char c)
{
    const char* pStr;
    /*if(c == ' ')
        pStr = space;
    else if(isdigit(c))
        pStr = numeric(c);*/
    // if c is 0-9
    //      numeric(c)
    // else if c is A-Za-z
    //      alphabetic(c)
    // else space, \n, \r
    // TODO handle math +-*/=()%
    // TODO handle punctuation .?!,'"
    return pStr;
}

static const char* numeric(const char c)
{
    const char* pStr;
    // switch(c)
    // {
    //     case '0': pStr = zero; break;
    //     case '1': pStr = one; break;
    //     case '2': pStr = two; break;
    //     case '3': pStr = three; break;
    //     case '4': pStr = four; break;
    //     case '5': pStr = five; break;
    //     case '6': pStr = six; break;
    //     case '7': pStr = seven; break;
    //     case '8': pStr = eight; break;
    //     case '9': pStr = nine; break;
    //     default:
    //         break;
    // }
    return pStr;
}

static char* generate_space(void)
{
    return NULL;

}
