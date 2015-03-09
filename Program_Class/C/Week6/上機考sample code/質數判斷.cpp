#include <stdio.h>
#define TRUE  1
#define FALSE 0

int IsPrime (int num)
{
	int i;
	
	if (num == 1)
		return FALSE; // 1���O���
	else if (num == 2)
		return TRUE;  // 2�O�ߤ@�����ƽ��
	else if (num % 2 == 0)
		return FALSE; // 2�H�~�����Ƴ����O��� 
	else 
		{
			for (i = 3; i < num; i += 2) //��2�j�����Ƴ����ΰ��F �@�w���O��� 
			{
				if (num % i == 0)
					return FALSE; //�p�G��1�M�ۤv�H�~���]�� �N���O��� 
			}
			return TRUE; // ����ۤv�٨S���ƥi�H�㰣���� �N�O��� 
		}
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
