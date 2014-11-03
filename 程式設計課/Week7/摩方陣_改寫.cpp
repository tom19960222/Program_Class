#include <stdio.h> 
#define MAX 30 

int CrushProcess (int n, int height)
{
	if (n >= height)
		return n-height;
	else if (n < 0)
		return n+height;
	else
		return n;
}

void Magic (int magic[][MAX], int height)
{
	int posX, posY, fillnum;
	
	posX = height/2; posY = 0;
	magic[posX][posY] = 1;
	
	for (fillnum = 2; fillnum <= height*height; fillnum++)
	{
		if (magic[CrushProcess(posX+1, height)][CrushProcess(posY-1, height)] == 0)
			{
				magic[CrushProcess(posX+1, height)][CrushProcess(posY-1, height)] = fillnum;
				posX = CrushProcess(posX+1, height);
				posY = CrushProcess(posY-1, height);
			}
		else
			{
				posY = CrushProcess(posY+1, height);
				fillnum--;
			}
		
	}
}
 
void prarray (int magic[][MAX], int height)
{
	int posX, posY;
	for (posY = 0; posY < height; posY++)
		{
			for (posX = 0; posX < height; posX++)
				printf("%3d", magic[posX][posY]);
			putchar('\n');
		}
}

void ComputeSum (int magic[][MAX], int height)
{
	int posX, posY, sum;
	for (posX = 0; posX < height; posX++)
	{
		sum = 0;
		for (posY = 0; posY < height; posY++)
			sum += magic[posX][posY];
		printf ("Sum of magic[%d][*] = %d\n", posX, sum);
	}
	
	for (posY = 0; posY < height; posY++)
	{
		sum = 0;
		for (posX = 0; posX < height; posX++)
			sum += magic[posX][posY];
		printf ("Sum of magic[*][%d] = %d\n", posY, sum);
	}
}

int main(){
	int board[MAX][MAX]={0};
	int N;
	
	printf("Enter N: ");
	scanf("%d", &N);
	
	Magic(board, N);
	prarray(board, N);
	printf("\n\n");
	printf("Checking sum by calling CheckSum(b,N)\n");
	ComputeSum(board, N);

return 0;
}
