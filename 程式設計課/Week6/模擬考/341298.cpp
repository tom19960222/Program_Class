#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{int a[20];

int i;


srand(time(0));
	
for(i=0;i<20;i++){
	a[i]=rand()%61+40;
	printf("%d ",a[i]);
}	
} 

