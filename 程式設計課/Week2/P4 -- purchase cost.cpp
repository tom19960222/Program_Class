/*
    ������: 100% ������: ²�� ���N�P: �C
    
    �ڦb���D�֥ΤFif�Mswitch�A��if�B�zswitch�L�k�B�z���j��p����D�A�å�switch�ӧP�_�Ʀr�϶��A�����iŪ�� 
*/ 

#include <stdio.h>

int main()
{
	float discount = 1;
	int units;
	
start:	
	printf ("Units: ");
	scanf ("%d", &units);
	
	if (units >= 100)
		discount = 0.5;
	else if (units < 0)
	{ printf ("Wrong number!\n\n"); goto start; } //�B�z�p��s���ҥ~ 
	else
	{
		switch (units)
		{
		    case 10 ... 19: discount = 0.8;
		    case 20 ... 49: discount = 0.7;
		    case 50 ... 99: discount = 0.6;
		}
	}
	
	printf ("Cost: %.0f", units*100*discount); //�p�Ʀ�@�w�O�s �ҥH����ܤp���I�᪺��� 
	return 0;
}
