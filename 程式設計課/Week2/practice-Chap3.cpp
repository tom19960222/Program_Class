/*
    實作題01
	int x=y=z=1; 
	z = ++x-y++;
	z = z + x++ + ++y;
	預測x, y, z為: 3, 3, 6 
	
	分析:
	z = 2 - 1;      -> z = 1, x = 2
	y += 1;         -> y = 2
	
	y += 1;         -> y = 3
	z = 1 + 2 + 3;  -> z = 6
	x += 1          -> x = 3
	 
*/

#include <stdio.h>
int main()
{
	int x, y, z;
	x=y=z=1; 
	z = ++x-y++;
	z = z + x++ + ++y;
	printf ("x = %d, y = %d, z = %d", x, y, z);
	return 0;
}
