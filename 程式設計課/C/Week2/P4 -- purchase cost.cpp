/*
    完成度: 100% 難易度: 簡單 成就感: 低
    
    我在本題併用了if和switch，讓if處理switch無法處理的大於小於問題，並用switch來判斷數字區間，提高可讀性 
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
	{ printf ("Wrong number!\n\n"); goto start; } //處理小於零的例外 
	else
	{
		switch (units)
		{
		    case 10 ... 19: discount = 0.8;
		    case 20 ... 49: discount = 0.7;
		    case 50 ... 99: discount = 0.6;
		}
	}
	
	printf ("Cost: %.0f", units*100*discount); //小數位一定是零 所以不顯示小數點後的位數 
	return 0;
}
