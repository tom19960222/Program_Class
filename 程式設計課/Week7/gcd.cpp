#include <stdio.h>

void swap (int *a, int *b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

int gcd_old (int m, int n)
{
	if (m == 1 || n == 1) return 1;
	if (m < n)
		swap(&m, &n);
	if (n == 0) return m;
	
	return gcd_old(m-n,n);	
}

int gcd (int m, int n)
{
	if (n == 0) return m;
	else return gcd (n, m % n);
}

int main()
{
	int n1, n2;
	
	printf ("Please input 2 numbers: ");
	scanf ("%d %d", &n1, &n2);
	printf ("gcd_old: %d\n", gcd_old(n1,n2));
	printf ("gcd: %d\n", gcd(n1,n2));
	return 0;
}
