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
void printList( Node *start); 


int main()
{
    int size  = 0;
    Node * head = NULL;
    head = readfile(&size);
    printList(head) ;

    //printf("size is %d\n",size);
    int prevk;
    int k = determinek(41, 1, prevk);
    //head = LLKsort(head, k, size);
    printList(head);
    return 0;
}

void printList( Node *start) 
{ 
	Node *temp = start; 
	printf("\n"); 
	while (temp!=NULL) 
	{ 
		printf("%d ", temp->value); 
		temp = temp->next; 
	} 
} 

void swap(Node *a, Node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
}

Node * LLKsort(Node *head, int k, int size)
{
    int ksneeded = k / size;
    printf("\n k's needed is: %d",ksneeded);
    
    Node * p1 = NULL;
    p1 = malloc(sizeof(Node));
    Node * p2 = NULL;
    p2 = malloc(sizeof(Node));
    
    p1 = head;
    p2 = head;

    for (int i = 0; i < ksneeded; i++) //k sort
    {
        printf(".");
        for (int j = 0; j < k; j++)
        {
            printf(",");
            if (p2->next != NULL)
                p2 = p2->next;
            else
                printf("\np2 bonk");
        }
        
        printf("\n%d:%d",p1->value,p2->value);
        if ((p1->value) < (p2->value))
        {
            printf("!");
            swap(p1, p2);
        }
        p1 = p2;
    }
    return head;
}



int determinek(int size, int k, int prevk)
{
    int tpk = k;
    int i = 0;
    while (k<size)
    {
        prevk = k;
        k = 3*k+1;
        k = determinek(size,k,prevk);     
    }
    if (tpk != k)
    {
        printf("\nK:%d, PK:%d, tpk:%d, i:%d",k,prevk,tpk,i);
        return k;
    }
    return k;
}
Node * readfile(int * size) //read file and store list from file
{
    FILE * fptr;
    fptr = fopen("10simp.txt", "r");
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
    
    fclose(fptr);
    
    return HEAD;
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