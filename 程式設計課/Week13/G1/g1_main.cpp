#include "g1.h"

int main()
{
    Lotto lotto;
    srand(time(NULL));
    
    printf("Enter the year: ");
    scanf("%d",&lotto.date.year);
    printf("Enter the month: ");
    scanf("%d",&lotto.date.month);
    printf("Enter the days: ");
    scanf("%d",&lotto.date.day);
    printf("Random generating 6 lotto numbers ... \n");  
    for(int i=0;i<6;i++)
    {
        do
        {
            lotto.num[i]=1+rand()%49;
        }while (duplicate(lotto.num,i));
    }
    
    printf ("Any winner (Y/N)? ");
    if (toupper(getch()) == 'Y')
    {
    	printf ("\nEnter name: ");
    	lotto.winner = (char*)malloc(sizeof(char) * 100);
    	fflush(stdin);
    	fgets(lotto.winner, 100, stdin);
    }
    prlotto(lotto);
    //prarray(lotto.num,6);
}

