#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "tree.h"


Tnode * readfile(int * youtried, int * nodecount);
Tnode * Tinsert(Tnode * tn, int val);
static Tnode * Tconstruct(int val);
int isBST(Tnode* node);
int isBSTUtil(Tnode* node, int min, int max);
Tnode * nodedel(Tnode * tn, int val);

int main(int argc, char** argv) {

    printf("running...\n");
    
    Tnode * root = NULL;
    root = malloc(sizeof(Tnode));
    root->left = NULL;
    root-> right = NULL;
    
    int youtried = 0;
    int nodecount = 0;
    root = readfile(&youtried, &nodecount); //oh yeah its also gonna construct the tree and stuff
    int idealheight = log(nodecount) / log(2);
    printf("\n%d:%c\n",root->key,root->key);

    int checkBST = isBST(root);
    int checkbal = 0;
    
    
    printf("(%d,%d,%d)",youtried,checkBST,checkbal);
    return (EXIT_SUCCESS);
}

Tnode * readfile(int * youtried, int * nodecount)
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
        *youtried = 0;
        *nodecount = 0;
    } 
   
    
    Tnode * root = NULL;
    root = malloc(sizeof(Tnode));
    root->left = NULL;
    root-> right = NULL;
    
    int varcount = 0;
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
        if (readline[i-1] == 'i') //add the integer to the tree
            {
            varcount++;
            for (j =0; j < i; j++)
                {
                    //printf("%c",readline[j]);
                    sendarr[j] = readline[j];
                }
            sendarr[j+1] = 'x';
            sendint = atoi(sendarr);
            printf("\nstoring %d",sendint);
            Tinsert(root,sendint);
            }   
        if (readline[i-1] == 'd') //delete the integer from the tree
            {    
                varcount--;
                printf("\n  i is %d. delete %c\ndeleting:",i,readline[i]);
                for (j = 0; j < i; j++)
                    {
                        //printf("%c",readline[j]);
                        sendarr[j] = readline[j];
                    }
                sendarr[j+1] = 'x';
                sendint = atoi(sendarr);
                printf("deleting %d\n",sendint);
                nodedel(root,sendint);
            }
        fgets(readline,30,fptr); 
    }
    *nodecount = varcount;
    *youtried = 1;
    return root;
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

int isBST(Tnode* node)  
{  
  return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  

int isBSTUtil(Tnode* node, int min, int max)  
{  
  /* an empty tree is BST */
  if (node==NULL)  
     return 1; 
        
  /* false if this node violates the min/max constraint */  
  if (node->key < min || node->key > max)  
     return 0;  
  
  /* otherwise check the subtrees recursively,  
   tightening the min or max constraint */
  return 
    isBSTUtil(node->left, min, node->key-1) &&  // Allow only distinct values 
    isBSTUtil(node->right, node->key+1, max);  // Allow only distinct values 
}  

Tnode * nodedel(Tnode * tn, int val)
{
    if (tn == NULL)
    {
        return NULL;
    }
    if (val < (tn->key))
    {
        (tn -> left) = nodedel(tn -> left, val);
        return tn;
    }
    if (val > (tn->key))
    {
        (tn -> right) = nodedel(tn -> right, val);
        return tn;
    }
    //if the values are equivalent, test how many children it has
    if (((tn->left) == NULL)&&((tn->right) == NULL))
    {
        //no child
        //F
        free(tn);
        return NULL;
    }
    if ((tn -> left) == NULL) //only right child
    {
        Tnode * rc = tn -> right;
        free(tn);
        return rc;
    }
    if ((tn -> right) == NULL) //only left child
    {
        Tnode * lc = tn -> right;
        free(tn);
        return lc;
    }
    //if it's here, that means the node has 2 childrens
    Tnode * successor = (tn->right);
    while ((successor->left) != NULL)
    { //find immediate predecsesor
        successor = successor -> left;
    }
    (tn -> key) = (successor -> key);
    (successor -> key) = val;
    
    tn->right = nodedel(tn->right, val);
    return tn;
}