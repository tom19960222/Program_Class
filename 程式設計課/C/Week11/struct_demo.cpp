#include <stdio.h>

typedef struct {
	char *Firstname;
	char *Lastname ;
} name;

typedef struct {
	int Year;
	int Month;
	int Day;
} date;

typedef struct {
	date Birthday;
	name Name;
} person;

int main()
{
	person students[3];
	person *ptr_to_students = students;
	
	students[0].Birthday.Year = 1996;
	students[0].Birthday.Month = 1;
	students[0].Birthday.Day = 1;
	students[0].Name.Lastname = "Zero";
	students[0].Name.Firstname = "Z";
	
	students[1].Birthday.Year = 1994;
	students[1].Birthday.Month = 2;
	students[1].Birthday.Day = 6;
	students[1].Name.Lastname = "One";
	students[1].Name.Firstname = "O";
	
	students[2].Birthday.Year = 1998;
	students[2].Birthday.Month = 7;
	students[2].Birthday.Day = 17;
	students[2].Name.Lastname = "Two";
	students[2].Name.Firstname = "T";
	
	int i;
	for (i = 0; i < 3; i++)
	{
		printf ("Printing student %d\n-------------------------------\n", i+1);
		printf ("Birthday = %d/%d/%d\n", (*ptr_to_students).Birthday.Year, (*ptr_to_students).Birthday.Month , (*ptr_to_students).Birthday.Day);
		printf ("Name = %s %s\n\n", (*ptr_to_students).Name.Firstname, (*ptr_to_students).Name.Lastname);
		ptr_to_students++;
	}
	
	return 0;
}


