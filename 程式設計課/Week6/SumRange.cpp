#include <stdio.h>

/*int SumRangeLOOP (int first, int last)
{
	int i, sum = 0;
	for (i = first; i <= last; i++)
		sum += i;
	return sum;
}*/

int SumRangeRecusive (int first, int last, int step, int sum)
{
	sum += first; // sum = sum + first;
	if (last == first)
		return sum;
	else
		return SumRangeRecusive (first+step, last, step, sum);
}

int SumItems (int first, int items, int step, int sum)
{
	int i, last = first;
	for (i = 0; i < items-1; i++) //第一次已經加過了. 
		last += step;
		
	return SumRangeRecusive (first, last, step, sum);
	
}

int main()
{
	int first, last, sum=0, step, items;
	printf ("Please input the first and the last number: ");
	scanf ("%d %d", &first, &last);
	printf ("Please input the number between two numbers: ");
	scanf ("%d", &step);
	printf ("The sum between %d and %d is %d\n\n", first, last, SumRangeRecusive(first, last, step, sum));
	
	printf ("Please input the first number and number of items: ");
	scanf ("%d %d", &first, &items);
	printf ("Please input the number between two numbers: ");
	scanf ("%d", &step);
	printf ("The sum started from %d with %d items is: %d", first, items, SumItems(first, items, step, sum));
	
	return 0;
}
