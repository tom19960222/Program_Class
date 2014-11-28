#include <stdio.h>

void swap_ref (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_value (int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	
	printf ("Address of a in function = %X\n", &a);
	printf ("Address of b in function = %X\n", &b);
}

int main()
{
	int a, b;
	int *ptr_to_a;
	
	ptr_to_a = &a;
	a = 10;  b = 5;
	
	printf ("a = %d  b = %d\n", a, b);
	printf ("a = %X  b = %X\n", &a, &b);
	printf ("Value stored in ptr_to_a = %X\n", ptr_to_a);
	printf ("Address of ptr_to_a = %X\n", &ptr_to_a);
	
	swap_value(a, b);
	
	printf ("a = %d  b = %d\n", a, b);
	printf ("a = %X  b = %X\n", &a, &b);
	
	return 0;
}
