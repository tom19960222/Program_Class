#include "include.h"
#include "struct.h"
#include "func.h"


void swap (int* n1, int* n2);
void BubbleSort (int* arr, int arr_size, int LargeFirst);
int Duplicate (int array[], int position);
void GenerateRandomNumbers (int array[], int count);
void prlotto(lotto Lo, int number);

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
