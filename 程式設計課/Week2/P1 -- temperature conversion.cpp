/* 
	攝氏 -> 華氏溫度轉換
	完成度: 100% 難易度: 簡單 成就感: 題目簡單 沒什麼成就感
	一個相當基本的題目 不過我使用了自訂函數來提高程式碼的可讀性 
	在四捨五入的運算上 使用了math.h函式庫的round函數的 float版本
	輸出時使用 %.0f 來去掉小數 
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
