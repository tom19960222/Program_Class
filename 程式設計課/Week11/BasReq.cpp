#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

typedef struct {
	int StudID;        // nine digits
    int W[10];         // grade of week i
    float BasR;        // average from W[0] ~ W[9]
} BasReq;

float GetAvarageScore (BasReq stu)
{
	int i;
	float avg = 0;
	for (i = 0; i < 10; i++)
		avg += stu.W[i];
		
	return avg / 10;
}

void PrintBasReq(BasReq stu)
{
	int i;
	printf ("  %d  %.1f", stu.StudID, stu.BasR);
	for (i = 0; i < 10; i++)
		printf ("%5d", stu.W[i]);
		
}

void PrintAllBasReq(BasReq BR[])
{
	int i;
	printf ("     ID      BasR  W01  W02  W03  W04  W05  W06  W07  W08  W09  W10\n");
	printf ("--------------------------------------------------------------------\n");
	for (i = 0; i < 3; i++)
		{  PrintBasReq(BR[i]);  printf ("\n");  }
	printf ("\n--------------------------------------------------------------------\n");
}

int main()
{
	int i, j;
	srand(time(NULL));
	
	BasReq BR[MAX]=
	{  
     {499410001,{0,0,0,0,0,0,0,0,0,0},0},
     {499410002,{0,0,0,0,0,0,0,0,0,0},0},
     {499410003,{0,0,0,0,0,0,0,0,0,0},0},
  	};
  	
  	for (i = 0; i < 3; i++)
  	{
  		for (j = 0; j < 10; j++)
  			BR[i].W[j] = rand() % 101;
  	}
	for (i = 0; i < 3; i++)
		BR[i].BasR = GetAvarageScore(BR[i]);
	PrintAllBasReq(BR);
	
	return 0;
}
