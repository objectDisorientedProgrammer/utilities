/**
    MIT License

    Copyright (c) 2017 objectDisorientedProgrammer

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

#include "mergesort.h"

/**
 * @brief Helper function for mergeSort. Does the work of merging and ordering.
 * @param[out] array - final array with sorted elements.
 * @param[in]  length - number of elements in array.
 * @param[in]  leftArray - first half of elements from array.
 * @param[in]  leftLength - number of elements in leftArray.
 * @param[in]  rightArray - second half of elements from array.
 * @param[in]  rightLength - number of elements in rightArray.
 */
static void merge(int* array, int length, int* leftArray, int leftLength,
    int* rightArray, int rightLength);

void mergeSort(int* array, int length)
{
    int sub1Length = (length % 2 == 0)? length >> 1 : (length >> 1) + 1; // ceil(length/2)
    int sub2Length = length >> 1; // floor(length/2)
    int sub1[sub1Length];
    int sub2[sub2Length];
    int i;

    // if array has at least 2 elements
    if(length > 1)
    {
        // split the array into 2 sequences
        for(i = 0; i < sub1Length; ++i)
        {
            sub1[i] = array[i];
        }

        for(int j = 0, i = sub1Length; i < length && j < sub2Length; ++i, ++j)
        {
            sub2[j] = array[i];
        }

        // recursively sort
        mergeSort(sub1, sub1Length);
        mergeSort(sub2, sub2Length);
        merge(array, length, sub1, sub1Length, sub2, sub2Length);
    }
}

static void merge(int* array, int length, int* leftArray, int leftLength,
    int* rightArray, int rightLength)
{
    int i, j, rear;
    rear = 0;

    // compare elements from left and right and put the smaller element into array
    for(i = 0, j = 0; i < leftLength && j < rightLength; ++rear)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[rear] = leftArray[i];
            ++i;
        }
        else
        {
            array[rear] = rightArray[j];
            ++j;
        }
    }

    // copy remaining elements of left
    for( ; i < leftLength; ++i, ++rear)
        array[rear] = leftArray[i];
    // copy remaining elements of right
    for( ; j < rightLength; ++j, ++rear)
        array[rear] = rightArray[j];
}

