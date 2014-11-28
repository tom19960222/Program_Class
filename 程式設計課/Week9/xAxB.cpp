#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEFAULT_SIZE 100

typedef struct {
	int A;
	int B;
} reply;

reply CheckAns (int* ans, int* input, int size)
{
	reply Reply;
	Reply.A = Reply.B = 0;
	int i, j;
	
	for (i = 0; i < size; i++)
	{
		if (*(ans+i) == *(input+i))
			{ Reply.A++; }
	}
	
	for (i = 0; i < size; i++)
	{
		for (j = 0 ; j < size; j++)
		{
			if (*(ans+i) == *(input+j) && i != j)
				Reply.B++;
		}
	}
	
	return Reply;
}

void Reverse (int *arr, int size)
{		
	int i, j, *temp;
	temp = (int*)malloc(size*sizeof(int));
	for (i = 0; i < size; i++)
		*(temp+i) = *(arr+i);
	for (i = 0, j = size-1; i < size; i++, j--)
		*(arr+j) = *(temp+i);
}

int main()
{
	int size, i;
	char ans_str[100], input_str[100];
	int *ans, *input;
	reply Reply;
	ans   = (int*)malloc(DEFAULT_SIZE*sizeof(int));
	input = (int*)malloc(DEFAULT_SIZE*sizeof(int));
	
	printf ("Please input answer: ");
	fgets(ans_str,100,stdin);
	
	size = strlen(ans_str)-1;
	for (i = 0; i < strlen(ans_str); i++)
		*(ans+i) = ans_str[i] - '0';
	system("cls");
	
	while (1)
	{
		printf ("Please input a %d digits number: ", size);
		fgets(input_str,100,stdin);
		if (strlen(input_str) < size+1)
			{  printf ("Too few digits!\n\n");  continue;  }
		else if (strlen(input_str) > size+1)
			{  printf ("Too many digits!\n\n");  continue;  }
			
		for (i = 0; i < strlen(ans_str); i++)
		*(input+i) = (input_str[i] - '0');
		
		//Reverse(input, size);
		
		Reply = CheckAns(ans, input, size);
		
		if (Reply.A != size)
			printf ("\n%dA%dB\n\n", Reply.A, Reply.B);
		else
			{  printf ("\nCongratulations! You are correct!\n\n");  system("pause"); return 0; }
	}
	
	return 0;
} 
