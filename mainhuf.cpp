#include <stdio.h> 
#include <stdlib.h> 
#define MAX_TREE_HT 100 
    
//Huffman tree node 
typedef struct MinHeapNode { 

	
	char data; // One of the input characters 

	
	unsigned freq; // Frequency of the character 

	
	struct MinHeapNode *left, *right; // Left and right child of this node 
}MinHeapNode; 

// A Min Heap: Collection of  min-heap (or Huffman tree) nodes 
typedef struct MinHeap { 

	
	unsigned size; // Current size of min heap 

	
	unsigned capacity; // capacity of min heap 

	
	struct MinHeapNode** array; // Array of minheap node pointers 
}MinHeap; 

typedef struct LLnode
{
    char title; //character received from file
    struct LLnode * next; //next LLnode in list
}LLnode;

LLnode *  CLL(void);
void sortunique(char * carr, char * uarr,int * farr,int n, int uniquesize) ;
void bubbleSort(int * farr,char * uniquearray, int n) ;
void charswap(char *xp, char *yp);
void swap(int *xp, int *yp);
int countDistinct(char arr[], int n);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) ;
void minHeapify(struct MinHeap* minHeap, int idx) ;
int isSizeOne(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) ;
void buildMinHeap(struct MinHeap* minHeap) ;
void printArr(int arr[], int n);
int isLeaf(struct MinHeapNode* root) ;
void printCodes(struct MinHeapNode* root, int arr[], int top, char data[],int freq[]) ;
void HuffmanCodes(char data[], int freq[], int size) ;
void swap(int *xp, int *yp) ;
void charswap(char *xp, char *yp) ;
int countDistinct(char arr[], int n) ;
MinHeapNode* newNode(char data, unsigned freq);
MinHeap* createMinHeap(unsigned capacity) ;
MinHeapNode* extractMin(struct MinHeap* minHeap);
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) ;
int countunique(char carr[], int n);
void createunique(char * carr, char * uarr,int uniquesize, int n);
void fetchlist(char * arr,LLnode * LLHEAD);
int sizeget(LLnode * LLHEAD);



int main() 
{ 
      
        //construct input as lonked list
        LLnode * LLHEAD = NULL;
        LLHEAD = CLL(); //creates the input as a linked list
    
        //Construct input as array
        int inputsize = sizeget(LLHEAD); //gets the input size
        char carr[inputsize];
        fetchlist(carr, LLHEAD); //array is now filled
        
        
        
        int countsize = sizeof(carr);
        int uniquesize = countunique(carr, countsize); //amount of unique characters in array
        char uarr[uniquesize];
        int farr[uniquesize]; //frequency arr
        int memsize = uniquesize / sizeof(uarr[0]);
        
        createunique(carr, uarr, uniquesize,countsize);
        sortunique(carr, uarr, farr, countsize, uniquesize);
        bubbleSort(farr, uarr, uniquesize) ;    
	HuffmanCodes(uarr, farr, memsize);
        return 0; 
} 

int sizeget(LLnode * LH) //gets the size of the linked list
{
    int size = 0;
    LLnode * p = LH;
    while(p->next!=NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

void fetchlist(char * carr, LLnode * LH) //stores LL to an array
{
    LLnode * p = LH;
    int i = 0;
    
    while(p->next!=NULL)
    {
        carr[i] = p->title;
        p = p->next;
        i++;        
    }
}

LLnode *  CLL()
{
    //read file
    FILE * fptr;
    char readline[30];
    fptr = fopen("gophers","r");
    
    //LLnode initializations
    LLnode * head = NULL;
    LLnode * t1 = NULL;
    LLnode * t2 = NULL;
    
    //start reading data
    fgets(readline,30,fptr);
    
    while(!feof(fptr)) //while not at the end of the file
    {
        t1 = (LLnode*)malloc(sizeof(LLnode)); //allocate memory for a new node
        t1 -> next = NULL; //give the new node a NULL child
        t1->title = readline[0];  //set the new node's title value to what is read from the file
        if (head == NULL) 
        {
            head = t1; //create 
        }
        else
        {
            t2 = head;
            while(t2->next != NULL)
            {
                t2 = t2->next;
            }
            t2->next = t1;
        }
        fgets(readline,30,fptr);
    }
    
            
    fclose(fptr);
    return head;
}

void sortunique(char * carr, char * uarr,int * farr, int n, int uniquesize) 
{
 //n is different sizes for unique array and main array
   int i = 0;
   int j = 0;
    for ( i = 0; i < uniquesize; i++)
    {
        farr[i] = 0; 
    }
   
    for (i = 0; i < uniquesize; i++)
    {
        
        for (j = 0; j<n; j++)
        {
            if (uarr[i] == carr[j])
            {
                farr[i] = ((farr[i]) + 1);
            }
        }
    }
}

void bubbleSort(int * farr,char * uniquearray, int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (farr[j] > farr[j+1]) 
           {
              swap(&farr[j], &farr[j+1]);  //////////
              charswap(&uniquearray[j], &uniquearray[j+1]); /////////
           }           
} 

void createunique(char * carr, char * uarr, int uniquesize, int n)
{
   int x = 0;
   int i = 0;
   int j = 0;
   
   for (i=0; i<n; i++) 
    { 
        for (j=0; j<i; j++) // Check if the picked element is already printed  
           if (carr[i] == carr[j]) 
               break; 
  
        // If not printed earlier, then print it 
        if (i == j) 
        {
        uarr[x] = carr[i];   
        x++;
        }
    } 
}

int countunique(char carr[], int n)
{
    int x = 0;
    int uniquesize = 0;
    int i = 0;
    int j = 0;
    for (i=0; i<n; i++) // Pick all elements one by one 
    { 
        for (j=0; j<i; j++) // Check if the picked element is already printed 
           if (carr[i] == carr[j]) 
           {
               break;
           }
        
        if (i == j) // If not printed earlier, then print it 
        {
            uniquesize++;    
            x++;
        }
    } 
    return uniquesize;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void charswap(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void printCodes(struct MinHeapNode* root, int arr[], int top, char data[],int freq[]) // Prints huffman codes from the root of Huffman Tree. 
{ 

	if (root->left) { 

		arr[top] = 0; 
		printCodes(root->left, arr, top + 1, data,freq); 
	} 
	if (root->right) { 

		arr[top] = 1; 
		printCodes(root->right, arr, top + 1, data,freq); 
	} 
	if (isLeaf(root)) { 

		printf("%c: ", root->data); 
                
		printArr(arr, top); 
	} 
       
        
        printf("_");
        

} 

void HuffmanCodes(char data[], int freq[], int size) 
{ 
	// Construct Huffman Tree 
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 

	// Print Huffman codes using 
	// the Huffman tree built above 
	int arr[MAX_TREE_HT], top = 0; 

	printCodes(root, arr, top,data,freq); 
       
} 

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) // A utility function to insert a new node to Min Heap 
{ 

	++minHeap->size; 
	int i = minHeap->size - 1; 

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 

		minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 

	minHeap->array[i] = minHeapNode; 
} 

void buildMinHeap(struct MinHeap* minHeap) 
{ 

	int n = minHeap->size - 1; 
	int i; 

	for (i = (n - 1) / 2; i >= 0; --i) 
		minHeapify(minHeap, i); 
} 

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
    printf("\n"); 
} 

int isLeaf(struct MinHeapNode* root) // Utility function to check if this node is leaf 
{ 

	return !(root->left) && !(root->right); 
} 

int countDistinct(char arr[], int n) 
{ 
    int res = 1; 
    for (int i = 1; i < n; i++) { 
        int j = 0; 
        for (j = 0; j < i; j++) 
            if (arr[i] == arr[j]) 
                break; 
        if (i == j) 
            res++; 
    } 
    return res; 
} 


int isSizeOne(struct MinHeap* minHeap) //check if size of heap is 1
{ 
	return (minHeap->size == 1); 
} 





void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) // A utility function to  swap two min heap nodes 
{ 

	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

void minHeapify(struct MinHeap* minHeap, int idx) // The standard minHeapify function. 
{ 

	int smallest = idx; 
	int left = 2 * idx + 1; 
	int right = 2 * idx + 2; 

	if (left < minHeap->size && minHeap->array[left]-> 
freq < minHeap->array[smallest]->freq) 
		smallest = left; 

	if (right < minHeap->size && minHeap->array[right]-> 
freq < minHeap->array[smallest]->freq) 
		smallest = right; 

	if (smallest != idx) { 
		swapMinHeapNode(&minHeap->array[smallest], 
						&minHeap->array[idx]); 
		minHeapify(minHeap, smallest); 
	} 
} 

// A utility function allocate a new min heap node with given character and frequency of the character 
MinHeapNode* newNode(char data, unsigned freq) 
{ 
	struct MinHeapNode* temp 
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode)); 

	temp->left = temp->right = NULL; 
	temp->data = data; 
	temp->freq = freq; 

	return temp; 
} 

// A utility function to create a min heap of given capacity 
MinHeap* createMinHeap(unsigned capacity) 
{ 

	struct MinHeap* minHeap 
		= (struct MinHeap*)malloc(sizeof(struct MinHeap)); 

	// current size is 0 
	minHeap->size = 0; 

	minHeap->capacity = capacity; 

	minHeap->array 
		= (struct MinHeapNode**)malloc(minHeap-> 
capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

MinHeapNode* extractMin(struct MinHeap* minHeap) // A standard function to extract minimum value node from heap 
{ 

	struct MinHeapNode* temp = minHeap->array[0]; 
	minHeap->array[0] 
		= minHeap->array[minHeap->size - 1]; 

	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return temp; 
} 

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) // Creates a min heap of capacity equal to size and inserts all character of data[] in min heap. Initially size of  min heap is equal to capacity 
{ 

	struct MinHeap* minHeap = createMinHeap(size); 

	for (int i = 0; i < size; ++i) 
		minHeap->array[i] = newNode(data[i], freq[i]); 

	minHeap->size = size; 
	buildMinHeap(minHeap); 

	return minHeap; 
} 

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{ 
	struct MinHeapNode *left, *right, *top; 

	// Step 1: Create a min heap of capacity 
	// equal to size. Initially, there are 
	// modes equal to size. 
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 

	// Iterate while size of heap doesn't become 1 
	while (!isSizeOne(minHeap)) { 

		// Step 2: Extract the two minimum 
		// freq items from min heap 
		left = extractMin(minHeap); 
		right = extractMin(minHeap); 

		// Step 3: Create a new internal 
		// node with frequency equal to the 
		// sum of the two nodes frequencies. 
		// Make the two extracted node as 
		// left and right children of this new node. 
		// Add this node to the min heap 
		// '$' is a special value for internal nodes, not used 
		top = newNode('$', left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		insertMinHeap(minHeap, top); 
	} 

	// Step 4: The remaining node is the 
	// root node and the tree is complete. 
	return extractMin(minHeap); 
} 