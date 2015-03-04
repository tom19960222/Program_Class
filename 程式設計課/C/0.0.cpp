#include <stdio.h>

int main()
{
	float n;
	printf("Enter temperature in C");
	scanf("%f" ,&n);
	printf("%.1f",1.8*n+32);
}
