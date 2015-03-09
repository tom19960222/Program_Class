/*
    根據輸入的數字決定聲速，並計算聲音走的秒數
	難易度：簡單  完成度：100% 成就感：低
	一個基本的switch - case練習，在計算time時使用(float)強迫轉型，避免小數的遺失 
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
