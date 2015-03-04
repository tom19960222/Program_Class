/*
    Author: Chun-Yu Shih
	Date: 2014/11/4 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void MakeRandomWalk (int *array, int n1, int n2)
{
	int i, randnum, fillnum=1;
	memset(array,0,n1*n2*sizeof(int)); //Set the array to zero. 
	for (i = 1; i <= n1*n2; i++)
	{
		randnum = rand()%(n1*n2); // Generate the number of element.
		if ( *(array+randnum) == 0) //If the value is zero, set it to fillnum.
			*(array+randnum) = i;
		else // If the value is not zero, redo the loop.
			i--;  
	}
}

void PrintArray (int *array, int n1, int n2)
{
	int i;
	for (i = 1; i <= n1*n2; i++)
	{
		printf ("%3d", *array);
		array++;
		if (i % n1 == 0) putchar('\n');  
	}
}

int main()
{
	int rank, *array;
	srand(time(NULL));
	//printf ("Enter rank: ");
	//scanf ("%d", &rank);
	//int array[rank][rank];
	rank=700;
	array = (int*)malloc (sizeof(int) * rank * rank);
	MakeRandomWalk(array, rank, rank);
	//PrintArray(array, rank, rank);
	
	return 0;
}
