#include <stdio.h>
#include <stdlib.h>

typedef struct _Tnode {
   int key;
   char balance;   
   struct _Tnode *left;
   struct _Tnode *right;
} Tnode;

int readfile();
Tnode * Tinsert(Tnode * tn, int val);
static Tnode * Tconstruct(int val);




int main(int argc, char** argv) {

    printf("running...\n");
    int youtried = 0;
    youtried = readfile();
    
    
    
    
    return (EXIT_SUCCESS);
}

int readfile()
{
    FILE * fptr;
    fptr = fopen("ops0.txt", "r");
    char readline[30];
    char sendarr[30];
    int sendint = 0;
    fgets(readline,30,fptr);
    
    
    if (fptr == NULL)
    {
        printf("Can't read file :(\n");
        return 0;
    } 
   
    
    Tnode * root = NULL;
    root = malloc(sizeof(Tnode));
    root->left = NULL;
    root-> right = NULL;
    
    printf("successful open\n");
    while (!feof(fptr))
    {
        int i = 0;
        int j;
        
        /* lines for testing line read success
        printf("line is: ");
        for (int k = 0; k < 30; k++)
        {
            printf("%c",readline[k]);
        }
        printf("\nEOL\n");*/
        
        //get the intiger to send to the tree
        
        while ((readline[i-1] != 'd') && (readline[i-1] != 'i')) //obtain the position of the letter after the number
        {
            i++;
        }
        if (readline[i] = 'i') //add the integer to the tree
            {
                //printf("i is %d. read %c\nstoring:",i,readline[i]);
                for (j =0; j < i; j++)
                {
                    //printf("%c",readline[j]);
                    sendarr[j] = readline[j];
                }
                sendarr[j+1] = 'x';
                sendint = atoi(sendarr);
                printf("send %d\n",sendint);
                Tinsert(root,sendint);
            }
        if (readline[i] = 'd') //delete the integer from the tree
        {
            //Tinsert(root,4);
        }
        fgets(readline,30,fptr); 
   }
    
    return 1;
}
//reading ops.b, ops1.b, ops2.b as inputs (equivalent text files included)

//fiel size is n*(sizeof(int)+sizeof(char))

Tnode * Tinsert(Tnode * tn, int val)
{
    if (tn == NULL)
    {
        return (Tconstruct(val));
    }
    if (val == tn->key)
    {
        return tn; //this is the thing youll have to go through later D:
    }
    if (val < (tn->key))
    {
        tn -> left = Tinsert(tn->left,val);
    }
    else
    {
        tn->right = Tinsert(tn->right, val);
    }
    return tn;
}

static Tnode * Tconstruct(int val)
{
    Tnode * tn;
    tn = malloc(sizeof(Tnode));
    tn->left = NULL;
    tn-> right = NULL;
    tn->key = val;
}