#include <stdio.h>

void prchar_recusive(char ch, int time)
{
	if (time > 0)
	{ 
		putchar(ch);
		return prchar_recusive(ch, time-1);
	}
} 

int main ()
{
	prchar_recusive ('*', 5);
	return 0;
}
