/*
    �ھڿ�J���Ʀr�M�w�n�t�A�íp���n���������
	�����סG²��  �����סG100% ���N�P�G�C
	�@�Ӱ򥻪�switch - case�m�ߡA�b�p��time�ɨϥ�(float)�j���૬�A�קK�p�ƪ��� 
*/

#include <stdio.h>

int main()
{
	int choice, height;
	float time;
	printf ("Select a medium:\n1. Air\n2. Water\n3.Steel\nYour choice: ? ");
	scanf ("%d", &choice);
	printf ("Enter the feet:? ");
	scanf ("%d", &height);
	
	switch (choice)
	{
		case 1:
			time = (float)height / 1100;  break;
		case 2:
			time = (float)height / 4900;  break;
		case 3:
			time = (float)height / 16400; break;
	}
	
	printf ("Travel time: %f sec", time);
	return 0;
} 
