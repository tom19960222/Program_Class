#include <stdio.h>

void prchar_recusive(char ch, int time)
{
	if (time > 0)
	{ 
		putchar(ch);
		prchar_recusive(ch, time-1);
	}
} 

void PrintTriangle(int height, int now)
{
	if (now <= height)
	{
		prchar_recusive(' ', height-now);
		prchar_recusive('*', now);
		putchar('\n');
		PrintTriangle(height, now+1);
	} 		
}

int main()
{
	int times;
	printf ("n: ");
	scanf ("%d", &times);
	putchar('\n');
	PrintTriangle(times, 1);
	return 0;
}
