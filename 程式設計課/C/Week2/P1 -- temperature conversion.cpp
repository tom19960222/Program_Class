/* 
	��� -> �ؤ�ū��ഫ
	������: 100% ������: ²�� ���N�P: �D��²�� �S���򦨴N�P
	�@�Ӭ۷�򥻪��D�� ���L�ڨϥΤF�ۭq��ƨӴ����{���X���iŪ�� 
	�b�|�ˤ��J���B��W �ϥΤFmath.h�禡�w��round��ƪ� float����
	��X�ɨϥ� %.0f �ӥh���p�� 
*/

#include <stdio.h> 
#include <math.h>

float CtoF(float C)
{
	return roundf(1.8*C+32);
}

int main()
{
	float temp;
	
	printf ("C: ");
	scanf ("%f", &temp);
	printf ("F = %.0f", CtoF(temp));
	
	return 0;
}
