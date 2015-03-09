#include <stdio.h>
#include <math.h>
#define UpLeft    1
#define UpRight   2
#define DownLeft  3
#define DownRight 4
#define IsoscelesTriangleUp   5
#define IsoscelesTriangleDown 6

/*
    輸出 * 的條件:
	    i == height || i == 0
	    j == width || j == 0
*/
int RoundtoInt (float input)
{
	float intpart;
	float floatpart = modff(input, &intpart);
	return (floatpart >= 0.5) ? (int)input+1 : (int)input;
}

void PrintRetengle (int width, int height, int fill)
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

int main ()
{
	int width, height, graph, i, fill;
	
start:
	printf ("Please input what kind of graphic you want to print\n1: retengle\n2: triangle\nYour choose: ");
	scanf ("%d", &graph);
	printf ("Do you want to fill up the graphic?\n1: Yes\n0: No\nYour Choose: ");
	scanf ("%d", &fill);
	if (graph == 1)
	{
		printf ("Please input width & height: ");
		scanf ("%d %d", &width, &height);
		PrintRetengle(width, height, fill);
	}
	else if (graph == 2)
	{
		printf ("Please input height: ");
		scanf ("%d", &height);
		for (i = 1; i <= 6; i++)
			{ putchar('\n'); PrintTriangle (height, i, fill); putchar('\n'); }
	}
	else
	{
		printf ("Wrong type!\n\n");
		goto start;
	}
} 
