#include <stdio.h>
#define SIZE 30
#define X_IS_OUTOFRANGE 1
#define Y_IS_OUTOFRANGE 2

int magic[SIZE][SIZE] = {0};

typedef struct {
	int x, y;
} point;

void PrintMagic (int size)
{
	int x, y;
	printf ("\n");
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
			printf ("%4d", magic[y][x]);
		printf ("\n\n");
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

point NextStep (point PosNow, int size)
{
	point Next = PosNow;
	Next.x--; Next.y -= 2;
	
	if (!isOutofRange(Next,size))
	{
		if (magic[Next.y][Next.x] == 0)
			return Next;
		else
		{
			Next.x++;
			Next.y++;
			return Next;		
		}
	}
	else
	{
		int x_isPlused = 0, y_isPlused = 0;
		if (isOutofRange(Next,size) == X_IS_OUTOFRANGE)
			{ Next.x += size; x_isPlused = 1; }
		if (isOutofRange(Next,size) == Y_IS_OUTOFRANGE)
			{ Next.y += size; y_isPlused = 1; }
			
		if (magic[Next.y][Next.x] == 0)
			return Next;
		else
		{
			Next.x++;
			Next.y++; //Next.y-2+1 == Next.y-1 (Moving up)
			if (x_isPlused) Next.x -= size;
			if (y_isPlused) Next.y -= size;
			return Next;		
		}
	} 	
}

int main()
{
	int size_in, FillInNumber;
	point Pos;
	
	printf ("Enter an odd integer: ");
	scanf ("%d", &size_in);
	
	Pos.x = size_in/2; Pos.y = size_in-1;
	magic[Pos.y][Pos.x] = 1;
	for (FillInNumber = 2; FillInNumber <= size_in*size_in; FillInNumber++)
	{
		Pos = NextStep(Pos, size_in);
		magic[Pos.y][Pos.x] = FillInNumber;
	}
	PrintMagic (size_in);
	return 0;
} 
