#include <stdio.h>

int main()
{
	float discount = 1;
	int units;
	
	printf ("Units: ");
	scanf ("%d", &units);
	
	if (units >= 10 && units < 20)
		discount = 0.8;
	else if (units >= 20 && units < 50)
		discount = 0.7;
	else if (units >= 50 && units < 100)
		discount = 0.6;
	else if (units > 100)
		discount = 0.5;
		
	printf ("Cost: %.0f", units*100*discount);
	return 0;
}
