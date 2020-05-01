#include <stdio.h>
#include <stdlib.h>

void Quick_Sort(long * Array, int Size);
long comparefunc(const void * ptr1, const void * ptr2);
void printarr(long * intArray, int size);
int compareint(const void * a, const void * b) ;
void intqs(int * Array, int Size);
void QUICKHELP(long * Array, int LB, int UB);
void swap(long * x, long * y);
int getpivot(long * Array, int LB, int UB);

void swap(long * x, long * y)
{
   // printf("\n%ld:%ld",Array[pos1],Array[pos2]);
    long a = *x;
    *x = *y;
    *y = a;
}

/*int getpivot(long * Array, int LB, int UB)
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
*/
long comparefunc(const void * ptr1, const void * ptr2)
{
    return ( *(long*)ptr1 - *(long*)ptr2 );
}

void QUICKHELP(long * Array, int LB, int UB)
{
    if (LB >= UB)
    {
        return;
    }
    int pivot = Array[LB];
    int low = LB+1;
    int high = UB;
    while (low < high)
    {
        while ((low<UB) && Array[low] <= pivot)
        {
            low++;
        }
        while ((LB < high) && (Array[high] > pivot))
        {
            high--;
        }
        if (low < high)
        {
            swap(&Array[low],&Array[high]);
        }
    }
    if (pivot>Array[high])
    {
        swap(&Array[LB],&Array[high]);
    }
    QUICKHELP(Array,LB,high-1);
    QUICKHELP(Array,low,UB);
}
void Quick_Sort(long * Array, int Size)
{
    Size--;
    QUICKHELP(Array, 0, Size);
}


void merge(long * Array, int LB, int mid, int UB)
{
    
    long temp[(UB-LB)+1];
    int iL = LB; 
    int iM = mid+1;
    int i = 0; 
    while (iL <= mid && iM <= UB)
    {
        if(Array[iL] <= Array[iM])
        {
            temp[i] = Array[iL];
            iL++;
        }
	else
	{
            temp[i] = Array[iM];
            iM++;
        }
        i++;
    }
    while(iL <= mid)
    {
        temp[i] = Array[iL];
        iL++;
        i++;
    }
    while(iM <= UB)
    {
        temp[i] = Array[iM];
        iM++;
        i++;
    }
    for(iL = 0; iL < i; iL++)
    {
	Array[LB + iL] = temp[iL];
    }    
}

void MERGEHELP(long * Array, int LB, int UB)
{
    if (LB >= UB)
        return;
    printf("\n");

    int mid = (UB + LB) / 2;
    MERGEHELP(Array, LB, mid);
    MERGEHELP(Array, mid + 1, UB);
    merge(Array, LB, mid, UB);
}

void Merge_Sort(long * Array, int Size)
{
    MERGEHELP(Array, 0,Size-1);
}



int main(int argc, char** argv) {
    
    long Array[5] = {30,11,41,10,50};
    
    int Size = sizeof(Array) / sizeof(long);
    //Load_Into_Array(Filename, Size);
    //Save_From_Array(Filename, Array, Size)
    printarr(Array,Size);
    //Quick_Sort(Array, Size);
    Merge_Sort(Array, Size);
    printf("\nFinal Array: ");
    printarr(Array,Size);
    
    
    return (EXIT_SUCCESS);
}



void printarr(long * intArray, int size)
{
    int i = 0;
    while (i<size)
    {
        printf("%ld,",intArray[i]);
        i++;
    }
}


