/*
    ��@�m�߲�4�D 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
	float computer_score;
	float math_score;
	float english_score;
} student;

int main ()
{
	student stu;
	
	printf ("�п�J�m�W: ");
	fgets (stu.name, 100, stdin); //�ϥ�fgets�קK���ťզr���������|Ū���� 
	stu.name[strlen(stu.name)-1] = '\0'; //�⴫��r������ 
	printf ("�п�J�p�����Z: ");
	scanf ("%f", &stu.computer_score);
	printf ("�п�J�ƾǦ��Z: ");
	scanf ("%f", &stu.math_score);
	printf ("�п�J�^�妨�Z: ");
	scanf ("%f", &stu.english_score);
	printf ("�έp��.................\n");
	
	printf ("%s�����Z�p�U : \n", stu.name);
	printf ("=====================\n");
	printf ("\t�p��: %.0f\n", stu.computer_score);
	printf ("\t�ƾ�: %.0f\n", stu.math_score);
	printf ("\t�^��: %.0f\n", stu.english_score);
	printf ("---------------------\n");
	printf ("\t�`��: %.0f\n", stu.computer_score+stu.math_score+stu.english_score);
	printf ("\t����: %.2f\n", (stu.computer_score+stu.math_score+stu.english_score) / 3);
	
	return 0;
}
