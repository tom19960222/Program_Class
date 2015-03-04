/* 懶得多寫一個版本了 把每個要算的都寫出來了*/
#include <stdio.h>

int main ()
{
	int num, failed_count=0, total_count=0, score[100], failed_sum=0, passed_sum=0;
	
	printf ("Please input scores (-1 to exit): ");
	
	while (1)
	{
		scanf ("%d", &num);
		if (num == -1) break;
		if (num < 60) 
		{
			score[failed_count] = num;
			failed_count++;
			failed_sum += num;
		} 
		else
			passed_sum += num;
		total_count++;
	}
	
	printf ("There are %d people in total, %d people failed, %d people passed.\n", total_count, failed_count, total_count-failed_count);
	printf ("The average score of failed people is %.2f, passed people is %.2f, all people is %.2f", (float)failed_sum/failed_count, (float)passed_sum/(total_count-failed_count), (float)(failed_sum+passed_sum)/total_count);
	
	return 0;
}
