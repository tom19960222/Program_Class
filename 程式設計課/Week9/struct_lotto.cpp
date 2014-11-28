#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct {
	int year, month, day;
} date;

typedef struct {
	int RandNums[6];
	date Date;
} lotto;

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

int Duplicate (int array[], int position) //Find if there is a duplicate number.
{
	int i, j;
	for ( i = 0; i < position; i++)
	{
		if (array[i] == array[position])
			return 1;
	}
	return 0;
}

//                            how many numbers you want to generate
void GenerateRandomNumbers (int array[], int count) //Generate random numbers in lotto.RandNum
{
	int i, temp;
	for (i = 0; i < count; i++)
	{
		array[i] = rand() % 49 + 1;
		if ( Duplicate (array, i) ) //If there exist a duplicate numbers, then regenerate
			{ i--;  continue; }
	}
}

void prlotto(lotto Lo, int number) //print all infomation in a lotto
{
	int i;
	printf ("\n===========================================");
	printf ("\nDate of lotto No.%d: %d/%d/%d\n\n", number+1, Lo.Date.year, Lo.Date.month, Lo.Date.day );
	for (i = 0; i < 6; i++)
		printf ("%d\t", Lo.RandNums[i]);
	printf ("\n===========================================\n");
}

int main()
{
	int size = 1, i, GoNext;
	lotto *Lotto = (lotto*)malloc(size*sizeof(lotto));
	srand(time(NULL));
	
	for (i = 0; i < size; i++)
	{
		GoNext = 0;
		printf ("\nNow is lotto No.%d\n\n", i+1);
		printf ("Please input the year of this lotto: ");
		scanf  ("%d", &((Lotto+i)->Date.year));
		printf ("Please input the month of this lotto: ");
		scanf  ("%d", &((Lotto+i)->Date.month));
		printf ("Please input the day of this lotto: ");
		scanf  ("%d", &((Lotto+i)->Date.day));
		
		GenerateRandomNumbers((Lotto+i)->RandNums, 6); //Generate random numbers in lotto.RandNum
		BubbleSort((int*)&((Lotto+i)->RandNums), 6, 0);
		
		printf ("Do you want the next lotto ( 1 = yes, 0 = no): ");
		scanf ("%d", &GoNext);
		if (GoNext)
		{
			size++;
			lotto *temp = (lotto*)realloc(Lotto, size*sizeof(lotto));
			Lotto = temp;
		}
	}
	
	printf ("\n");
	for (i = 0; i < size; i++)
		prlotto(*(Lotto+i), i); 
	return 0;
}
