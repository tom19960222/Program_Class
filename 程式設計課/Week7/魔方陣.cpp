#include <stdio.h>
#include <string.h>

int main ()
{
	int height, fillnum, posX, posY;
	
	printf ("Please input height: ");
	scanf ("%d", &height);
	int magic[height][height];
	memset(magic, 0, sizeof(int)*height*height);
	
	posX = height/2; posY = 0;
	magic[posX][posY] = 1;
	
	for (fillnum = 2; fillnum <= height*height; fillnum++)
	{
		posX++; posY--;
		if (posX >= height)
			posX -= height;
		if (posY < 0)
			posY += height;
		else if (posY >= height)
			posY -= height; 
		if (magic[posX][posY] != 0)
			posY++;
		magic[posX][posY] = fillnum;
	}
	
	for (posY = 0; posY < height; posY++)
	{
		for (posX = 0; posX < height; posX++)
			printf("%3d", magic[posX][posY]);
		putchar('\n');
	}
	
	return 0;
} 
