#include "pa09.h"
#include <stdio.h>
#include <stdlib.h>


// This function checks if the file is bit-based or char-based. 
//If function returns 1 then file is bit-based or if it returns 0 then file is char-based
int checkBitCh(FILE * fptr)
{
    int val;
    int flag = 0;
    char ch;
    int i;
    for(i=0;i<10;i++)
    {
	ch = fgetc(fptr); // This gets only one character in a file at a time.
	val = (int)ch;
	if(val < 32 || val > 126) // This statement checks if the character in the output file are bit-based or char-based
	{
	    flag = 1;
	    break;
	}
    }
    
    return flag;
}

// This function inserts a new node in the stack.
Stack *Stack_push(Stack *head,HuffNode *node)
{
   Stack *item = malloc(sizeof(List)); // This allocates the dynamic memory to the List type pointer.
   if(item == NULL)
   {
     return NULL;
   }
   item->node = node;
   item->next = head;
   return item;
}

// This function pops or free(deallocate) the node in a Stack.
Stack *Stack_pop(Stack *head)
{
  if(head == NULL) // This checks whether the head is NULL or not, if it is then it will return NULL.
  {
    return NULL;
  }
  Stack *item = NULL;
  item = head->next;
  free(head);// This deallocates the allocated head.
  return item;
}

//This function creates a first node of a tree
HuffNode * HuffNode_create(int val)
{
  HuffNode * tn = malloc(sizeof(HuffNode));
  tn -> value = val;
  tn -> left = NULL;
  tn -> righ = NULL;
  return tn;
}

//This function destroys all the allocated memory.
void Huff_destroyTree(HuffNode *tree);
{
    if(tree == NULL)
    {
	return;
    }
    Huff_destroyTree(tree->left);
    Huff_destroyTree(tree->right);
    free(tree);
}


HuffNode *Huff_CharRead(char filename)
{
    int command = 0;
    FILE *fptr = NULL;
    fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
	return NULL;
    }
    
    Stack *st = NULL;
    while((command=fgetc(fptr)) != EOF)
    {
	command = fgetc(fptr);
	if(command == 1)
	{
	    HuffNode *leaf = HuffNode_create(int command);
	    st =  Stack_push(st,leaf);
	}
	if(command == 0)
	{
	    HuffNode * A = st -> tn;
	    st = Stack_pop(st);
	    if (st == NULL)
	    {
		return A;
	    }
	    else
	    {
		TreeNode * B = st -> tn;
		st = Stack_pop(st);
		TreeNode * par = malloc(sizeof(TreeNode));
		par -> value = ' '; // doesn't matter
		par -> right = A;
		par -> left = B;
		st = Stack_push(st, par);
	    }
	}
    }   
}


//This function prints the output 
void Huff_postOrderPrint(HuffNode *tree)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }

    // Recursive case: post-order traversal

    // Visit left
    printf("Left\n");
    Huff_postOrderPrint(tree->left);
	printf("Back\n");
    // Visit right
    printf("Right\n");
    Huff_postOrderPrint(tree->right);
	printf("Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
		printf("Leaf: %c\n", tree->value);
    }
    

}