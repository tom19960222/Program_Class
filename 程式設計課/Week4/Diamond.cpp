#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int height, i, j, center, fill = 1;
	scanf ("%d", &height);
	if (height % 2 == 0)
	{
		center = height / 2;
		for (i = 1; i <= center; i++)
		{
			for (j = 1; j <= height; j++)
			{
				if ((j == center && i == 1) || j == center + i-1 || j == center - i+1 || (fill && (j < center + i-1 && j > center - i+1))) putchar ('*');
				else putchar (' ');
			}
			putchar('\n');
		}
		for (; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
			{
				if ((j == center && i == height) || j == i-center || j == center + height - i || (fill && (j > i-center && j < center + height - i)) ) putchar ('*');
				else putchar (' ');
			}
			putchar('\n');
		}
	}
	
	else
	{
		center = height / 2 + 1;
		for (i = 1; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
			{
				if (j == center - i+1 || j == center + i-1 || j == i+1 - center || j == center + height-i || (fill && (j > center - i+1 && j < center + i-1 && j > i+1 - center && j < center + height-i))) putchar ('*');
				else putchar (' ');
			}
			putchar('\n');
		} 
	}
	return 0;
}
