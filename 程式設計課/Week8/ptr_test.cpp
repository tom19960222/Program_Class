#include <stdio.h>

int main()
{
	int test[2][2], i;
	int* ptr; 
	ptr = (int*)test;
	test[0][0] = 0;
	test[0][1] = 1;
	test[1][0] = 2;
	test[1][1] = 3;
	
	printf ("test[1][1] == %d == ptr+(2*1)+1 == %d", test[1][1], *ptr+(2*1)+1);
	
	return 0;
} 
