/*
    實作練習第4題 
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
	
	printf ("請輸入姓名: ");
	fgets (stu.name, 100, stdin); //使用fgets避免有空白字元之類的會讀不到 
	stu.name[strlen(stu.name)-1] = '\0'; //把換行字元拿掉 
	printf ("請輸入計概成績: ");
	scanf ("%f", &stu.computer_score);
	printf ("請輸入數學成績: ");
	scanf ("%f", &stu.math_score);
	printf ("請輸入英文成績: ");
	scanf ("%f", &stu.english_score);
	printf ("統計中.................\n");
	
	printf ("%s的成績如下 : \n", stu.name);
	printf ("=====================\n");
	printf ("\t計概: %.0f\n", stu.computer_score);
	printf ("\t數學: %.0f\n", stu.math_score);
	printf ("\t英文: %.0f\n", stu.english_score);
	printf ("---------------------\n");
	printf ("\t總分: %.0f\n", stu.computer_score+stu.math_score+stu.english_score);
	printf ("\t平均: %.2f\n", (stu.computer_score+stu.math_score+stu.english_score) / 3);
	
	return 0;
}
