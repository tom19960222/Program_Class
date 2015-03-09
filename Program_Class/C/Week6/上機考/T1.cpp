#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	int count, i;
	srand(time(NULL));
	
	printf ("Please input random numbers: ");
	scanf ("%d", &count);
	int RandNums[count];
	
	for (i = 0; i < count; i++)
	{
		RandNums[i] = rand() % 61 + 40;
		
	} 
} 
 
