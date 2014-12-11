#include "lotto3.h"

void prarray(int s[],int size)
{
   for(int i=0;i<size;i++)
     printf("%4d",s[i]);
}
 
int duplicate(int num[], int pos)
{
    for(int i=0;i<pos;i++)
    {
        if(num[i]==num[pos])
          return 1;
    }
    return 0;
} 


void GenerateRandomNumbers (int array[], int count) //Generate random numbers in lotto.RandNum
{
	int i, temp;
	for (i = 0; i < count; i++)
	{
		array[i] = rand() % 49 + 1;
		if ( duplicate (array, i) ) //If there exist a duplicate numbers, then regenerate
			{ i--;  continue; }
	}
}


void list(Lotto *lotto){
    printf("\nLotto ID: %d \n", lotto->id);
    printf("   Date: %d/%d/%d\n", lotto->date.year, lotto->date.month, lotto->date.day);
    printf("   Six winning numbers: ");
    for(int i=0;i<6;i++) printf("%d ",lotto->num[i]);
    printf("\n");
    if(lotto->winnerCount==0) 
      printf("   No winner\n");
    else{
      printf("   Winners: %d \n", lotto->winnerCount);
      for(int j=1;j<=lotto->winnerCount;j++) {
        printf("   [%d] %s, %s, Money Win: $%d\n", j, lotto->winners[j]->name, lotto->winners[j]->id, lotto->winners[j]->moneywin);
      }
    }
    printf("\n");
}

void listSome(Lotto *lotto[], int id1, int id2){
    for(int i=1;i<=MAX;i++){
      if(lotto[i]->id >= id1 && lotto[i]->id <= id2) 
        list(lotto[i]);      
      else if (lotto[i]->id > id2)
        break;
    }

}


void add(Lotto *lotto)
{
	int i;
	printf ("Enter ID: ");
	scanf ("%d", &(lotto->id));
	printf ("Enter date: ");
	scanf ("%d %d %d", &(lotto->date.year), &(lotto->date.month), &(lotto->date.day));
	GenerateRandomNumbers(lotto->num, 6);
	printf ("How many winner? ");
	scanf ("%d", &(lotto->winnerCount));
	
	for (i = 1; i <= (lotto->winnerCount); i++)
	{
		lotto->winners[i] = (WinnerInfo*)malloc(sizeof(WinnerInfo));
		printf ("\nEnter name: ");
		fflush(stdin);
		lotto->winners[i]->name = (char*)malloc(sizeof(char) * 100);
		fgets(lotto->winners[i]->name, 100, stdin);
		printf ("Enter id: ");
		fflush(stdin);
		fgets(lotto->winners[i]->id, 10, stdin);
		printf ("Enter money: ");
		fflush(stdin);
		scanf ("%d", &(lotto->winners[i]->moneywin));	
	}
}
