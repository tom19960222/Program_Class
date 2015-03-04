/*
    給定車子的速度，顯示車子在每個小時累計走的總距離 
    難易度：簡單 完成度：100% 成就感：高！
	
	原本一直以為printf 在讀取變數時，是由左而右的
	因此在印出字串時，寫出了  printf ("Time: %d hr/Distance: %d km\n", i, i++*speed); 這樣的敘述 
	以為會是 取得第一個i -> 取得i*speed -> i += 1 這樣的執行順序
	但是卻產生了意外之外的結果，後面的i*speed是正常的，前面的i卻被+1了
	於是便開始和朋友一連串的實驗和討論，最後得出的結果請見下方Code
	
	能對C語言有更多的認識真是一件令人開心的事！ 
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
		    實驗結果:
			    從右往左看變數 左++先遞增 > (右++取值 > 右++遞增) LOOP > 左++ & 一般變數取值 
		*/ 
		
	/*for (i = 1; i <= time; i++)
		printf ("Time: %d hr/Distance: %d km\n", i, i*speed);*/
		//等價的for版本 
}
