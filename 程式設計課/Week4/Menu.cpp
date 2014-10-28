#include <stdio.h>
#define TRUE 1

void PrintMenu ()
{
	printf ("Main Menu:\n");
	printf ("1. CtoF\n2. FtoC\n3. Calendar\n4. DrawRect\n5. Exit\n===> YourChoose: ");
}

float FtoC (float F)
{
	return (F-32) / 1.8;
}

float CtoF (float C)
{
	return 1.8*C+32;
}

void PrintCalender (int days, int first) 
{
	int ItemsInLine, i;
	char *spaces = "    ";
	
	first = first % 7;
	i = 1;
	
	printf ("\n Sun Mon Tue Wed Thu Fri Sat\n");
	while (days > 0)
	{
		ItemsInLine = first;
		while (first > 0)
			{  printf ("%s", spaces);  first--; }
		for (; ItemsInLine < 7; ItemsInLine++)
		{
			printf ("%4d", i++);
			days--;
			if (days == 0) break;
		}
		putchar('\n');
	}
}

void PrintRectengle (int width, int height, int fill)
{
	int i, j; //i -> w; j -> h;
	putchar ('\n');
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf ("%c", (i == height-1 || i == 0 || j == width-1 || j == 0 || fill) ? '*' : ' ');
		putchar('\n');
	}
}

int main()
{
	int option;
	
	while (TRUE)
	{
		int width, height, days, first, fill;
		float F, C;
		PrintMenu();
		scanf ("%d", &option);
		if (option == 5) break;
		
		switch(option)
		{
			case 1: 
				printf ("\nC = ");
				scanf ("%f", &C);
				printf ("F = %.2f", CtoF(C));
				break;
			
			case 2:
				printf ("\nF = ");
				scanf ("%f", &F);
				printf ("C = %.2f", FtoC(F));
				break;
				
			case 3:
				printf ("\nPlease input the number of days: ");
				scanf ("%d", &days);
				printf ("Please input which one is the first day (1 to 7): ");
				scanf ("%d", &first);
				PrintCalender(days, first);
				break;
			
			case 4:
				printf ("\nPlease input width and height: ");
				scanf ("%d %d", &width, &height);
				printf ("Do you want to fill (1 = yes, 0 = no): ");
				scanf ("%d", &fill);
				PrintRectengle(width, height, fill);
				break;
		}
		printf ("\n\n");
	}
	
} 
