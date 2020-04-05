#include <stdio.h>
#include <stdlib.h>

//long *Array_Load_From_File(char *filename, int *size);
//int Array_Save_To_File(char *filename, long *array, int size);
//void Array_Shellsort(long *array, int size, long *n comp);
typedef struct listnode {
    struct listnode * next;
    int value;
} Node;

Node * readfile(int * size);
Node * List_Insert(Node * head, int val);
Node * Node_Construct(int val);
int determinek(int size, int k, int prevk);
Node * LLKsort(Node *head, int k, int size);
void LLswap(Node * a, Node * b);

int main()
{
    int size  = 0;
    Node * head = NULL;
    head = readfile(&size);
    printf("size is %d\n",size);
    int prevk;
    int k = determinek(14, 1, prevk);
    printf("\nk is now %d",k);
    head = LLKsort(head, k, size);
    return 0;
}

void swap(Node *a, Node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
}

Node * LLKsort(Node *head, int k, int size)
{
    int ksneeded = size / k;
    printf("/n k's needed is: %d",ksneeded);
    
    
    
    
    for (int i = 0; i < ksneeded; i++)
    {
        
    }
}



int determinek(int size, int k, int prevk)
{
    while (k<size)
    {
        prevk = k;
        k = 3*k+1;
        k = determinek(size,k,prevk);  
    }
    printf("PK:%d",prevk);
    return k;
}
Node * readfile(int * size) //read file and store list from file
{
    FILE * fptr;
    fptr = fopen("10.txt", "r");
    int readint = 0;
    fscanf(fptr,"%d",&readint);
    
    Node * HEAD = NULL;
    HEAD = malloc(sizeof(Node));
    HEAD->next = NULL;
    HEAD->value = 0;
    
    if (fptr == NULL)
    {
        printf("Can't read file :(\n");
        return HEAD;
    } 
    
    while (!feof(fptr))
    {
        HEAD = List_Insert(HEAD,readint);
        fscanf(fptr, "%d",&readint);
        *size = *size+1;
    }
    HEAD = List_Insert(HEAD,readint);
    fclose(fptr);
}


Node * Node_Construct(int val)
{
    Node * nd = malloc(sizeof(Node));
    nd -> value = val;
    nd -> next = NULL;
    return nd;
}

Node * List_Insert(Node * head, int val)
{
    printf("insert %d\n",val);
    Node * ptr = Node_Construct(val);
    ptr -> next = head;
    return ptr;
}