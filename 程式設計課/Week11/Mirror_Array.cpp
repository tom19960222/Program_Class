#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

int Normal[SIZE][SIZE] = {0};
int Mirror[SIZE][SIZE] = {0};

void GenerateSequenceArray(int size)
{
	int i, j, num = 1;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			Normal[i][j] = num++;
	}
}

void RandomizeArray(int size)
{
	int num, temp;
	int n1_x, n1_y, n2_x, n2_y;
	for (num = 0; num < size*size; num++)
	{
		n1_x = rand()%size;
		n1_y = rand()%size;
		n2_x = rand()%size;
		n2_y = rand()%size;
		
		temp = Normal[n1_y][n1_x];
		Normal[n1_y][n1_x] = Normal[n2_y][n2_x];
		Normal[n2_y][n2_x] = temp;
	}
}

void MirrorArray(int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = size-1; j >= 0; j--)
			Mirror[i][j] = Normal[i][size-j-1];
	}
}

void PrintArray(int array[][SIZE], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf ("%3d", array[i][j]);
		printf ("\n");
	}
}

int main()
{
	int size = 6;
	srand(time(NULL));
	
	GenerateSequenceArray(size);
	RandomizeArray(size);
	PrintArray(Normal, size);
	MirrorArray(size);
	printf ("\n");
	PrintArray(Mirror,size);
	return 0;
}
