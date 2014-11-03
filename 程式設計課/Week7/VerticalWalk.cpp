#include <stdio.h>
#include <string.h>

void MakeVerticalWalk (int *array, int n1, int n2)
{
	int i, j, fillnum=1;
	memset(array,0,sizeof(n1*n2));
	for (i = 0; i < n2; i++)
	{
		for (j = 0; j < n1; j++)
			*(array+(j*n2)+i) = fillnum++;
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
	printf ("Enter rank: ");
	scanf ("%d", &rank);
	int array[rank][rank];
	MakeVerticalWalk((int*)array, rank, rank);
	PrintArray((int*)array, rank, rank);
	
	return 0;
}
