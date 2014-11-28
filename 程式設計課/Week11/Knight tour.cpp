#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {0};
int count[8][8] = {0};

int isTraveled (int x, int y)
{
	if (board[y][x] == 1)
		return 1;
	return 0;
}

int isReachable (int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8) 
	{
		if (isTraveled(x, y) == 0) return 1;
	}
	
	return 0;
}

int CountAvaliableWays (int x, int y)
{
	int checkpos_x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int checkpos_y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int i, AvaliableWays = 0;
	
	for (i = 0; i < 8; i++) 
	{
		if (isReachable(x+checkpos_x[i], y+checkpos_y[i]))
			AvaliableWays++;
	}
	
	return AvaliableWays;
}

void CountAvaliableWaysInMap ()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			count[i][j] = CountAvaliableWays (j, i);
	}
} 

void PrintBoard (int in[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf ("%2d", in[i][j]);
		printf ("\n");
	}
}

int main()
{
	int x, y;
	while (1)
	{
		CountAvaliableWaysInMap();
		printf("\n\n");
		PrintBoard(board);
		printf("\n\n");
		PrintBoard(count);
		printf("\n\n");
		
		printf ("Travel: ");
		scanf ("%d %d", &x, &y);
		board[y][x] = 1;
	}
	
	return 0;
} 
