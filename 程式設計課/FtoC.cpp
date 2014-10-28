#include <stdio.h>

int main()
{
	float temp;
	printf ("Please input Fahrenheit temperature: ");
	scanf ("%f", &temp);
	printf ("%fF = %fC", temp, (temp-32)/1.8);
	return 0;
}
