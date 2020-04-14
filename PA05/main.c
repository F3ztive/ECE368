#include <stdio.h>
#include <stdlib.h>
//#include "sorting.h"
//#include "sorting.c"
void Quick_Sort(long * Array, int Size);
long comparefunc(const void * ptr1, const void * ptr2);
void printarr(long * intArray, int size);
int compareint(const void * a, const void * b) ;
void intqs(int * Array, int Size);
void QUICKHELP(long * Array, int LB, int UB);
void swap(long * Array, int pos1, int pos2);
int getpivot(long * Array, int LB, int UB);
   





int main(int argc, char** argv) {
    
    long Array[5] = {30,11,41,10,50};
    
    int Size = sizeof(Array) / sizeof(long);
    //Load_Into_Array(Filename, Size);
    //Save_From_Array(Filename, Array, Size)
    printarr(Array,Size);
    Quick_Sort(Array, Size);
    printf("\n");
    printarr(Array,Size);
    
    return (EXIT_SUCCESS);
}

void swap(long * Array, int pos1, int pos2)
{
    printf("\n%ld:%ld",Array[pos1],Array[pos2]);
    if (Array[pos1] == Array[pos2])
        return;
    else
    {
        printf("x");
        long temp = Array[pos1];
        Array[pos1] = Array[pos2];
        Array[pos2] = temp;
    }
}

int getpivot(long * Array, int LB, int UB)
{
    int x = LB + (rand() % (UB - LB + 1)); //maybe add " % Size " to rand?
    swap(Array, LB, x);
    
    int pos = LB++;
    for (int i = ++LB; i<=UB; i++ )
    {
        if (Array[i] < Array[LB])
        {
            swap(Array,i,pos++);
        }
    }    
}

long comparefunc(const void * ptr1, const void * ptr2)
{
    return ( *(long*)ptr1 - *(long*)ptr2 );
}



void QUICKHELP(long * Array, int LB, int UB)
{
    if (LB >= UB)
        return;
    int pivot = getpivot(Array, LB, UB);
    QUICKHELP(Array, LB, --pivot);
    QUICKHELP(Array, ++pivot, UB);
}
void Quick_Sort(long * Array, int Size)
{
    Size--;
    QUICKHELP(Array, 0, Size);
}

void printarr(long * intArray, int size)
{
    int i = 0;
    while (i<size)
    {
        printf("%ld",intArray[i]);
        i++;
    }
}

void Merge_Sort(long * Array, int Size)
{
    if (Size > 2)
    {
        
    }
}

