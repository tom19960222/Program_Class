/* 既然老師說不考陣列 那我乾脆也不用陣列了... */ 
/* 寫到一半的OS: WTF 如果不用陣列 又不從檔案輸入測試資料的話 要怎麼印出所有偶數? 不會變成邊打邊印嗎?
   決定還是用陣列了..... XD */ 
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
