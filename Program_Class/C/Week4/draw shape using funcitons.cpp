//draw shape using funcitons

#include <stdio.h>

#define UpLeft    1
#define UpRight   2
#define DownLeft  3
#define DownRight 4
#define IsoscelesTriangleUp   5
#define IsoscelesTriangleDown 6

void PrintRetangle (int width, int height, int fill)
{
	int i, j; //i -> w; j -> h;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf ("%c", (i == height-1 || i == 0 || j == width-1 || j == 0 || fill) ? '*' : ' ');
		putchar('\n');
	}
}

void PrintTriangle (int height, int Type, int fill)
{
	int i, j;
	if (Type == UpLeft)
	{
		for (i = 1 ; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
				printf ("%c", (i == 1 || j == 1 || i+j == height+1 || (fill && (i+j) <= height+1)) ? '*' : ' ');
			putchar('\n');
		}
	}
	else if (Type == UpRight)
	{
		for (i = 1 ; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
				printf ("%c", (i == 1 || j == height || i == j || (fill && j >= i)) ? '*' : ' ');
			putchar('\n');
		}
	}
	else if (Type == DownLeft)
	{
		for (i = 1 ; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
				printf ("%c", (i == height || j == 1 || j == 1 || i == j || (fill && i >= j)) ? '*' : ' ');
			putchar('\n');
		}
	}
	else if (Type == DownRight)
	{
		for (i = 1 ; i <= height; i++)
		{
			for (j = 1; j <= height; j++)
				printf ("%c", (i == height || j == height || i+j == height+1 || (fill && i+j >= height+1)) ? '*' : ' ');
			putchar('\n');
		}	
	}
	else if (Type == IsoscelesTriangleUp)
	{
		for (i = 1; i <= height; i++)
		{
			for (j = 1 ; j < height*2; j++)
				printf ("%c", ((j == height && i == 1) ||  j == height-i+1 || j == height+i-1 || i == height || (fill && (j > height-i+1 && j < height+i-1))) ? '*' : ' ');
			putchar('\n');
		}
	}
	else if (Type == IsoscelesTriangleDown)
	{
		for (i = height; i >= 1; i--)
		{
			for (j = 1 ; j < height*2; j++)
				printf ("%c", ((i == 1 && j == height) ||  j == height-i+1 || j == height+i-1 || i == height || (fill && (j >= height-i+1 && j <= height+i-1)))? '*' : ' ');
			putchar('\n');
		}
	}
}

void PrintDiamond (int height, int fill)
{
	int center, i, j;
	if (height % 2 == 0)
	{
		center = height / 2;
		for (i = 1; i <= center; i++) //上半部 
		{
			for (j = 1; j <= height; j++)
			{
				if ((j == center && i == 1) || j == center + i-1 || j == center - i+1 || (fill && (j < center + i-1 && j > center - i+1))) putchar ('*');
				else putchar (' ');
			}
			putchar('\n');
		}
		for (; i <= height; i++) //下半部 
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
}

int main ()
{
	int option, height, width, type, fill;
	
	while (1)
	{
		printf("    Draw Menu\n--------------\n1. rectangle\n2. vertical triangle\n3. diamond\n4. Exit\n=> ");
		scanf ("%d", &option);
		
		putchar('\n');
		switch(option)
		{
			case 1:
				
				printf ("Please input height: ");
				scanf ("%d", &height);
				printf ("Please input width: ");
				scanf ("%d", &width);
				printf ("Filled (1 for yes, 0 for no): ");
				scanf ("%d", &fill);
				putchar('\n');
				PrintRetangle(width, height, fill);
				break;
			
			case 2:
				printf ("Please input height: ");
				scanf ("%d", &height);
				printf ("Please input type: ");
				scanf ("%d", &type);
				printf ("Filled (1 for yes, 0 for no): ");
				scanf ("%d", &fill);
				putchar('\n');
				PrintTriangle(height, type, fill);
				break;
				
			case 3:
				printf ("Please input height: ");
				scanf ("%d", &height);
				printf ("Filled (1 for yes, 0 for no): ");
				scanf ("%d", &fill);
				putchar('\n');
				PrintDiamond (height, fill);
				break;
				
			case 4:
				putchar('\n');
				printf ("Bye!\n");
				return 0;
		}
		
		printf ("\n\n");
	}
	return 0;
}
