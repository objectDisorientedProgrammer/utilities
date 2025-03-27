/**
    main.c
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
#include <stdio.h>


void testResult(int status)
{
    if(status > 0)
        printf("found at %d\n", status);
    else
        puts("not found");
}

int main(int argc, char const *argv[])
{
    int test1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // TODO use a real unittest framework...
    testResult(binarySearchInt(test1, sizeof(test1)/sizeof(int), 2)); // found
    testResult(binarySearchInt(test1, sizeof(test1)/sizeof(int), 55)); // not
    testResult(binarySearchInt(test1, 0, 6)); // not

    
    int test2[] = { 23, 44, 51, 65, 66, 67, 88, 89, 91, 92, 94, 100 };

    testResult(binarySearchInt(test2, sizeof(test2)/sizeof(int), 87)); // not
    testResult(binarySearchInt(test2, sizeof(test2)/sizeof(int), 100)); // found

    return 0;
}

