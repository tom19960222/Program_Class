#include <stdio.h> 
#include <stdlib.h>
#define BUFF 10

int Max (int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}

int Min (int n1, int n2)
{
	return (n1 < n2) ? n1 : n2;
}

int main()
{
	int min, max, temp, arr_index = 0, arr_size = BUFF, arr_increase = 10, i;
	
	int *arr = (int*)malloc(arr_size*sizeof(int));
	
	//Get the first value, in order to prevent there is only one value inputed.
	scanf ("%d", arr+arr_index);
	min = max = *(arr+arr_index);
	arr_index++;
	
	while (scanf ("%d", arr+arr_index) != EOF)
	{
		if (*(arr+arr_index) == -99) break;
		
		if (arr_index == arr_size-1)  //space is full, need more space.
		{
			int* temp = (int*)realloc(arr,sizeof(int)*(arr_size+arr_increase));
			if (temp!=NULL) //Success
			{ arr = temp; arr_size += arr_increase; }
			else
			{ printf ("Failed to locate memory!\n"); return 1; }
		}
		arr_index++;
	}
	
	for (i = 0 ; i < arr_index ; i++)
	{
		min = Min (min, *(arr+i));
		max = Max (max, *(arr+i));
	}
		
	printf ("Max = %d\nMin = %d", max, min);
	
	return 0;
}
