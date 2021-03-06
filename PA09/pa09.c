
#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"


int main(int argc, char ** argv)
{
    
    //Check arguments
    if(argc != 3)
    {
	printf("incomplete arguments");
	return EXIT_FAILURE;
    }
    
    //initializing input file
    FILE * fptr = NULL;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
	printf("File error!\n");
	return EXIT_FAILURE;
    }
    
    int flag;
    HuffNode *tree = NULL;
    flag = checkBitCh(fptr);
    
    //Reading file and creating huffman tree
    if(flag == 0) //input file is char based
    {
	tree = Huff_CharRead(argv[1]);
    }
    
    else//input file is bit-based
    {
	tree = Huff_BitRead(argv[1]);
    }
    
    fclose(fptr);
    
    //writing the output
    fptr = fopen(argv[2], "w");
    if (fptr == NULL)
    {
	printf("File error!\n");
	return EXIT_FAILURE;
    }
    
    //This function prints the output on the output file
    Huff_postOrderPrint(tree,fptr);
    
    //This destroys the allocated memory
    Huff_destroyTree(tree);
    
    
    fclose(fptr);
    return EXIT_SUCCESS;
}