#include<stdio.h>

int palindrome(int num){
	int Num[5],i;
	for(int i=0;i<5;i++){
		Num[i] = num % 10 ; num = num / 10;
	}
	if(Num[0]==Num[4]&&Num[1]==Num[3])
	  return 1;
	else
	  return 0;  
}

int NxN_table(int N){
	int i,j;
	for(int i=1;i<=N;i++){
		printf("%4d",i);
	}
}

int main(){
	int option,num,stop=0;
	
	while(1){
		printf("1.Palindrome\n2 for N*N table\n3.Exit\n=>");
		scanf("%d",&option);
		
		switch(option){
			case 1:
				
				printf("\nEnter a five-digit number:");
				scanf("%d",&num);
				
				if(palindrome(num))
				 printf("%d is a palindrome number.\n",num);
			    else
			     printf("%d is not a palindrome number.\n",num);
			    printf("\n");
				break; 
			case 2:
				
				printf("\nEnter N :");
				scanf("%d",num);
				NxN_table(num);
				printf("\n");
				break;
				
				
			case 3:
			  stop=1;
			  break;	
		}
	    if(stop)break; 
	}
   return 0;
}
