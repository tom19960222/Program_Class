#include <stdio.h>
#define SIZE 30
#define UP    1
#define RIGHT 2
#define DOWN  3
#define LEFT  4
#define X_IS_OUTOFRANGE 1
#define Y_IS_OUTOFRANGE 2

typedef struct {
	int x, y;
} point;

int square[SIZE][SIZE] = {0};
int FillInNum = 2, size;
point pos = {0, 0};

void PrintSquare()
{
	int i, j;
	printf ("\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf ("%3d", square[i][j]);
		printf ("\n");
	}
}

int isOutofRange (point PosNow, int size)
{
	if (PosNow.x < 0 || PosNow.x >= size)
		return X_IS_OUTOFRANGE;
	else if (PosNow.y < 0 || PosNow.y >= size)
		return Y_IS_OUTOFRANGE;
	else
		return 0;
}

void FillUntilEnd (int direction)
{
	switch(direction)
	{
		case RIGHT:
			while (1)
			{
				pos.x++;
				if (!isOutofRange(pos, size))
				{
					if (square[pos.y][pos.x] == 0)
						square[pos.y][pos.x] = FillInNum++;
					else {	pos.x--; break;}
				}
				else {	pos.x--; break;}
			}
			break;
			 
		case DOWN:
			while (1)
			{
				pos.y++;
				if (!isOutofRange(pos, size))
				{
					if (square[pos.y][pos.x] == 0)
						square[pos.y][pos.x] = FillInNum++;
					else {	pos.y--; break;}
				}
				else {	pos.y--; break;}
			}
			break;
			
		case LEFT:
			while (1)
			{
				pos.x--;
				if (!isOutofRange(pos, size))
				{
					if (square[pos.y][pos.x] == 0)
						square[pos.y][pos.x] = FillInNum++;
					else {	pos.x++; break;}
				}
				else {	pos.x++; break;}
			}
			break;
			
		case UP:
			while (1)
			{
				pos.y--;
				if (!isOutofRange(pos, size))
				{
					if (square[pos.y][pos.x] == 0)
						square[pos.y][pos.x] = FillInNum++;
					else { pos.y++; break; } 
				}
				else {	pos.y++; break;}
			}
			break;
	}
}

int main()
{
	size = 7;
	square[0][0] = 1;
	
	while (FillInNum <= size*size)
	{
		FillUntilEnd (RIGHT);
		FillUntilEnd (DOWN);
		FillUntilEnd (LEFT);
		FillUntilEnd (UP);
	}
	PrintSquare();
	return 0;
}
