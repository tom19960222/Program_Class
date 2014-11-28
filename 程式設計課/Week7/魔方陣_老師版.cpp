#include <stdio.h> 
#define MAX 30 

void prchar (char ch, int n)  //putchar(ch) for n times. 
{
	while (n--)
		putchar(ch);
}

void Magic (int magic[][MAX], int height) //在陣列magic裡面產生魔方陣 沿用老師的演算法 
{
	int row=0, col=height/2, i;
	magic[row][col] = 1;
	
	for ( i = 2; i <= height*height; i++)
	{
		if (i % height == 1) //在同一列上繞一圈了 換下面一列 
			row++;
		else //還沒繞完一圈 往右上走一格 
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
	
	prchar('-', 5*height+1); putchar('\n');  //上面的框線 
	
	for (posY = 0; posY < height; posY++) // 印出數字+框線 
	{
		for (posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  }
		printf ("|\n");
	}
		
	prchar('-', 5*height+1); putchar('\n'); //下面的框線 
}

void ComputeSum (int magic[][MAX], int height)
{
	int posX, posY, HoriSum, VertSum, TiltedSum=0;
	
	for (posX = height-1; posX >= 0; posX--) //右上加到左下的值  
		TiltedSum += magic[posX][posX]; 
	
	prchar(' ', 5*height); prchar('-', 6); putchar('\n'); //印右上方格的上框線  
	prchar(' ', 5*height); printf("|%4d|\n",TiltedSum);   //印出右上加到左下的值 
	prchar('-', 5*height+6); putchar('\n'); //第一條長框線 
	
	for (posY = 0; posY < height; posY++) //橫排的加總 和框線一起印出 
	{
		for (HoriSum = posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  HoriSum += magic[posX][posY];  }
		
		printf ("|%4d|\n", HoriSum);
	}
		
	prchar('-', 5*height+6); putchar('\n'); //第二條框線 
	
	for (posX = 0; posX < height; posX++) //直行加總並印出 
	{
		for(posY = 0; posY < height; posY++)
		{
			VertSum = 0;
			for (posX = 0; posX < height; posX++)
				VertSum += magic[posX][posY];
			printf ("|%4d", VertSum);
		}
	}
	
	for (TiltedSum = posX = 0; posX < height; posX++) //左上加到右下 
		TiltedSum += magic[posX][posX];
	printf ("|%4d|\n", TiltedSum);
	
	prchar('-', 5*height+6); putchar('\n'); //最下面的框線 
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
