#include "lotto3.h"

void Prarray(int s[],int size)
{
   for(int i=0;i<size;i++)
     printf("%4d",s[i]);
}
 
int Duplicate(int num[], int pos)
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

WinnerInfo* newWinnerInfo()
{
	WinnerInfo *info = (WinnerInfo*)malloc(sizeof(WinnerInfo));
	info->id = (char*)malloc(sizeof(char) * 100);
	info->moneywin = 0;
	info->name = (char*)malloc(sizeof(char) * 20);
	info->next = NULL;
	
	return info;
}

Lotto* newLotto ()
{
	Lotto *lotto = (Lotto*)malloc(sizeof(Lotto));
	lotto->id = 0;
	lotto->winnerCount = 0;
	lotto->date->year = 0;
	lotto->date->month = 0;
	lotto->date->day = 0;
	lotto->next = NULL;
	lotto->winners = newWinnerInfo();
	
	return lotto;
}

void SwapLotto (Lotto *L1, Lotto *L2)
{
	Lotto temp;
	temp = *L1;
	*L1 = *L2;
	*L2 = temp;
}

Lotto* GetLastLotto(Lotto *first_lotto)
{
	Lotto *ptr = first_lotto;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return ptr;
}

WinnerInfo* GetLastLotto(WinnerInfo *first_info)
{
	WinnerInfo *ptr = first_info;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return ptr;
}

Lotto* GetLottoFromId (Lotto *All_lotto, int id)
{
	Lotto *ptr = All_lotto;
	do 
	{
		if (ptr -> id == id)
			return ptr;
		ptr = ptr->next;
	} while (ptr != NULL);
	
	return NULL;
}

void PrintLotto(Lotto *lotto)
{
    printf("\nLotto ID: %d \n", lotto->id);
    printf("   Date: %d/%d/%d\n", lotto->date.year, lotto->date.month, lotto->date.day);
    printf("   Six winning numbers: ");
    for(int i=0;i<6;i++) printf("%d ",lotto->num[i]);
    printf("\n");
    if(lotto->winnerCount==0) 
      printf("   No winner\n");
    else{
      printf("   Winners: %d \n", lotto->winnerCount);
      PrintWinnerInfo(lotto->winners);
    }
    printf("\n");
}

void PrintWinnerInfo (WinnerInfo *info)
{
	WinnerInfo *ptr = info;
	int i = 1;
	do {
		printf("   [%d] %s, %s, Money Win: $%d\n", i++, info->name, info->id, info->moneywin);
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void PrintAllLotto (Lotto *first_lotto)
{
	date *ptr = first_lotto;
	do {
		PrintLotto(ptr);		
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void PrintSomeLotto(Lotto *first_lotto, int start, int end)
{
	date *ptr = first_lotto;
	do{
		if (ptr->id >= start && ptr->id <= end)
			Print(*ptr);
		//if (ptr->id > end) break;
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void SetWinnnerInfoData(WinnerInfo *info)
{
	printf ("\nEnter name: ");
	fflush(stdin);
	fgets(info->name, 100, stdin);
	printf ("Enter id: ");
	fflush(stdin);
	fgets(info->id, 20, stdin);
	printf ("Enter money: ");
	fflush(stdin);
	scanf ("%d", &(info->moneywin));
}

void SetLottoData(Lotto *lotto)
{
	int i = 0;
	WinnerInfo *info = newWinnerInfo();
	lotto->winners = info;
	
	printf ("Enter date: ");
	scanf ("%d %d %d", &(lotto->date.year), &(lotto->date.month), &(lotto->date.day));
	GenerateRandomNumbers(lotto->num, 6);
	printf ("How many winner? ");
	scanf ("%d", &(lotto->winnerCount));
	SetWinnerInfoData(info);  
	i++;
	while (i < lotto->winnerCount)
	{
		info = newWinnerInfo();
		SetWinnerInfoData(info);
		AppendWinnerInfo(lotto->winners,info);		
	}	
}

void AppendLotto(Lotto *all_lotto, Lotto *insert_data)
{
	Lotto *ptr = GetLastLotto(all_lotto);		
	ptr->next = insertdata;	
}

void AppendWinnerInfo(WinnerInfo *all_info, WinnerInfo *insert_data)
{
	WinnerInfo *ptr = GetLastWinnerInfo(all_info);
	ptr->next = insert_data;
} 

void DeleteLottoByID (Lotto **all_lotto, int id)
{
	Lotto *ptr_prev = NULL;
	Lotto *ptr_now = *all_lotto;
	Lotto *ptr_next = (*all_lotto)->next;
	
	while (ptr_now->id != id && ptr_now->next != NULL)
	{
		ptr_prev = ptr_now;
		ptr_now = ptr_next;
		ptr_next = ptr_next->next;
	}
	
	if (ptr_prev == NULL) //The first one.
	{
		free(*records);
		*records = ptr_next;
	}
	else if (ptr_now->id == id && ptr_next == NULL) //The last one.
	{
		ptr_prev->next = NULL;
		free(ptr_now);
	}
	else if (ptr_next == NULL) //Not Found.
		printf ("\nRecord not found!\n");
	else
	{
		ptr_prev->next = ptr_next;
		free(ptr_now);
	}

}

void ModifyLotto(Lotto *all_lotto, int ID)
{	
	SetLottoData(GetLottoByID(all_lotto, ID));
}

int searchbyID (Lotto *lotto[], int ID, int lottoCount)
{

}

int searchbyDate (Lotto *lotto[], Date searchdate, int lottoCount, int searchresult[])
{

}
