#include <stdio.h>
#define TRUE  1
#define FALSE 0



int IsPrime (int num);
void MakePrimeNumberTable (int* table, int target, int numbernow);

int IsPrime (int num, int* table)
{
	int i;
	
	if (num == 1)
		return FALSE; // 1ぃ琌借计
	else if (num == 2)
		return TRUE;  // 2琌斑案计借计
	else if (num % 2 == 0)
		return FALSE; // 2案计常ぃ琌借计 
	else 
		{
			for (i = 3; i < num; i += 2) //ゑ2案计常ぃノ埃 ﹚ぃ琌借计 
			{
				if (num % i == 0)
					return FALSE; //狦Τ1㎝计 碞ぃ琌借计 
			}
			return TRUE; // 埃临⊿Τ计俱埃杠 碞琌借计 
		}
}

void MakePrimeNumberTable (int* table, int target, int numbernow)
{
	for (; *table == numbernow; table++);
		
}

int main ()
{
	int num;
	
	while (1)
	{
		printf ("Please input a number (-1 to exit): ");
		scanf ("%d", &num);
		if (num == -1) break;
		if (IsPrime(num) == TRUE)
			printf ("%d is a prime number.\n\n", num);
		else
			printf ("%d is not a prime number.\n\n", num);
	}
	
	return 0;
} 
