#include <stdio.h>

int main()
{
	int num1, num2;
	printf ("Please input 2 intergers: ");
	scanf ("%d %d", &num1, &num2);
	printf ("%d + %d = %d\n", num1, num2, num1+num2);
	printf ("%d - %d = %d\n", num1, num2, num1-num2);
	printf ("%d x %d = %d\n", num1, num2, num1*num2);
	printf ("%d / %d = %.3f\n", num1, num2, (float)num1/num2);
	
	return 0;
}
