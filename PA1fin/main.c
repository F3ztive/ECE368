#include <stdio.h>
#include <stdlib.h>

//long *Array_Load_From_File(char *filename, int *size);
//int Array_Save_To_File(char *filename, long *array, int size);
//void Array_Shellsort(long *array, int size, long *n comp);
typedef struct listnode {
    struct listnode * next;
    long value;
} Node;

Node * List_Load_From_File(char  * filename);
Node * List_Insert(Node * head, long val);
Node * Node_Construct(long val);
Node * List_Shellsort(Node *head, long k, long size);
void LLswap(Node * a, Node * b);
void printList( Node *start); 
int List_Save_To_File(char *filename, Node *list);
int determinesize(Node * head);
Node * ksender(long size, Node * head);


int main()
{
    long size  = 0;
    Node * head = NULL;
    head = List_Load_From_File("15.b");
    size = determinesize(head);
    printf("size is %ld",size);
    //printList(head) ;

    //printf("size is %d\n",size);
    int prevk;
    ksender(size, head);
    //int k = determinek(k, prevk, &head);
    //head = LLKsort(head, k, size);
    printf("\n||||||||||\n");
    
    
    //printList(head);
    size = List_Save_To_File("outputfile.txt", head);
    //printf("\nsize is %d",size);
    return 0;
}

Node * ksender(long size, Node * head)
{
    //size = 2147483646;
    long k = 1743392200;
    while (k > size)
    {
        k = (k - 1)/ 3;
        //printf("\n%ld",k);
    }
    while (k >0)
    {
        head = List_Shellsort(head, k, size);
        k = (k - 1)/ 3;
    }
}


Node * List_Shellsort(Node * head, long k, long size)
{ 
    //printf("\nk:%ld=",k);
    //printList(head);
    int ksneeded;
    if (k != 0)
    {
       ksneeded = size / k;
    }
    
    //printf("\n k's needed is: %d",ksneeded);
    
    Node * p1 = NULL;
    p1 = malloc(sizeof(Node));
    Node * p2 = NULL;
    p2 = malloc(sizeof(Node));
    
    for (int q = k; q < size; q = q + k)
    {
        for (int i = 0; i < k;i++)
        {
            p1 = head;
            //p2 = head;

            for (int p = i;p<k;p++)
            {
                p1 = p1->next;
            }
            p2 = p1;
            for (int j = 0; j < ksneeded;j++)
            {
                for (int m = 0; m < k; m++)
                {
                    if ((p2->next) == NULL)
                        p2 == NULL;
                    else
                        p2 = p2->next;
                }

                //printf("\n%d:%d",p1->value,p2->value);

                if ((p1->value) > (p2->value))
                {
                    //printf("!");
                    LLswap(p1, p2);
                }
                p1 = p2;
            }
        }
    }
    /*for (int x = 0; x < size;   )
    {
    p1 = head;
    p2 = head;
        x = x + k;
        for (int i = 0; i < ksneeded; i++) //repeat for the necessary number for k
        {
            //printf(".");
            for (int j = 0; j < k; j++)
            {
                //printf(",");
                if (p2->next != NULL)
                    p2 = p2->next;
                //else
                    //printf("\np2 bonk");
            }

            printf("\n%ld:%ld",p1->value,p2->value);
            if ((p1->value) > (p2->value))
            {
                printf("!");
                swap(p1, p2);
            }
            p1 = p2;
        }
    }
    
     printList(head);
    */
    return head;
}

/*int determinek(int k, int prevk, Node ** head)
{
    
    int size = 0;
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->value = 0;
    
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    
    int tpk = k;
    while (k<size)
    {
        prevk = k;
        k = 3*k+1;
        
        k = determinek(k,prevk,&head);     
    }
    if (tpk != k)
    {
        //printf("\nK:%d, PK:%d, tpk:%d",k,prevk,tpk);
        head = LLKsort(head, prevk, size);
        return k;
    }
    return k;
}
*/

Node * List_Load_From_File(char * filename) //read file and store list from file
{
    long buffer;
    FILE * fptr;
    fptr = fopen("15.b", "rb");
    int readint = 0;
    fread(&buffer,sizeof(buffer),1,fptr);    
    
    Node * HEAD = NULL;
    HEAD = malloc(sizeof(Node));
    HEAD->next = NULL;
    HEAD->value = 0;
    
    if (fptr == NULL)
    {
        printf("Can't read file :(\n");
        return HEAD;
    } 
    
    
    //get file size
    fseek (fptr , 0 , SEEK_END);
    int size = ftell(fptr);
    rewind (fptr);
    size = size/sizeof(long);
    //printf("size is %d",size);
    
    /*
    buffer = (char*) malloc (sizeof(char)*size);
    if (buffer == NULL) 
    {
        printf("mem error");
    }*/
    

    
    for (int i = 0; i < size; i++)
    {
        //printf("%ld",buffer);
        HEAD = List_Insert(HEAD,buffer);
        fread(&buffer,sizeof(buffer),1,fptr);       
    }
    
    fclose(fptr);
    
    return HEAD;
}

Node * Node_Construct(long val)
{
    Node * nd = malloc(sizeof(Node));
    nd -> value = val;
    nd -> next = NULL;
    return nd;
}

Node * List_Insert(Node * head, long val)
{
    //printf("insert %ld\n",val);
    Node * ptr = Node_Construct(val);
    ptr -> next = head;
    return ptr;
}

int determinesize(Node * head)
{
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->value = 0;
    temp = head;
    
    int size = -1;
    
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

int List_Save_To_File(char *filename, Node *list)
{
    FILE *fd = fopen(filename, "w");
    int size = 0;
    
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->value = 0;
    temp = list; 
    
    while (temp!=NULL) 
    { 
       printf(".");
       fprintf(fd, "%li\n", temp->value);
       temp = temp->next;
       //fputc(writechar,fptr); 
       size++;
    }     
    fclose(fd);
    return (size-1); //since the loop increments one time too many
}

void printList( Node *start) 
{ 
	Node *temp = start; 
	//printf("\n"); 
	while (temp!=NULL) 
	{ 
            //printf("%ld ", temp->value); 
            temp = temp->next; 
	} 
} 

void LLswap(Node *a, Node *b) 
{ 
    long temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
}