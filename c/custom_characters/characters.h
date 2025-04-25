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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define VALID_ASCII_RANGE_BEGIN 32
#define VALID_ASCII_RANGE_END 127
#define CHARMAP_SIZE 128
#define BACKGROUND_CHARACTER 'b'
#define FOREGROUND_CHARACTER 'f'

typedef struct metadata
{
    int width;
    int height;
    char fill_char;
    char bg_char;
} metadata_t;

typedef struct encoding
{
   char **char_map;
   int char_map_size;
   metadata_t meta;
} encoding_t;

int CHR_read_encoding_from_csv(const char *filename, const int length, encoding_t* encode);
void CHR_cleanup(const encoding_t* enc);

/**
 * Convert a string into a buffer.
 * @param[in] str The string to convert.
 * @param[in] str_len The length of the string to convert.
 * @param[in] enc The character encoding.
 * @param[out] buffer The place to hold the decoded character.
 * @param[in] buffer_size The size of the buffer.
 * 
 * @note A null terminator is appended when using this function.
 * 
 * @return 1 if the entire string is converted, -1 if the string is partially converted, and 0 for other errors.
 */
int CHR_get_string(const char *str, const int str_len, const encoding_t* enc, char *buffer, const int buffer_size);

/**
 * Get an entire, single character into a buffer.
 * @param[in] ch The character to get.
 * @param[in] enc The character encoding to use.
 * @param[out] buffer The place to hold the decoded character.
 * @param[in] buffer_size The size of the buffer.
 * 
 * @note A null terminator is appended when using this function.
 *
 * @return 1 if the character is populated into the buffer, otherwise 0.
 */
int CHR_get_character(const char ch, const encoding_t* enc, char *buffer, const int buffer_size);

/**
 * Get a row for a single character into a buffer.
 * @param[in] ch The character to get.
 * @param[in] enc The character encoding to use.
 * @param[in] char_row The row of the character.
 * @param[out] buffer The place to hold the decoded character.
 * @param[in] buffer_size The size of the buffer.
 * @param[in/out] buffer_index The index to begin within the buffer and the new ending index.
 * 
 * @note No null terminator is appended when using this function.
 *
 * @return 1 if the character row is populated into the buffer, otherwise 0.
 */
int CHR_get_partial_character(const char ch, const encoding_t* enc, const int char_row, char* buffer, const int buffer_size, int* buffer_index);

#ifdef __cplusplus
}
#endif
