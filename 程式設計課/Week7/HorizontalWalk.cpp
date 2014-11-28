#include <stdio.h>
#include <string.h>

void MakeHorizontalWalk (int *array, int n1, int n2)
{
	int i;
	memset(array,0,sizeof(n1*n2));
	for (i = 1; i <= n1*n2; i++)
	{
		*array = i;
		array++;
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
	MakeHorizontalWalk((int*)array, rank, rank);
	PrintArray((int*)array, rank, rank);
	
	return 0;
}
