#include <stdio.h> 

int main()
{
	int input, i = 0;
	int Bin[100];
	printf ("Input a number: ");
	scanf ("%d", &input);
	
	for (i = sizeof(input)*8 - 1; i >= 0; i--)
		printf("%d", (input >> i) & 1);
	/*
	while (input > 0)
	{
		Bin[i] = (input & 1);
		input = input >> 1;
		i++;x	
	} 
	
	for (i--; i >= 0; i--)
		printf ("%d", Bin[i]);
	 */
	 return 0;
}
