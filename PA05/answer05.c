#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
#define MAXIMUM_LENGTH 80

/*
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numInteger: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fscanf
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readInteger(char * filename, int * numInteger)
{
    FILE *fptr = NULL;
    int temp = 0;
    int count = 0;
    int ind = 0;
    int *arr;
    
    fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
	fclose(fptr);
	return NULL;
    }
    
    while(fscanf(fptr,"%d",&temp) == 1)
    {
	count++;
    }
    
    arr = malloc(sizeof(int) * count);
    fseek(fptr,0,SEEK_SET);
    
    while(fscanf(fptr,"%d",&temp) == 1)
    {
	arr[ind] = temp;
	ind++;
    }
    *numInteger = count;
    fclose(fptr);
    return arr;
}

/* ----------------------------------------------- */

/*
 * Read a file of strings. This is similar to readInteger. However,
 * each string is an array of characters. The function needs to
 * allocate memory for an array of strings, i.e., array of arrays of
 * characters. In other words, this is a two-dimensional array (thus,
 * char **).
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of strings (one
 * per line)
 * 
 * numString: pointer to store the number of strings in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of strings from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fgets. 
 * 
 * Remember that an array of strings is a two-dimensional array of
 * characters
 *
 * You do NOT know how many strings are in the file until you have
 * read it. Once you know how many strings there are, you can modify
 * the "numberOfStrings" variable. (Note that this is a pointer, not
 * an string) You must allocate memory to store the strings.
 * 
 * Once memory is allocated to store the strings, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read stringes is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of strings in the file.  For example, if
 * you write this
 *
 * char array[10000];
 * 
 *
 */

char * * readString(char * filename, int * numString)
{
    FILE *fptr = NULL;
    char **strArr;
    int numline = 0;
    int ind = 0;
    char buf[MAXIMUM_LENGTH];
    
    fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
	fclose(fptr);
	return NULL;
    }
    
    while(fgets(buf,MAXIMUM_LENGTH,fptr) != NULL)
    {
	numline++;
    }
    
    strArr = malloc(sizeof(char*) *numline);
    fseek(fptr,0,SEEK_SET);
    while(fgets(buf,MAXIMUM_LENGTH,fptr) != NULL)
    {
	strArr[ind] = malloc(sizeof(char)*(strlen(buf)+1));
	strcpy(strArr[ind],buf);
	ind++;
    }
    
    *numString = numline;
    fclose(fptr);
    return strArr;
}

/* ----------------------------------------------- */
/*
 * print an array of integers, one integer per line
 */
void printInteger(int * arrInteger, int numInteger)
{
    int ind;
    for(ind=0;ind<numInteger;ind++)
    {
	printf("%d\n", arrInteger[ind]);
    }
}

/* ----------------------------------------------- */
/*
 * print an array of strings, one string per line
 *
 * Hint: printf("%s" ... can print a string
 */
void printString(char * * arrString, int numString)
{
    int ind;
    for(ind=0;ind<numString;ind++)
    {
	printf("%s\n",arrString[ind]);
    }
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of integers
 */
void freeInteger(int * arrInteger, int numInteger)
{
    free(arrInteger);
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of strings
 *
 * Hint: an array of strings is a two-dimensional array of characters
 */
void freeString(char * * arrString, int numString)
{
    int ind;
    for(ind=0;ind<numString;ind++)
    {
	free(arrString[ind]);
    }
    free(arrString);
}

/* ----------------------------------------------- */
/*
 * Write integers to a file, one integer per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrInteger: an array of integers
 * numInteger: the number of integers 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %d
 *
 */

int saveInteger(char * filename, int * arrInteger, int numInteger)
{
    FILE *fptr = NULL;
    int ind;
    
    fptr = fopen(filename,"w");
    if(fptr == NULL)
    {
	fclose(fptr);
	return 0;
    }
    
    for(ind=0;ind<numInteger;ind++)
    {
	fprintf(fptr,"%d\n",arrInteger[ind]); 
    }
    fclose(fptr);
    return 1;
}

/* ----------------------------------------------- */
/*
 * Write strings to a file, one string per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrString: an array of strings
 * numString: the number of strings 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %s
 *
 */

int saveString(char * filename, char * * arrString, int numString)
{
    FILE *fptr = NULL;
    int ind;
    
    if(fptr == NULL)
    {
	fclose(fptr);
	return 0;
    }
    
    for(ind=0;ind<numString;ind++)
    {
	fprintf(fptr,"%s\n",arrString[ind]);
    }
    fclose(fptr);
    return 1;
}

/* ----------------------------------------------- */
/*
 * sort an arry of integers by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 */

int compint1(const void *p1,const void *p2)
{
    int *intp1 = (int *)p1;
    int *intp2 = (int *)p2;
    int intv1 = *intp1;
    int intv2 = *intp2;
    
    if(intv1 < intv2)
    {
	return -1;
    }
    if(intv1 == intv2)
    {
	return 0;
    }
    return 1;
}

void sortInteger(int * arrInteger, int numInteger)
{
    qsort(arrInteger,numInteger,sizeof(int),compint1);
}


/* ----------------------------------------------- */
/*
 * sort an arry of strings by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 * Hint: use strcmp in the comparison function
 *
 */


int compint2(const void *p1,const void *p2)
{
    char **strp1 = (char **)p1;
    char **strp2 = (char **)p2;
    char *strv1 = *strp1;
    char *strv2 = *strp2;
    
    return strcmp(strv1,strv2);
    
}

void sortString(char * * arrString, int numString)
{    
    qsort(arrString,numString,sizeof(char *),compint2);
}


