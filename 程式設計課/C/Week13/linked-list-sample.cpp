#include <stdio.h>
#include <stdlib.h>

struct date{
	int id;
	int year;
	int month;
	int day;
	date *next;
};

typedef struct date date; 

date* newDate(int* id)
{
	date *d = (date*)malloc(sizeof(date));
	d->id = (*id)++;
	d->year = 0;
	d->month = 0;
	d->day = 0;
	d->next = NULL;
	return d;
}

date* GetLastDate(date *records)
{
	date *ptr = records;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return ptr;
}

date* GetDateByID(date *records, int ID)
{
	date *ptr = records;
	do 
	{
		if (ptr -> id == ID)
			return ptr;
		ptr = ptr->next;
	}
	while (ptr != NULL);
	
	return NULL;
}

void Append (date *records, date *insertdata)
{
	date *ptr = GetLastDate(records);		
	ptr->next = insertdata;
}

void Print (date d)
{
	printf ("ID = %d, year = %d, month = %d, day = %d\n", d.id, d.year, d.month, d.day);
}

void PrintAll (date *records)
{
	date *ptr = records;
	do {
		Print(*ptr);		
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void PrintRange(date *records, int start, int end)
{
	date *ptr = records;
	do{
		if (ptr->id >= start && ptr->id <= end)
			Print(*ptr);
		if (ptr->id > end) break;
		ptr = ptr->next;
	}
	while (ptr != NULL);
}

void SetData (date *d)
{
	printf ("Please input year: ");
	scanf ("%d", &(d->year));
	printf ("Please input month: ");
	scanf ("%d", &(d->month));
	printf ("Please input day: ");
	scanf ("%d", &(d->day));
}

int Count (date *records)
{
	int count = 1; //There must be one record in records.
	date *ptr = records;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;
}

void DeleteByID (date **records, int id)
{
	
	date *ptr_prev = NULL;
	date *ptr_now = *records;
	date *ptr_next = (*records)->next;
	
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

void SearchByID(date *records, int ID)
{
	date *FoundData = GetDateByID(records, ID);
	if (FoundData)
		Print(*FoundData);
	else
		printf ("Data not found!\n");
}

void Modify (date *records, int ID)
{
	SetData(GetDateByID(records, ID));
}

int main()
{
	int i, ID = 1;
	date *records = newDate(&ID);
	date *data = NULL;
	SetData(records);
	
	for (i = 0; i < 3; i++)
	{
		data = newDate(&ID);
		SetData(data);
		Append(records, data);
	}
	
	PrintAll(records);
	printf ("\nThere are %d records now.\n\n", Count(records));
	DeleteByID(&records, 1);
	PrintAll(records);
	printf ("\nThere are %d records now.\n\n", Count(records));
	printf ("searching record id = 4...\n\n");
	SearchByID(records, 4);
	printf ("\nListing ID=2~4...\n\n");
	PrintRange(records, 2, 10);
	Modify(records, 2);
	PrintAll(records);
	return 0;
}
