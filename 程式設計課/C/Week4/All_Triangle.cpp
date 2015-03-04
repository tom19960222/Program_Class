#include <stdio.h>

int main()
{
	int height, fill, i, j;
	printf ("Please input the height of the triangle: ");
	scanf ("%d", &height);
	printf ("Filled (1 for yes, 0 for no): ");
	scanf ("%d", &fill);
	for (i = 1 ; i <= height; i++)
	{
		for (j = 1; j <= height; j++) //DownRight
				printf ("%c", (i == height || j == height || i+j == height+1 || (fill && i+j >= height+1)) ? '*' : ' ');
		putchar (' ');
		for (j = 1; j <= height; j++) //DownLeft
				printf ("%c", (i == height || j == 1 || j == 1 || i == j || (fill && i >= j)) ? '*' : ' ');
		putchar('\n');
	}
	
	for (i = 1 ; i <= height; i++)
	{
		for (j = 1; j <= height; j++)
			printf ("%c", (i == 1 || j == height || i == j || (fill && j >= i)) ? '*' : ' ');
		putchar(' ');
		for (j = 1; j <= height; j++)
			printf ("%c", (i == 1 || j == 1 || i+j == height+1 || (fill && (i+j) <= height+1)) ? '*' : ' ');
		putchar('\n');
	}
	return 0;
}
