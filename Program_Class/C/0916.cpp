#include <stdio.h>
#include <stdlib.h>

float CtoF (float C)
{
	return 1.8 * C + 32;
} 

float FtoC (float F)
{
	return (F-32) / 1.8;
} 

int ReturnToStartOrNot ()
{
	int result;
	printf ("Return to start? 0 = No , Not 0 = Yes :");
	scanf ("%d", &result);	
	return result;
} 

int main ()
{
	float number;
	int choice, ReturnToStart = 1;
		
	while (ReturnToStart)
	{
		printf ("1.Fahrenheit to Celsius\n2.Celsius to Fahrenheit\nYour choice:");
		scanf ("%d", &choice);
		if (choice == 1)
		{
			printf ("Please input Fahrenheit degree you want to convert:");
			scanf ("%f", &number);
			printf ("%.1f Fahrenheit degree is %.1f Celsius degree.\n\n", number, FtoC(number));
		}
		else if (choice == 2)
		{
			printf ("Please input Fahrenheit degree you want to convert:");
			scanf ("%f", &number);
			printf ("%.1f Celsius degree is %.1f Fahrenheit degree.\n\n", number, CtoF(number));
		}
		else
		{
			printf ("Wrong input!\n\n");
			system("pause");
			system("cls");
			continue;
		}
		ReturnToStart = ReturnToStartOrNot();
	}
	return 0;
}
