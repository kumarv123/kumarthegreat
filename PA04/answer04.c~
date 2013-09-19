/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */


void printPartition(int *arr,int length)
{
    int ind;
    printf("= ");
    for(ind = 0;ind < length-1;ind++)
    {
	printf("%d + ",arr[ind]);
    }
    printf("%d\n",arr[length-1]);
    
}
void partHelp(int *arr, int ind, int value)
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    for(lcv = 1;lcv <= value;lcv++)
    {
	arr[ind] = lcv;
	partHelp(arr,ind+1,value-lcv);
    }
    
}
void partitionAll(int value)
{
    printf("partitionAll %d\n", value);
    int *arr;
    
    arr = malloc(sizeof(int)*value);
    partHelp(arr,0,value);
    free(arr);
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void printIncreasing(int *arr,int length,int value)
{
    int lcv;
    int flag;
    for(lcv=0;lcv+1<length;lcv++)
    {
	if(arr[lcv] < arr[lcv+1])
	{
	    flag = 1;
	}
	else
	{
	    return;
	}
    }
    if(flag == 1)
    {
	printf("= ");
	for(lcv = 0;lcv < length-1;lcv++)
	{
	    printf("%d + ",arr[lcv]);
	}
	printf("%d\n",arr[length-1]);
    }
}
void partIncHelp(int *arr, int ind, int value)
{
    int lcv;
    if(value <= 0)
    {
	printIncreasing(arr,ind,value);
	//printf("= %d\n",arr[ind-1] = value);
	return;
    }
    
    for(lcv = 1;lcv <= value;lcv++)
    {
	arr[ind] = lcv;
	partIncHelp(arr,ind+1,value-lcv);
    }
    
}
void partitionIncreasing(int value)
{
    printf("partitionIncreasing %d\n", value);
    int *arr;
    
    arr = malloc(sizeof(int)*value);
    partIncHelp(arr,0,value);
    arr[0] = value;
    printf("= %d\n",arr[0]);
    free(arr);

}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void printDecreasing(int *arr,int length)
{
    int lcv;
    int flag;
    for(lcv=0;lcv+1<length;lcv++)
    {
	if(arr[lcv] > arr[lcv+1])
	{
	    flag = 1;
	}
	else
	{
	    return;
	}
    }
    if(flag == 1)
    {
	printf("= ");
	for(lcv = 0;lcv < length-1;lcv++)
	{
	    printf("%d + ",arr[lcv]);
	}
	printf("%d\n",arr[length-1]);
    }
}
void partDecHelp(int *arr, int ind, int value)
{
    int lcv;
    if(value <= 0)
    {
	printDecreasing(arr,ind);
	return;
    }
    
    for(lcv = 1;lcv <= value;lcv++)
    {
	arr[ind] = lcv;
	partDecHelp(arr,ind+1,value-lcv);
    }
    
}
void partitionDecreasing(int value)
{
    printf("partitionDecreasing %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
    arr[0] = value;
    printf("= %d\n",arr[0]);
    partDecHelp(arr,0,value);
    free(arr);

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partOddHelp(int *arr,int ind,int value)
void partitionOdd(int value)
{
    printf("partitionOdd %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
    //arr[0] = value;
    //printf("= %d\n",arr[0]);
    partOddHelp(arr,0,value);
    free(arr);

}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);

}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);

}
