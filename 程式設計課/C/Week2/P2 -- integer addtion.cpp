/*
    完成度: 100% 難易度: 簡單 成就感: 低
    
	基本的I/O搭配if...else即可完成的一題 
	原本想要用函式回傳字元指標，搭配三元運算子一口氣寫在一個printf內，但因對指標的瞭解還不夠，BUG連連
	因此還是先使用基本的寫法 
*/

#include <stdio.h> 
#include <stdlib.h>

int main()
{
	int n1, n2, ans, correct;
	
	printf ("Teacher:\nn1: ");
	scanf ("%d", &n1);
	printf ("n2: ");
	scanf ("%d", &n2);
	printf ("Student:\n%d + %d = ? ", n1, n2); 
	scanf ("%d", &ans);
	
	printf ("\n");
	if (n1 + n2 == ans)
		printf ("Correct\n");
	else
		printf ("Wrong\n%d + %d = %d\n", n1, n2, n1+n2);
}
