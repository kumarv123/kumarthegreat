
#include "pa10.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/**
 * Returns a pointer to a new empty stack.
 */
Stack * Stack_create()
{
    Stack *st = malloc(sizeof(Stack));
    if(st == NULL)
    {
	return NULL;
    }
    
    st -> list = NULL;
    
    return st;;
}

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you _must_ free the entire contained linked-list.
 * Also, you must safely to _nothing_ if stack == NULL. 
 */
void Stack_destroy(Stack * stack)
{
    if(stack == NULL)
    {
	return;
    }
    ListNode *temp = NULL;
    while(stack->list != NULL)
    {
	temp = stack->list->next;
	free(stack->list);
	stack->list = temp;
    }
    free(stack);
    return;
}

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */
int Stack_isEmpty(Stack * stack)
{
    if(stack->list == NULL)
    {
	return TRUE;
    }
    return FALSE;
}

/**
 * Pop the front 'value' from the stack.
 *
 * More precisely, this function must do two things:
 * (1) Return the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 */
int Stack_pop(Stack * stack)
{
    int val;
    if(stack->list == NULL)
    {
	return 0;
    }
    val = stack->list->value;
    ListNode *temp = NULL;
    temp = stack->list->next;
    free(stack->list);
    stack->list = temp;
    return val;
}

/**
 * Push an 'value' onto the front of the stack.
 *
 * More precisely, this function must:
 * (1) Create a new ListNode with 'value' for it's value.
 * (2) Push that new ListNode onto the front of the stack's list.
 */
void Stack_push(Stack * stack, int value)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = stack->list;
    stack->list = node;
    return;
}

/**
 * Sort 'array' of length 'len' using Donald Knuth's "StackSort"
 *
 * To do this, you must implement the following pseudo-code:
 * (1) Maintain a 'write_index'. This is where you'll write values to
 *     as you sort them. It starts off as zero.
 * (2) Initialize an empty stack
 * (3) For each input value 'x':
 *     (3.a) While the stack is nonempty and 'x' is larger than the 
 *           front 'value' on the stack, pop 'value' and:
 *           (3.a.i) Write 'value' to array[write_index], and 
 *                   increment write_index.
 *     (3.b) Push x onto the stack.
 * (4) While the stack is nonempty, pop the front 'value' and follow
 *     step (3.a.i).
 *
 * The output should be a sorted array if, and only if, the array
 * is stack-sortable. You can find files full of stack-sortable and
 * stack-unsortable arrays in the 'expected' folder.
 */
void stackSort(int * array, int len)
{
    if(isStackSortable(array,len))
    {
	int ind;
	int write_index = 0;
	int value;
	Stack *stack = Stack_create();
	for(ind=0;ind<len;ind++)
	{
	    while((stack->list != NULL) && (array[ind] > stack->list->value))
	    {
		value = Stack_pop(stack);
		array[write_index] = value;
		write_index++;
	    }
	    Stack_push(stack,array[ind]);
	}
    
	while(stack->list != NULL)
	{
	    value = Stack_pop(stack);
	    array[write_index] = value;
	    write_index++;
	}
	//free(stack);
	Stack_destroy(stack);
    }
}

/**
 * Return TRUE (1) if the 'array' of length 'len' is stack-sortable.
 *
 * To do this you must:
 * (1) If 'len' is less than 3, return TRUE.
 * (2) Find the maximum value in 'array'.
 * (3) Partition array into two parts: left of max, and right of max.
 * (4) The maximum value in left must be smaller than the minimum
 *     value in right. (Otherwise return FALSE.)
 * (5) Return TRUE if both left and right are stack-sortable.
 *
 * The 'expected' directory contains files for all sortable and 
 * unsortable sequences of length len. You must return TRUE for every
 * sequence in the sortable files, and you must return FALSE for every
 * sequence in the unsortable files.
 */
int isStackSortable(int * array, int len)
{
    int f;
    int s;
    int ind;
    int max = 0;
    int maxind = 0;
    int leftmax = 0;
    int rightmin = 999999999;
    if(len < 3)
    {
	return TRUE;
    }

    for(ind=0;ind<len;ind++)
    {
	if(array[ind] > max)
	{
	    max = array[ind];
	    maxind = ind;
	}
    }
    for(ind =0;ind<maxind;ind++)
    {
	if(array[ind] > leftmax)
	{
	    leftmax = array[ind];
	}
    }
    
    for(ind =maxind+1;ind<len;ind++)
    {
	if(array[ind] < rightmin)
	{
	    rightmin = array[ind];
	}
    }
    
    if(leftmax > rightmin)
    {
      
	return FALSE;
    }

    f = isStackSortable(array,maxind);
    s = isStackSortable(&array[maxind+1],len-maxind-1);
    if(f == TRUE && s == TRUE)
    {
	return TRUE;
    }

    else
    {
	return FALSE;
    }
}

/**
 * Generates (and prints) all the unique binary tree shapes of size k
 *
 * To do this, you must:
 * (1) Create an array with the elements [0..k-1] inclusive.
 * (2) Find all the permutations of this array.
 * (3) In the base-case of your permute function, you must test if the
 *     permutation is "stack-sortable"
 * (4) If the permutation is "stack-sortable", then build a binary
 *     tree, and print it using the "Tree_printShape(...)" function.
 *
 * Your genShapes() function must NOT produce duplicate tree shapes.
 * The correct outputs for sizes [1..9] are in the 'expected' 
 * directory.
 */

static void swap ( int * a , int * b )
{
    int t = * a ;
    * a = * b ;
    * b = t ;
}

static void permuteHelper(int *array, int len, int ind)
{
    TreeNode *tree;
    if ( ind == len )
    {
	if(isStackSortable(array, len))
	{
	    tree = Tree_build(array,len);
	    Tree_printShape(tree);
	    Tree_destroy(tree);
	}
    }
    int pos ;
    for ( pos = ind ; pos < len ; pos ++)
    {
	swap (&array[pos] , &array[ind]); 
	permuteHelper ( array,len ,ind + 1);
	swap (&array[pos] , &array[ind]); 
    }
}

void permute( int *array , int len )
{
    permuteHelper ( array , len , 0);
}

void genShapes(int k)
{
    int ind;
    int *array = malloc(sizeof(int)*k);
    for(ind=0;ind<k;ind++)
    {
	array[ind] = ind;
    }
    permute(array,k); 
    free(array);
}