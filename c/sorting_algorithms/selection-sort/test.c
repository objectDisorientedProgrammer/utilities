/**
    test.c
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

#include "test.h"
#include "selectionSort.h"
#include <stdio.h>

int main(void)
{
    char* filename = "randomInts.txt";
    int values[ARRAY_SIZE];
    //int values[ARRAY_SIZE] = {5, -3, 2, 1, -4, 100, -20, 15, 3, -3, 45, 44, -40};
    
    #if VERBOSE
    int k = 0;
    #endif

    // read ints from a file
    FILE *myfile = fopen(filename, "r");
    if(myfile == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        for(int i = 0; i < ARRAY_SIZE; ++i)
        {
            fscanf(myfile, "%d", &values[i]);
        }
        fclose(myfile);

        #if VERBOSE
        // print out array before sorting
        printf("starting array\n[ ");
        for(k = 0; k < ARRAY_SIZE; k++)
        {
            printf("%d ", values[k]);
        }
        puts("]");
        #endif

        // sort
        selectionSortInt(values, ARRAY_SIZE);

        #if VERBOSE
        // print out array after sorting
        printf("sorted array\n[ ");
        for(k = 0; k < ARRAY_SIZE; k++)
        {
            printf("%d ", values[k]);
        }
        puts("]");
        #endif

        // test to make sure the sort worked
        testSortedInts(values, ARRAY_SIZE);

        // reverse sort and test
        selectionSortReverseInt(values, ARRAY_SIZE);
        
        #if VERBOSE
        printf("sorted array\n[ ");
        for(k = 0; k < ARRAY_SIZE; k++)
        {
            printf("%d ", values[k]);
        }
        puts("]");
        #endif
        
        testReverseSortedInts(values, ARRAY_SIZE);
    }
    
    return 0;
}

void testSortedInts(int* sortedArray, const int size)
{
    int isSorted = 1;
    int i = 0;

    if(size <= 1)
    {
        puts("Value is sorted!");
    }
    else if(size > 1)
    {
        for(i = 0; sortedArray[i] && sortedArray[i + 1] && i < size; ++i)
        {
            if(sortedArray[i] > sortedArray[i + 1])
            {
                isSorted = 0;
                break;
            }
        }

        if(isSorted)
        {
            puts("Values are sorted!");
        }
        else
        {
            printf("Array not sorted at index %d!\n", i);
            printf("%d > %d\n", sortedArray[i], sortedArray[i + 1]);
        }
        
    }
}

void testReverseSortedInts(int* sortedArray, const int size)
{
    int isSorted = 1;
    int i = 0;

    if(size <= 1)
    {
        puts("Value is sorted!");
    }
    else if(size > 1)
    {
        for(i = 0; sortedArray[i] && sortedArray[i + 1] && i < size; ++i)
        {
            if(sortedArray[i] < sortedArray[i + 1])
            {
                isSorted = 0;
                break;
            }
        }

        if(isSorted)
        {
            puts("Values are sorted!");
        }
        else
        {
            printf("Array not sorted at index %d!\n", i);
            printf("%d < %d\n", sortedArray[i], sortedArray[i + 1]);
        }
    }
}

