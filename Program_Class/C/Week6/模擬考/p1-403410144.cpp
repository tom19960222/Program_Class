#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Max (int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}

int Min (int n1, int n2)
{
	return (n1 < n2) ? n1 : n2;
}

int main()
{
	srand(time(NULL));
	int RandNums[10], i, pass=0, fail=0, max=0, min=101;
	
	for (i = 0; i < 10; i++)
	{
		RandNums[i] = rand()%101;
		if (RandNums[i] >= 60)
			pass++;
		else
			fail++;
		max = Max(max, RandNums[i]);
		min = Min(min, RandNums[i]);
	}
	
	printf ("10 numbers randomly generated.\n");
	for (i = 0; i < 10; i++)
		printf ("%d ", RandNums[i]);
	printf ("\n\nPassed: %d\nFailed: %d\nMax = %d\nMin = %d\n\n", pass, fail, max, min);
	printf ("Bye~\nCoding by 1B-403410144-¬I«T¦Ğ");
	
	return 0;
} 
