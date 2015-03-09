/*
    輸入一串數字，取其最大最小值
	難易度：簡單 完成度：100% 成就感：普通
	
	非常典型的簡單競賽題，通常要注意的部分是如果只有輸入一個測資，則兩筆資料都要一次更新 
	另一個要注意的部分則是-99是否要列入計算，或是單純作為控制用途 
*/ 
#include <stdio.h>
#include <math.h> 

int max (int n1, int n2)
{
	return (n1 > n2) ? n1 : n2;
}

int min (int n1, int n2)
{
	return (n1 < n2) ? n1 : n2;
}

int main()
{
	int Max = 0, Min = 0, temp;
	
	scanf ("%d", &temp);
	
	/* Deal with some special inputs.
	   When there is only one input "-99" -> exit program.
	   When there are two inputs: (a number) and -99 -> Min and Max are set to the number, and then exit the program.
	*/
	
	if (temp != -99) Min = Max = temp;
	else return 0;
	 
	do 
	{
		scanf ("%d", &temp);
		if (temp == -99) break;
		Max = max(Max, temp);
		Min = min(Min, temp);
	} while (temp != -99);
	
	printf ("\nInput ended.\n");
	printf ("Max = %d, Min = %d", Max, Min);
	
	return 0;
}
