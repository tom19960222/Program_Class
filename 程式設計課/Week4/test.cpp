#include <stdio.h>

int main()
{
	int temp;
	scanf ("%d", &temp);
	
	switch(temp){
		case 1: 
		case 2: putchar('2'); break;
		case 3: putchar('3');
	}
	
	return 0;
}
