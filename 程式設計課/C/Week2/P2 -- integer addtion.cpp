/*
    ������: 100% ������: ²�� ���N�P: �C
    
	�򥻪�I/O�f�tif...else�Y�i�������@�D 
	�쥻�Q�n�Ψ禡�^�Ǧr�����СA�f�t�T���B��l�@�f��g�b�@��printf���A���]����Ъ��A���٤����ABUG�s�s
	�]���٬O���ϥΰ򥻪��g�k 
*/

#include <stdio.h> 
#include <stdlib.h>

int main()
{
	int n1, n2, ans, correct;
	
	printf ("Teacher:\nn1: ");
	scanf ("%d", &n1);
	printf ("n2: ");
	scanf ("%d", &n2);
	printf ("Student:\n%d + %d = ? ", n1, n2); 
	scanf ("%d", &ans);
	
	printf ("\n");
	if (n1 + n2 == ans)
		printf ("Correct\n");
	else
		printf ("Wrong\n%d + %d = %d\n", n1, n2, n1+n2);
}
