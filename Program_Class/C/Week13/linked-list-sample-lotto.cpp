#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct{
	int year;
	int month;
	int day;
} Date;

struct lotto{
	int id;             // lotto id
    Date date;          // opening date
    int num[6];         // winning numbers
    int winnerCount;    // number of winners
	lotto *next;
};
typedef struct lotto lotto; 
enum {ADD=1, SEARCH, LISTRANGE, LISTALL, MODIFY, DELETE, EXIT};

lotto* newLotto()
{
	lotto *Lotto = (lotto*)malloc(sizeof(lotto));
	Lotto->id = 0;
	Lotto->date.year = 0;
	Lotto->date.month = 0;
	Lotto->date.day = 0;
	Lotto->next = NULL;
	return Lotto;
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

lotto* GetLastDate(lotto *records)
{
	lotto *ptr = records;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return ptr;
}

lotto* GetLottoByID(lotto *records, int ID)
{
	lotto *ptr = records;
	do 
	{
		if (ptr -> id == ID)
			return ptr;
		ptr = ptr->next;
	}
	while (ptr != NULL);
	
	return NULL;
}

void Append (lotto *records, lotto *insertdata)
{
	lotto *ptr = GetLastDate(records);		
	ptr->next = insertdata;
}

void Print (lotto *lo)
{
	printf("\nLotto ID: %d \n", lo->id);
    printf("   Date: %d/%d/%d\n", lo->date.year, lo->date.month, lo->date.day);
    printf("   Six winning numbers: ");
    for(int i=0;i<6;i++) printf("%d ",lo->num[i]);
    printf("\n");
    if(lo->winnerCount==0) 
      printf("   No winner\n");
    else
      printf("   Winners: %d \n", lo->winnerCount);
    printf ("\n");
}

void PrintAll (lotto *records)
{
	lotto *ptr = records;
	do {
		Print(ptr);		
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void PrintRange(lotto *records, int start, int end)
{
	lotto *ptr = records;
	do{
		if (ptr->id >= start && ptr->id <= end)
			Print(ptr);
		if (ptr->id > end) break;
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void SetData (lotto* records, lotto *d)
{
start:
	printf ("Please input ID: ");
	scanf ("%d", &(d->id));
	
	if (GetLottoByID(records, d->id) != NULL)
	{
		printf ("No duplicate record allowed!\n\n");
		goto start;
	}
	
	printf ("Please input year: ");
	scanf ("%d", &(d->date.year));
	printf ("Please input month: ");
	scanf ("%d", &(d->date.month));
	printf ("Please input day: ");
	scanf ("%d", &(d->date.day));
	printf ("How many winners? ");
	scanf ("%d", &(d->winnerCount));
	GenerateRandomNumbers(d->num, 6);
}

int Count (lotto *records)
{
	int count = 1; //There must be one record in records.
	lotto *ptr = records;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;
}

void DeleteByID (lotto **records, int id)
{
	
	lotto *ptr_prev = NULL;
	lotto *ptr_now = *records;
	lotto *ptr_next = (*records)->next;
	
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

void SearchByID(lotto *records, int ID)
{
	lotto *FoundData = GetLottoByID(records, ID);
	if (FoundData)
		Print(FoundData);
	else
		printf ("Data not found!\n");
}

void Modify (lotto *records, int ID)
{
	SetData(records, GetLottoByID(records, ID));
}

void PrintMenu()
{
     printf("\n\nLotto Menu\n");
     printf("1. Add\n");
     printf("2. Search\n");
     printf("3. List range\n");
     printf("4. List all\n");
     printf("5. Modify\n");
     printf("6. Delete\n"); 
     printf("7. Exit\n"); 
     printf("==> ");
}

int main()
{
	int count = 0, choice, inputID, inputID2;
	lotto *records = newLotto();
	lotto *data = NULL;
	
	while (1)
	{
		PrintMenu();
		scanf ("%d", &choice);
		
		switch(choice)
		{
			case ADD:
				do{
					if (count == 0)
					{
						SetData(records, records);
						count++;
					}
					else
					{
						data = newLotto();
						SetData(records, data);
						Append(records, data);
						count++;
					}
					printf ("Add more? \n\n");
				} while(toupper(getch()) == 'Y');
			break;
			
			case SEARCH:
				printf ("Please input ID: ");
				scanf ("%d", &inputID);
				SearchByID(records, inputID);
			break;
			
			case LISTRANGE:
				printf ("Please input range: ");
				scanf ("%d %d", &inputID, &inputID2);
				PrintRange(records, inputID, inputID2);
			break;
			
			case LISTALL:
				PrintAll(records);
			break;
			
			case MODIFY:
				printf ("Please input ID: ");
				Modify(records, inputID);
			break;
			
			case DELETE:
				printf ("Please input ID: ");
				scanf ("%d", &inputID);
				DeleteByID(&records, inputID);
			break;
			
			
			case EXIT:
				return 0;
			break;	
		}
	}
	return 0;
}
