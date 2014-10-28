#include <stdio.h>

void prchar(char c, int n){
  for(int i=1;i<=n;i++) printf("%c", c);
}

int Palindrome (int num)
{
	int NumArray[5], i;
	for (i = 0; i < 5; i++)
	{ NumArray[i] = num % 10; num /= 10; }
	
	if (NumArray[0] == NumArray[4] && NumArray[1] == NumArray[3])
		return 1;
	else 
		return 0;
}

void NxN_Table (int N)
{
	int i, j;
	
	printf ("   |");
	for (i = 1; i <= N; i++)
		printf ("%4d", i);
	putchar ('\n');
	printf ("---|");
	prchar ('-', N*4);
	putchar ('\n');
	for (i = 1; i <= N; i++)
	{
		printf ("%2d |", i);
		for (j = 1; j <= N; j++)
			printf ("%4d", j + N*(i-1));
		putchar ('\n');
	}
	
	printf ("---|");
	prchar ('-', N*4);
	putchar ('\n');
}

int main ()
{
	int option, num, stop = 0;
	while (1)
	{
		printf ("1. Palindrome\n2. NxN table\n3. Exit\n=> ");
		scanf ("%d", &option);
		
		switch (option)
		{
			case 1:
				putchar('\n');
				printf ("Enter a five-digit number: ");
				scanf ("%d", &num);
				if (Palindrome(num))
					printf ("%d is a palindrome number.\n", num);
				else
					printf ("%d is not a palindrome number.\n", num);
				putchar('\n');
				break;
				
			case 2:
				putchar('\n');
				printf ("Enter N: ");
				scanf ("%d", &num);
				NxN_Table(num);
				putchar('\n');
				break;
			case 3:
				stop = 1;
				break;
		}
		
		if (stop) break;
	}
	printf ("\nBye~\nCoding by 1B-403410144-¬I«T¦Ð\n");
	return 0;
}
