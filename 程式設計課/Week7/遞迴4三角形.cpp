#include <stdio.h>
enum Triangle_Type{LeftUP, LeftDown, RightUP, RightDown};

void prchar_recusive(char ch, int time)
{
	if (time > 0)
	{ 
		putchar(ch);
		prchar_recusive(ch, time-1);
	}
} 

void PrintLeftDownTriangle(int height, int now)
{
	if (now <= height)
	{
		prchar_recusive('*', now); 
		putchar('\n');
		PrintLeftDownTriangle(height, now+1);
	}
}

void PrintLeftUPTriangle(int height, int now)
{
	if (now <= height)
	{
		prchar_recusive('*', height-now);
		putchar('\n');
		PrintLeftUPTriangle(height, now+1);
	}
}

void PrintRightUPTriangle(int height, int now)
{
	if (now <= height)
	{
		prchar_recusive(' ', now);
		prchar_recusive('*', height-now);
		putchar('\n');
		PrintRightUPTriangle(height, now+1);
	}
}

void PrintRightDownTriangle(int height, int now)
{
	if (now <= height)
	{
		prchar_recusive(' ', height-now);
		prchar_recusive('*', now);
		putchar('\n');
		PrintRightDownTriangle(height, now+1);
	}
}

void CallPrintTriangle (int type, int height)
{
	switch(type)
	{
		case LeftUP:
			PrintLeftUPTriangle(height, 1); break;
		case LeftDown:
			PrintLeftDownTriangle(height, 1); break;
		case RightUP:
			PrintRightUPTriangle(height, 1); break;
		case RightDown:
			PrintRightDownTriangle(height, 1); break;		
	}
}

int main()
{
	int height;
	printf ("Please input height: ");
	scanf ("%d", &height);
	
	CallPrintTriangle (LeftUP,height);    putchar ('\n');
	CallPrintTriangle (LeftDown,height);  putchar ('\n');
	CallPrintTriangle (RightUP,height);   putchar ('\n');
	CallPrintTriangle (RightDown,height); putchar ('\n');
	
	return 0;
}
