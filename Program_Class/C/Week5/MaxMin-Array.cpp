#include <stdio.h>

int max (int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}

int min (int n1, int n2)
{
	return (n1 < n2) ? n1 : n2;
}

int main ()
{
	int array[100], i, Max, Min;
	
	for (i = 0; i < 100; i++) //Get data.
	{
		scanf ("%d", &array[i]);
		if (array[i] == -99) break;
	}	
	
	Min = Max = array[0];
	i--; //The last data in array is "-99"
	for (; i > 0; i--) //Find from the end of the input, so we don't have to declare another variable.
	{
		Min = min (Min, array[i]);
		Max = max (Max, array[i]);
	}
	
	printf ("Max = %d, Min = %d", Max, Min);
	
}
