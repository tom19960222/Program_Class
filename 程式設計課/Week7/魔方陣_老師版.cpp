#include <stdio.h> 
#define MAX 30 

void prchar (char ch, int n)  //putchar(ch) for n times. 
{
	while (n--)
		putchar(ch);
}

void Magic (int magic[][MAX], int height) //�b�}�Cmagic�̭������]��} �u�ΦѮv���t��k 
{
	int row=0, col=height/2, i;
	magic[row][col] = 1;
	
	for ( i = 2; i <= height*height; i++)
	{
		if (i % height == 1) //�b�P�@�C�W¶�@��F ���U���@�C 
			row++;
		else //�٨S¶���@�� ���k�W���@�� 
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
	
	prchar('-', 5*height+1); putchar('\n');  //�W�����ؽu 
	
	for (posY = 0; posY < height; posY++) // �L�X�Ʀr+�ؽu 
	{
		for (posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  }
		printf ("|\n");
	}
		
	prchar('-', 5*height+1); putchar('\n'); //�U�����ؽu 
}

void ComputeSum (int magic[][MAX], int height)
{
	int posX, posY, HoriSum, VertSum, TiltedSum=0;
	
	for (posX = height-1; posX >= 0; posX--) //�k�W�[�쥪�U����  
		TiltedSum += magic[posX][posX]; 
	
	prchar(' ', 5*height); prchar('-', 6); putchar('\n'); //�L�k�W��檺�W�ؽu  
	prchar(' ', 5*height); printf("|%4d|\n",TiltedSum);   //�L�X�k�W�[�쥪�U���� 
	prchar('-', 5*height+6); putchar('\n'); //�Ĥ@�����ؽu 
	
	for (posY = 0; posY < height; posY++) //��ƪ��[�` �M�ؽu�@�_�L�X 
	{
		for (HoriSum = posX = 0; posX < height; posX++)
			{  printf("|%4d", magic[posX][posY]);  HoriSum += magic[posX][posY];  }
		
		printf ("|%4d|\n", HoriSum);
	}
		
	prchar('-', 5*height+6); putchar('\n'); //�ĤG���ؽu 
	
	for (posX = 0; posX < height; posX++) //����[�`�æL�X 
	{
		for(posY = 0; posY < height; posY++)
		{
			VertSum = 0;
			for (posX = 0; posX < height; posX++)
				VertSum += magic[posX][posY];
			printf ("|%4d", VertSum);
		}
	}
	
	for (TiltedSum = posX = 0; posX < height; posX++) //���W�[��k�U 
		TiltedSum += magic[posX][posX];
	printf ("|%4d|\n", TiltedSum);
	
	prchar('-', 5*height+6); putchar('\n'); //�̤U�����ؽu 
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
