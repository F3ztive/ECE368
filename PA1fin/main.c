#include <stdio.h>
#include <stdlib.h>



typedef struct listnode {
    struct listnode * next;
    long value;
} Node;

long *Array_Load_From_File(char *filename, int *size);
int Array_Save_To_File(char *filename, long *array, int size);
void Array_Shellsort(long *array, int size, long *n_comp);


Node * List_Load_From_File(char  * filename);
Node * List_Insert(Node * head, long val);
Node * Node_Construct(long val);
Node * Old_List_Shellsort(Node *head, long k, long size);
void LLswap(Node * a, Node * b);
void printList( Node *start); 
int List_Save_To_File(char *filename, Node *list);
int determinesize(Node * head);
Node * ksender(long size, Node * head);
Node * List_Shellsort(Node *list, long *n_comp);
Node * cleanlist(Node * head, long val);
int determinek(long size);
void  destroylist(Node * head);

long main()
{
    long size = 0;
    long n_comp = 0;
    //array stuff
    
    /*
    
    long *array;
    
    {
      array = Array_Load_From_File("15.b", &size);
      if (array == NULL)
        {
	  return EXIT_FAILURE;
	}
    if (size != 0)
	{
	  Array_Shellsort(array, size, &n_comp);
	  printf("\n%ld\n", n_comp);
	  Array_Save_To_File("savefile.b", array, size);
	  free(array);
	}
      else
	{
	  Array_Save_To_File("savefile.b", NULL, 0);
	  free(array);
	}
     } //array
     */
    
    //Linked List
    
    Node * head = NULL;
    Node * sorted = NULL;
    
    head = List_Load_From_File("15.b");
    size = determinesize(head);
    printf("size is %ld",size);
    //printList(head);
    
    int prevk;
    //
    printf("\n||||||||||\n");
    //head = Old_List_Shellsort(head, n_comp);
    
    sorted = List_Shellsort(head, &n_comp);
    printf("\n NCOMP IS %ld",n_comp);
    //printList(sorted);
    //destroylist(head);
    destroylist(sorted);
    //size = List_Save_To_File(argv[3], head);
    //printf("\nsize is %d",size);
  return 0;
}



//LL
void destroylist(Node * head)
{
    while (head != NULL)
    {
        Node * p = head->next;
        free(head);
        head = p;
    }
}

Node * cleanlist(Node * head, long val) //ended up using for deleting any node
{
    printf("deleting %ld",val);
    Node * p = head;
    if (p == NULL)
    {
        return p; //do nothing
    }
    
    if ((p->value) == val) //if its the head node
    {
        p = p->next;
        free (head);
        return p;
    }
    
    Node * q = p->next;
    while ((q!= NULL) && ((q -> value) != val))
    {
        p = p-> next;
        q = q->next;
    }
    if (q != NULL)
    {
        p->next = q->next; //delete the node whose value is null
        free(q);
    }
    return head;
}

Node * List_Shellsort(Node * list, long *n_comp)
{
    long ZeRo = 0;
    int ksneeded = 0;
    
    list = cleanlist(list,ZeRo); //the list for whatever reason adds an extra 0 at the end. This is how i fix it.
    long size = determinesize(list);
    int k = determinek(size);
    //printf("\n!!k  is %d!!\n",k);
    

    Node * p1 = NULL;
    p1 = malloc(sizeof(Node));
    Node * p2 = NULL;
    p2 = malloc(sizeof(Node));
    
    while (k>0)
    {
        ksneeded = size / k;
        //    printf("\nksneeded is %ld",ksneeded);
        for (int q = k; q < size; q = q + k)
        {
            for (int i = 0; i < k;i++)
            {
                p1 = list;
                for (int p = i;p<k;p++)
                {
                    p1 = p1->next;
                }
                p2 = p1;
                for (int j = 0; j < ksneeded;j++)
                {
                    for (int m = 0; m < k; m++)
                    {
                        (*n_comp)++;
                        if ((p2->next) == NULL)
                            p2 == NULL;
                        else
                            p2 = p2->next;
                    }
                    if ((p1->value) > (p2->value))
                    {
                        LLswap(p1, p2);
                        
                    }
                    p1 = p2;
                }
            }
        }    
    k = (k - 1) / 3;
    }
    //printList(list);
    return list; 
}

int determinek(long size)
{
  int n = 1;
  //find last number in sequence
  while (n < size)
    {
      n = (n * 3) + 1;
    }
  n = (n - 1) / 3;
  return n;
}

Node * ksender(long size, Node * head) //old method of sorting lol
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
        //head = Old_List_Shellsort(head, k, size);
        k = (k - 1)/ 3;
    }
}

Node * Old_List_Shellsort(Node * head, long k, long size)
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
                if ((p1->value) > (p2->value))
                {
                    LLswap(p1, p2);
                }
                p1 = p2;
            }
        }
    }
    return head;
}

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
	while (temp!=NULL) 
	{ 
            printf("\n%ld ", temp->value); 
            temp = temp->next; 
	} 
} 

void LLswap(Node *a, Node *b) 
{ 
    long temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
}







//array 
long *Array_Load_From_File(char *filename, int *size)
{
  long *array;
  FILE *fptr = fopen(filename, "r");
  
  if (fptr == NULL)
    {
      size = 0;
      return NULL;
    }
  
  fseek(fptr, 0, SEEK_END);
  *size = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  array = malloc(*size * sizeof(long));
  if (array == NULL)
    {
      size = 0;
      return NULL;
    }
  
  for (int i = 0; i < *size / 8; i++)
    {
      fread(array, *size, 1, fptr);
    }
  fclose(fptr);
  return array;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
  int num = 0;
  FILE *fptr = fopen(filename, "w");

  num = fwrite(array, sizeof(array), size / 8, fptr);
  printf("\n");
  fclose(fptr);
  return num;
}

int sequence(int arrsize)
{
  int n = 1;
  
  //find last number in sequence
  while (n < arrsize)
    {
      n = (n * 3) + 1;
    }
  return n;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
  int temp;
  int i;
  int j;
  
  int arrsize = size/sizeof(array[0]); //find array size
  int seq = sequence(arrsize); //generate sequence
  //sort subarray sequence
  while (seq != 1)
    {
      for (j = seq; j < arrsize; j++)
	{
	  temp = array[j];
	  i = j;
	  while ((i >= seq) && (array[i-seq] > temp))
	    {
	      array[i] = array[i - seq];
	      i = i - seq;
	      (*n_comp)++;
	    }
	  (*n_comp)++;
	  array[i] = temp;
	}
      seq = (seq - 1) / 3;
    }

  //sort one last time
  for (j = 1; j < arrsize; j++)
    {
      temp = array[j];
      i = j;
      while ((i >= 1) && (array[i-1] > temp))
	{
	  array[i] = array[i - 1];
	  i = i - 1;
	  (*n_comp)++;
        }
      (*n_comp)++;
      array[i] = temp;
    }
}