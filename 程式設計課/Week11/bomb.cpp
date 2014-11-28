#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_MAX 20

void swap (int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void PrintBomb (int bomb[SIZE_MAX][SIZE_MAX], int size, int BombCount[SIZE_MAX][SIZE_MAX])
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf ("%2d", bomb[i][j]);
		printf ("\n");
	}
	printf ("\n");
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (BombCount[i][j] == -1)
				printf (" X");
			else
				printf ("%2d", BombCount[i][j]);
		}
		printf ("\n");
	}
		
}

void GenBomb (int bomb[SIZE_MAX][SIZE_MAX], int size, int count)
{
	int i, j, randX, randY;
	for (i = 0; i < count; i++)
	{
		randX = rand() % size;
		randY = rand() % size;
		if (bomb[randX][randY] == 0)
			bomb[randX][randY] = 1;
		else
			{  i--;  continue;	}
	}
}

int CountBomb (int x, int y, int bomb[SIZE_MAX][SIZE_MAX], int size) //Count the number of bombs on the position we gave
{
	int result = 0;
	int onLeftBorder, onRightBorder, onUpBorder, onDownBorder;
	onLeftBorder = onRightBorder = onUpBorder = onDownBorder = 0;
	
	if (y-1 < 0) onUpBorder = 1;
	if (y+1 == size) onDownBorder = 1;
	if (x-1 < 0) onLeftBorder = 1;
	if (x+1 == size) onRightBorder = 1;
	
	if (!onLeftBorder && !onUpBorder && bomb[y-1][x-1]) result++;
	if (!onUpBorder && bomb[y-1][x]) result++;
	if (!onRightBorder && !onUpBorder && bomb[y-1][x+1]) result++;
	if (!onLeftBorder && bomb[y][x-1]) result++;
	if (!onRightBorder && bomb[y][x+1]) result++;
	if (!onLeftBorder && !onDownBorder && bomb[y+1][x-1]) result++;
	if (!onDownBorder && bomb[y+1][x]) result++;
	if (!onRightBorder && !onDownBorder && bomb[y+1][x+1]) result++;
	
	return result;
}

void CountBomb_Map (int bomb[SIZE_MAX][SIZE_MAX], int BombCount[SIZE_MAX][SIZE_MAX], int size) //Count the whole map 
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (bomb[i][j] != 1)
				BombCount[i][j] = CountBomb(j, i, bomb, size);
			else
				BombCount[i][j] = -1;
		}
	}
}

int main()
{
	int bomb[SIZE_MAX][SIZE_MAX] = {0};
	int BombCount[SIZE_MAX][SIZE_MAX] = {0};
	int size, NumberofBombs;
	srand(time(NULL));
	
start:	
	printf ("Please input the size of the map: ");
	scanf ("%d", &size);
	printf ("Please input the amount of the bomb: ");
	scanf ("%d", &NumberofBombs);
	if (NumberofBombs > size*size)
		{  printf ("The amount of bombs cannot more than the size of map!\n\n");  goto start;  }
	printf ("\n");
	
	GenBomb(bomb, size, NumberofBombs);	
	CountBomb_Map (bomb, BombCount, size);
	PrintBomb(bomb, size, BombCount);
	
	return 0;
}
