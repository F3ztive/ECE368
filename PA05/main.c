#include <stdio.h>
#include <stdlib.h>
//#include "sorting.h"
//#include "sorting.c"
void Quick_Sort(long * Array, int Size);
long comparefunc(const void * ptr1, const void * ptr2);
void printarr(int * intArray, int size);
int compareint(const void * a, const void * b) ;
void intqs(int * Array, int Size);

int main(int argc, char** argv) {
    long Array[5] = {3,1,4,1,5};
    int intArray[5] = {3,1,4,1,5};
    
    int Size = sizeof(Array) / sizeof(Array[0]);
    int intsize = sizeof(intArray) / sizeof(intArray[0]);
    //printarr(Array,Size);

    printarr(intArray,intsize);

    intqs(intArray, intsize);
    printf("\n");
    printarr(intArray,Size);

    return (EXIT_SUCCESS);
}

int compareint (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

long comparefunc(const void * ptr1, const void * ptr2)
{
    
    return 6;
}

void intqs(int * intArray, int Size)
{
    qsort(intArray, Size, sizeof(int),compareint);

}

void Quick_Sort(long * Array, int Size)
{
    qsort(Array, Size, sizeof(Array[0]),comparefunc);
}

void printarr(int * intArray, int size)
{
    int i = 0;
    while (i<size)
    {
        printf("%d",intArray[i]);
        i++;
    }
}

void Merge_Sort(long * Array, int Size)
{
    
}

