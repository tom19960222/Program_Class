#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int IndexOf (int target, int* arr, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (*(arr+i) == target)
			return i;
	}
	
	return -1;
}

void swap (int* n1, int* n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void BubbleSort (int* arr, int arr_size, int LargeFirst)
{
	int i, j;
	for (j = 0; j < arr_size; j++)
	{
		for (i = 0; i < arr_size; i++)
		{
			if (i == arr_size-1) break; 
			if (LargeFirst)
			{
				if (*(arr+i) < *(arr+i+1))
					swap(arr+i, arr+i+1);
			}
			else
			{
				if (*(arr+i) > *(arr+i+1))
					swap(arr+i, arr+i+1);
			}
		}
		
	}
}

int main()
{
	int arr_size = 6, roll_max = 49;
	int temp, RandNums[arr_size], i;
	srand(time(NULL)); //Use time to be the random seed.
	memset(RandNums, 0, sizeof(int)*arr_size);
	
	for (i = 0; i < arr_size; i++)
	{
		temp = rand()%roll_max+1;

		if (IndexOf(temp, RandNums, arr_size) == -1)
			RandNums[i] = temp;
		else
			{ i--; continue; }
	}
	
	BubbleSort(RandNums, arr_size, 0);
	printf ("Random numbers: ");
	for (i = 0; i < arr_size; i++)
		printf ("%d  ", RandNums[i]);
		
	return 0;
}
