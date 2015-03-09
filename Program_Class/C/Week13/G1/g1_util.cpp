#include "g1.h"

void prarray(int s[],int size)
{
   for(int i=0;i<size;i++)
   printf("%4d",s[i]);
}
 
 
int duplicate(int num[], int pos)
{
    for(int i=0;i<pos;i++)
    {
        if(num[i]==num[pos])
          return 1;
    }
    return 0;
} 

void prlotto(Lotto lotto){
    printf("Date: %d/%d/%d\n", lotto.date.year, lotto.date.month, lotto.date.day);
    printf("Winning numbers: ");
    for(int i=0;i<6;i++) printf("%3d",lotto.num[i]);
    printf("\n");
    if (lotto.winner != NULL)
    	printf ("Winner: %s\n", lotto.winner);
    else
    	printf ("No winner\n");
}
