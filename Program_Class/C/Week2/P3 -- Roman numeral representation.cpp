/*
    ������: 100% ������: ²�� ���N�P: �C
    
    �ڦb���D�ϥΤF�r�����СA���{���X���iŪ�ʧ�
	�P�ɥ[�J�F���~�ˬd����A�b��J���~�Ʀr�ɥi�H�^��}�Y���� 
*/ 

#include <stdio.h> 
#include <string.h>

int main ()
{
	int num, wrong = 0;
	
start:	
	printf ("Input a number (1~10): ");
	scanf("%d", &num);
	char* Roman = NULL;
	wrong = 0;
	
	switch (num)
	{
		case 1: Roman = "I";    break;
		case 2: Roman = "II";   break;
		case 3: Roman = "III";  break;
		case 4: Roman = "IV";   break;
		case 5: Roman = "V";    break;
		case 6: Roman = "VI";   break;
		case 7: Roman = "VII";  break;
		case 8: Roman = "VIII"; break;
		case 9: Roman = "IX";   break;
		case 10: Roman = "X";   break;
		default: Roman = "Wrong input!"; wrong = 1; //�ҥ~�B�z 
	} 
	
	printf ("%s", Roman);
	
	if (wrong) //���F�N�^��}�Y 
		goto start;
	return 0;
}
