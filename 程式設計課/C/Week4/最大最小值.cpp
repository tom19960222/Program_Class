/*
    ��J�@��Ʀr�A����̤j�̤p��
	�����סG²�� �����סG100% ���N�P�G���q
	
	�D�`�嫬��²���v���D�A�q�`�n�`�N�������O�p�G�u����J�@�Ӵ���A�h�ⵧ��Ƴ��n�@����s 
	�t�@�ӭn�`�N�������h�O-99�O�_�n�C�J�p��A�άO��§@������γ~ 
*/ 
#include <stdio.h>
#include <math.h> 

int max (int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}

int min (int n1, int n2)
{
	return (n1 < n2) ? n1 : n2;
}

int main()
{
	int Max = 0, Min = 0, temp;
	
	scanf ("%d", &temp);
	
	/* Deal with some special inputs.
	   When there is only one input "-99" -> exit program.
	   When there are two inputs: (a number) and -99 -> Min and Max are set to the number, and then exit the program.
	*/
	
	if (temp != -99) Min = Max = temp;
	else return 0;
	 
	do 
	{
		scanf ("%d", &temp);
		if (temp == -99) break;
		Max = max(Max, temp);
		Min = min(Min, temp);
	} while (temp != -99);
	
	printf ("\nInput ended.\n");
	printf ("Max = %d, Min = %d", Max, Min);
	
	return 0;
}
