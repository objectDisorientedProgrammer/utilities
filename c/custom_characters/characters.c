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

int CHR_get_string(const char *str, const int str_len, const encoding_t* enc, char *buffer, const int buffer_size)
{
    // validate input pointers
    if (str == NULL || enc == NULL || buffer == NULL)
        return 0;
    // ensure the buffer is big enough to hold the string

    int index = 0;
    // create the string, row by row
    for (int row = 0; row < enc->meta.height; ++row)
    {
        // add each character in the row
        for (int c = 0; str[c]; ++c)
        {
            // If the character is space and not the first character in the string,
            // backtrack the buffer index since each normal character ends with
            // an extra space appended. This ensures space is the correct width.
            if (str[c] == ' ' && index > 0)
                --index;
            if (1 != CHR_get_partial_character(str[c], enc, row,  buffer, buffer_size, &index))
            {
                // error, complete string and return
                buffer[index] = '\0';
                return -1;
            }
            // if the character is not space, add padding between characters
            if (str[c] != ' ')
            {
                buffer[index] = enc->meta.bg_char;
                ++index;
            }
        }
        // complete the row
        buffer[index-1] = '\n';
    }
    // complete the string
    buffer[index-1] = '\0';

    return 1;
}

int CHR_get_character(const char ch, const encoding_t* enc, char *buffer, const int buffer_size)
{
    /* Required length is larger than charWidth*charHeight since we add a newline
       to the end of each letter segment so it displays propperly and a +1 for \0.
    */
    //                                 newline                 null terminator
    int required_len = ((enc->meta.width + 1) * enc->meta.height) + 1;
    int ch_index = (int) toupper(ch);

    // validate input pointers
    if (enc == NULL || buffer == NULL)
        return 0;
    // check for valid character index in map
    else if (ch_index < VALID_ASCII_RANGE_BEGIN || ch_index > VALID_ASCII_RANGE_END)
        return 0;
    // ensure the buffer is big enough to hold a character
    else if (buffer_size < required_len)
        return 0;

    // Populate the buffer
    int buf_index = 0;
    for (int i = 0; buf_index < required_len && enc->char_map[ch_index][i] != '\0'; ++i, ++buf_index)
    {
        // add a newline at the end of each letter row segment
        if (i != 0 && i % enc->meta.width == 0)
        {
            buffer[buf_index] = '\n';
            ++buf_index;
        }
        buffer[buf_index] = enc->char_map[ch_index][i];
    }
    // Terminate string using buf_index because required_len is oversized
    buffer[buf_index] = '\0';
    return 1;
}

int CHR_get_partial_character(const char ch, const encoding_t* enc, const int char_row, char* buffer, const int buffer_size, int* buffer_index)
{
    int ch_index = (int) toupper(ch);

    // validate input pointers
    if (enc == NULL || buffer == NULL || buffer_index == NULL)
        return 0;
    // check for valid character index in map
    else if (ch_index < VALID_ASCII_RANGE_BEGIN || ch_index > VALID_ASCII_RANGE_END)
        return 0;
    // invalid row
    else if (char_row > enc->meta.height)
        return 0;

    // if there is room in the buffer and the character is defined, get the decoded row
    if ((*buffer_index) + enc->meta.width < buffer_size && enc->char_map[ch_index] != NULL)
    {
        for (int i = 0; i < enc->meta.width; ++i)
        {
            buffer[*buffer_index] = enc->char_map[ch_index][char_row * (enc->meta.width) + i];
            ++(*buffer_index);
        }
    }
    else
        return 0;

    return 1;
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
    int line_number = 1; // starts at 1 since the 1st line (line_number zero) is metadata
    while (fgets(line, sizeof(line), file))
    {
        ++line_number;
        // Tokenize the line by comma
        char *token = strtok(line, ",");
        while (token != NULL)
        {
            // verify the token is within the valid ASCII range
            if (*token < VALID_ASCII_RANGE_BEGIN || *token >= VALID_ASCII_RANGE_END)
            {
                fprintf(stderr, "Error line %d: character %c (UTF-8 0x%X) not recognized.\n", line_number, *token, (int)(*token)&0xFF);
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
