/*
    完成度: 100% 難易度: 簡單 成就感: 低
    
    我在本題使用了字元指標，讓程式碼的可讀性更高
	同時加入了錯誤檢查機制，在輸入錯誤數字時可以回到開頭重來 
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
		default: Roman = "Wrong input!"; wrong = 1; //例外處理 
	} 
	
	printf ("%s", Roman);
	
	if (wrong) //錯了就回到開頭 
		goto start;
	return 0;
}
