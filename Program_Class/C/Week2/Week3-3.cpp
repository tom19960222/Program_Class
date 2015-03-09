#include <stdio.h> 

int main ()
{
	int num;
	printf ("Input a number (1~10): ");
	scanf("%d", &num);
	
	if (num == 1)
		printf ("I\n");
	else if (num == 2)
	    printf ("II\n");
    else if (num == 3)
	    printf ("III\n");
	else if (num == 4)
	    printf ("IV\n");	    
	else if (num == 5)
	    printf ("V\n");
	else if (num == 6)
	    printf ("VI\n");
	else if (num == 7)
	    printf ("VII\n");
	else if (num == 8)
	    printf ("VIII\n");
	else if (num == 9)
	    printf ("IX\n");
	else if (num == 10)
	    printf ("X\n");
	else
		printf ("Wrong input!\n");
	    
	return 0;
}
