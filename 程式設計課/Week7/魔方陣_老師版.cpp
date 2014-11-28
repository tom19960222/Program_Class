#include <stdio.h> 
#define MAX 30 

void prchar (char ch, int n)
{
	while (n--)
		putchar(ch);
}

void Magic (int magic[][MAX], int height)
{
	int row=0, col=height/2, i;
	magic[row][col] = 1;
	
	for ( i = 2; i <= height*height; i++)
	{
		if (i % height == 1)
			row++;
		else
		{
			row = (row-1+height) % height;
			col = (col+1) % height;
		}
		magic[row][col] = i;
	}
	
}
 
void prarray (int magic[][MAX], int height)
{
int posX, posY, HoriSum, VertSum, TiltedSum=0;
	
	prchar('-', 5*height+1); putchar('\n');
	
	for (posY = 0; posY < height; posY++)
	{
		for (posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  }
		printf ("|\n");
	}
		
	prchar('-', 5*height+1); putchar('\n');
}

void ComputeSum (int magic[][MAX], int height)
{
	int posX, posY, HoriSum, VertSum, TiltedSum=0;
	
	for (posX = height-1; posX >= 0; posX--)
		TiltedSum += magic[posX][posX];
	
	prchar(' ', 5*height); prchar('-', 6); putchar('\n');
	prchar(' ', 5*height); printf("|%4d|\n",TiltedSum);
	prchar('-', 5*height+6); putchar('\n');
	
	for (posY = 0; posY < height; posY++)
	{
		for (HoriSum = posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  HoriSum += magic[posX][posY];  }
		
		printf ("|%4d|\n", HoriSum);
	}
		
	prchar('-', 5*height+6); putchar('\n');
	
	for (posX = 0; posX < height; posX++)
	{
		for(posY = 0; posY < height; posY++)
		{
			VertSum = 0;
			for (posX = 0; posX < height; posX++)
				VertSum += magic[posX][posY];
			printf ("|%4d", VertSum);
		}
	}
	
	for (TiltedSum = posX = 0; posX < height; posX++)
		TiltedSum += magic[posX][posX];
	printf ("|%4d|\n", TiltedSum);
	
	prchar('-', 5*height+6); putchar('\n');
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
