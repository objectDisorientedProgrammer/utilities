/**
    selectionSort.c
    Created 7 May 2016




    MIT License

    Copyright (c) 2016 objectDisorientedProgrammer

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

#include "selectionSort.h"

void selectionSortInt(int* values, const int arraySize)
{
    int i = 0;
    int j = 0;
    int minIndex = 0;
    int temp = 0;

    for(i = 0; i < arraySize - 1; ++i)
    {
        minIndex = i + 1;
        // select min
        for(j = i; j < arraySize; j++)
            if(values[j] < values[minIndex])
                minIndex = j;
        // swap values
        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
}

void selectionSortReverseInt(int* values, const int arraySize)
{
    int i = 0;
    int j = 0;
    int minIndex = 0;
    int temp = 0;

    for(i = 0; i < arraySize - 1; ++i)
    {
        minIndex = i + 1;
        // select min
        for(j = i; j < arraySize; j++)
            if(values[j] > values[minIndex])
                minIndex = j;
        // swap values
        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
}

void selectionSortFloat(float* values, const int arraySize)
{
    int i = 0;
    int j = 0;
    int minIndex = 0;
    float temp = 0;

    for(i = 0; i < arraySize - 1; ++i)
    {
        minIndex = i + 1;
        // select min
        for(j = i; j < arraySize; j++)
            if(values[j] < values[minIndex])
                minIndex = j;
        // swap values
        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
}

void selectionSortDouble(double* values, const int arraySize)
{
    int i = 0;
    int j = 0;
    int minIndex = 0;
    double temp = 0;

    for(i = 0; i < arraySize - 1; ++i)
    {
        minIndex = i + 1;
        // select min
        for(j = i; j < arraySize; j++)
            if(values[j] < values[minIndex])
                minIndex = j;
        // swap values
        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
}

