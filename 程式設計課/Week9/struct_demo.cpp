#include <stdio.h>

int main()
{
	typedef struct {
		int english;
		int chinese;
		int math;
	} student;
	
	int i, amount = 3;
	student stu[amount];
	
	for (i = 0; i < amount; i++)
	{
		printf ("====== Student %d ======\n\n", i+1);
		printf ("english score = ");
		scanf ("%d", &stu[i].english);
		printf ("chinese score = ");
		scanf ("%d", &stu[i].chinese);
		printf ("math score = ");
		scanf ("%d", &stu[i].math);
	}
	
	printf ("Outputing data...\n");
	for (i = 0; i < amount; i++)
		printf ("\nStudent %d\'s score:\n\tenglish:%d\n\tchinese:%d\n\tmath:%d\n\n",i+1, stu[i].english, stu[i].chinese, stu[i].math);
} 
