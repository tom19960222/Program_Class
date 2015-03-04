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

void swapLotto (Lotto *L1, Lotto *L2)
{
	Lotto temp;
	temp = *L1;
	*L1 = *L2;
	*L2 = temp;
}

int indexOf (Lotto *lotto[], Lotto *target, int lottoCount)
{
	int i;
	Lotto **ptr = lotto;
	for (i = 0; i < lottoCount; i++)
	{
		if (*ptr == target)
			return i;
		else
			ptr++;
	}
	return -1;
}

int getLottoFromId (Lotto *lotto[], int id, int lottoCount)
{
	int i;
	for (i = 0; i < lottoCount; i++)
	{
		if (lotto[i]->id == id)
			return i;
	}
	return -1;
}

void InsertData(Lotto *target)
{
	int i;
	printf ("Enter date: ");
	scanf ("%d %d %d", &(target->date.year), &(target->date.month), &(target->date.day));
	GenerateRandomNumbers(target->num, 6);
	printf ("How many winner? ");
	scanf ("%d", &(target->winnerCount));
	
	for (i = 1; i <= (target->winnerCount); i++)
	{
		target->winners[i] = (WinnerInfo*)malloc(sizeof(WinnerInfo));
		printf ("\nEnter name: ");
		fflush(stdin);
		target->winners[i]->name = (char*)malloc(sizeof(char) * 100);
		fgets(target->winners[i]->name, 100, stdin);
		printf ("Enter id: ");
		fflush(stdin);
		fgets(target->winners[i]->id, 10, stdin);
		printf ("Enter money: ");
		fflush(stdin);
		scanf ("%d", &(target->winners[i]->moneywin));	
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

void listSome(Lotto *lotto[], int id1, int id2, int lottoCount){
    for(int i=0;i<MAX;i++){
      if(lotto[i]->id >= id1 && lotto[i]->id <= id2) 
        list(lotto[i]);      
      if (i+1 == lottoCount)
    	break;
    }
}

void add(Lotto *lottos[], Lotto *target, int* Count)
{
start:
	int i;
	printf ("Enter ID: ");
	scanf ("%d", &(target->id));
	if (getLottoFromId(lottos, target->id, *Count) != -1)
	{
		printf ("No duplicate record allowed!\n\n");
		goto start;
	}
	InsertData(target);
	(*Count)++;
}

int del (Lotto *lotto[], Lotto *target, int *Count)
{
	int i, index;
	index = indexOf(lotto, target, *Count);
	if (index == -1)
		return -1; //lotto not found.
	for (i = index; i < *Count-1; i++)
		swapLotto(lotto[i], lotto[i+1]);
	free(lotto[i]);
	*Count -= 1;
}

void modify(Lotto *target)
{	
	InsertData(target);
}

int searchbyID (Lotto *lotto[], int ID, int lottoCount)
{
	return getLottoFromId(lotto, ID, lottoCount);
}

int searchbyDate (Lotto *lotto[], Date searchdate, int lottoCount, int searchresult[])
{
	int resultcount = 0, i;
	for (i = 0; i < lottoCount; i++)
	{
		if (lotto[i]->date.year == searchdate.year && lotto[i]->date.month == searchdate.month && lotto[i]->date.day == searchdate.day)
		{
			searchresult[resultcount] = i;
			resultcount++;
		}
	}
	return resultcount;
}
