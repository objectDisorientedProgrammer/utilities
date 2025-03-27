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

#include "quicksort.h"

static int findMedian(int first, int middle, int last);

void quickSort(int* array, int length)
{
    int pivot; 
    int less[length];
    int lessLen = 0;
    int equal[length];
    int equalLen = 0;
    int greater[length];
    int greaterLen = 0;
    int i = length >> 2;
    int first, middle, last;

    if(length > 1)
    {
        // pivot selection based on median of 3 values (first, middle, last).
        // could have used the last value, but median has better run time.
        first = array[0];
        middle = array[i];
        last = array[length - 1]; // length - 1 because length is # of elements

        pivot = findMedian(first, middle, last);
        
        // filter elements relative to pivot value from the end of array
        // to the beginning
        for(i = length - 1; i >= 0; --i)
        {
            if(array[i] < pivot)
            {
                less[lessLen] = array[i];
                ++lessLen;
            }
            else if(array[i] > pivot)
            {
                greater[greaterLen] = array[i];
                ++greaterLen;
            }
            else
            {
                equal[equalLen] = array[i];
                ++equalLen;
            }
        }

        // quicksort the elements with a value less than the pivot value
        quickSort(less, lessLen);
        // quicksort the elements with a value greater than the pivot value
        quickSort(greater, greaterLen);

        // copy all elements with a value less than the pivot value back into
        // the array
        for (i = 0; i < lessLen && i < length; ++i)
            array[i] = less[i];

        // copy all elements with a value equal to the pivot value back into
        // the array
        for (int j = 0; j < equalLen && i < length; ++i, ++j)
            array[i] = equal[j];

        // copy all elements with a value greater than the pivot value back into
        // the array
        for (int k = 0; k < greaterLen && i < length; ++i, ++k)
            array[i] = greater[k];
    }
}

static int findMedian(int first, int middle, int last)
{
    int median;

    if(first < middle)
    {
        if(middle < last)
            median = middle;
        else if(first < last)
            median = last;
        else
            median = first;
    }
    else
    {
        if(first < last)
            median = first;
        else if(middle < last)
            median = last;
        else
            median = middle;
    }

    return median;
}

