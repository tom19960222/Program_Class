#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void MakeRandomWalk (int *array, int n1, int n2)
{
	int i, randnum, fillnum=1;
	memset(array,0,n1*n2*sizeof(int));
	for (i = 1; i <= n1*n2; i++)
	{
		randnum = rand()%(n1*n2);
		if ( *(array+randnum) == 0)
			*(array+randnum) = i;
		else
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
	int rank;
	srand(time(NULL));
	printf ("Enter rank: ");
	scanf ("%d", &rank);
	int array[rank][rank];
	MakeRandomWalk((int*)array, rank, rank);
	PrintArray((int*)array, rank, rank);
	
	return 0;
}
