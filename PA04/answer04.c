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

void partIncHelp(int *arr, int ind, int value)
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    for(lcv = 1;lcv <= value;lcv++)
    {
	if((ind == 0) || (arr[ind-1] < lcv))
	{
	    arr[ind] = lcv;
	    partIncHelp(arr,ind+1,value-lcv); 
	}
    }
}
void partitionIncreasing(int value)
{
    printf("partitionIncreasing %d\n", value);
    int *arr;
    
    arr = malloc(sizeof(int)*value);
    partIncHelp(arr,0,value);
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

void partDecHelp(int *arr, int ind, int value)
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    
    for(lcv = value;lcv > 0;lcv--)
    {
	if((ind == 0) || (arr[ind-1] > lcv))
	{
	    arr[ind] = lcv;
	    partDecHelp(arr,ind+1,value-lcv); 
	}
    }
    
}
void partitionDecreasing(int value)
{
    printf("partitionDecreasing %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
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
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    for(lcv = 1;lcv <= value;lcv+=2)
    {
	arr[ind] = lcv;
	partOddHelp(arr,ind+1,value-lcv);
    }
}
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
    
void partEvenHelp(int *arr,int ind,int value)
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    for(lcv = 2;lcv <= value;lcv+=2)
    {
	arr[ind] = lcv;
	partEvenHelp(arr,ind+1,value-lcv);
    }
}

void partitionEven(int value)
{
    printf("partitionEven %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
    partEvenHelp(arr,0,value);
    free(arr);

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
void partOddEvenHelp(int *arr,int ind,int value)
{
    int lcv;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    if(ind%2 == 0)
    {
	for(lcv = 1;lcv <= value;lcv+=2)
	{
	    arr[ind] = lcv;
	    //printf("ODD\n");
	    partOddEvenHelp(arr,ind+1,value-lcv);
	}
    }
    else if(ind%2 == 1)
    {
	for(lcv = 2;lcv <= value;lcv+=2)
	{
	    arr[ind] = lcv;
	    //printf("EVEN\n");
	    partOddEvenHelp(arr,ind+1,value-lcv);
	}
    }
     
}
void partitionOddAndEven(int value)
{
    printf("partitionOddAndEven %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
    partOddEvenHelp(arr,0,value);
    free(arr);
    
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


int primeCheck(int value)
{
    int i;
    if(value<=1)
    {
      return 0;
    }
    for(i=2;i<=value-1;i++)
    {
	if(value%i == 0)
	{
	    return 0;
	}
    }
    return 1;
}

void primeHelp(int *arr,int ind,int value)
{
    int lcv;
    int flag;
    if(value <= 0)
    {
	printPartition(arr,ind);
	return;
    }
    
    for(lcv = 0;lcv <= value;lcv++)
    {
	if(lcv != 2)
	{
	    flag = primeCheck(lcv);
	}
	else
	{
	    flag =1;
	}
	if(flag == 1)
	{
	    arr[ind] = lcv;
	    primeHelp(arr,ind+1,value-lcv);
	}
    }
}
void partitionPrime(int value)
{
    printf("partitionPrime %d\n", value);
    int *arr;
    arr = malloc(sizeof(int)*value);
    primeHelp(arr,0,value);
    free(arr);
}
