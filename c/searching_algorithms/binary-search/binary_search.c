/**
    binary_search.c
    Created 31 March 2020


    MIT License

    Copyright (c) 2020 objectDisorientedProgrammer

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "binary_search.h"

// assume starting from array[0]
int binarySearchInt(const int* array, const int len, const int findMe)
{
    if(len <= 0)
        return -1;

    int low = 0;
    int high = len - 1;
    int mid;

    while(low <= high)
    {
        mid = low + ((high - low) >> 1);

        if(array[mid] < findMe) // search from high to mid
        {
            low = mid + 1;
        }
        else if(array[mid] > findMe) // search from mid to low
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

