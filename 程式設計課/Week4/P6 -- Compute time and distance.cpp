/*
    ���w���l���t�סA��ܨ��l�b�C�Ӥp�ɲ֭p�����`�Z�� 
    �����סG²�� �����סG100% ���N�P�G���I
	
	�쥻�@���H��printf �bŪ���ܼƮɡA�O�ѥ��ӥk��
	�]���b�L�X�r��ɡA�g�X�F  printf ("Time: %d hr/Distance: %d km\n", i, i++*speed); �o�˪��ԭz 
	�H���|�O ���o�Ĥ@��i -> ���oi*speed -> i += 1 �o�˪����涶��
	���O�o���ͤF�N�~���~�����G�A�᭱��i*speed�O���`���A�e����i�o�Q+1�F
	��O�K�}�l�M�B�ͤ@�s�ꪺ����M�Q�סA�̫�o�X�����G�Ш��U��Code
	
	���C�y������h���{�ѯu�O�@��O�H�}�ߪ��ơI 
*/

#include <stdio.h>

int main()
{
	int speed, time, i = 1;
	printf ("Speed of the vehicle? ");
	scanf ("%d", &speed);
	printf ("Hours that it traveled? ");
	scanf ("%d", &time);
	
	while (i <= time)
		printf ("Time: %d hr/Distance: %d km\n", i++, i*speed); 
		
		/*
		    ���絲�G:
			    �q�k�������ܼ� ��++�����W > (�k++���� > �k++���W) LOOP > ��++ & �@���ܼƨ��� 
		*/ 
		
	/*for (i = 1; i <= time; i++)
		printf ("Time: %d hr/Distance: %d km\n", i, i*speed);*/
		//������for���� 
}
