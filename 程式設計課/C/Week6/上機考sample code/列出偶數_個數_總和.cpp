/* �J�M�Ѯv�����Ұ}�C ���ڰ��ܤ]���ΰ}�C�F... */ 
/* �g��@�b��OS: WTF �p�G���ΰ}�C �S���q�ɮ׿�J���ո�ƪ��� �n���L�X�Ҧ�����? ���|�ܦ��䥴��L��?
   �M�w�٬O�ΰ}�C�F..... XD */ 
#include <stdio.h>

int main ()
{
	int num, sum=0, even_count=0, even_array[100], i;
	
	printf ("Please input numbers (-1 to exit): ");
	
	while (1)
	{
		scanf ("%d", &num);
		if (num == -1) break;
		if (num % 2 == 0)
		{
			even_array[even_count] = num;
			even_count++;
			sum += num;
		}
	} 
	
	printf ("There are %d even numbers are in the array:\n", even_count);
	for (i = 0; i < even_count; i++)
		printf ("%d ", even_array[i]);
	printf ("\n\nThe sum of these numbers are %d\n", sum);
	
	return 0;
} 
