#include <stdio.h>

int main()
{
	float temp;
	printf ("Please input Celsius temperature: ");
	scanf ("%f", &temp);
	printf ("%fC = %fF", temp, 1.8*temp+32);
	return 0;
}
