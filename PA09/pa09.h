#ifndef PA09_H
#define PA09_H

#include <stdio.h>

typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;


int checkBitCh(FILE * fptr);
HuffNode * Huff_CharRead(char * filename);
HuffNode * Huff_BitRead(char * filename);
HuffNode * HuffNode_create(int val);
Stack *Stack_pop(Stack *head);
Stack *Stack_push(Stack *head,HuffNode *node);
void Huff_destroyTree(HuffNode *tree);
void Huff_postOrderPrint(HuffNode *tree,FILE *fptr);

#endif

