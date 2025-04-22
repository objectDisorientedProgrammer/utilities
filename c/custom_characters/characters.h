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

// const char* CHR_getCharacter(const char c);
// int CHR_getPartialCharacter(const char c, const int row, char* out, const int len, int offset);

#ifdef __cplusplus
}
#endif
