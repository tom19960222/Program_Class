#include <stdio.h>

void prchar(char c, int n){
  for(int i=1;i<=n;i++) printf("%c", c);
}

int main ()
{
	int height, i, j;
	
	while (1)
	{
		printf ("Enter height: ");
		scanf ("%d", &height);
		if (height == -1) break;
		
		putchar('\n');
		i = height; j = 1;
		while (i > 0 && j <= height)
		{
			prchar (' ', height-i);
			prchar ('*', i);
			
			prchar (' ', 2);
			
			prchar ('*', j);
			putchar ('\n');
			i--; j++;
		}
		prchar ('\n', 2);
	}
	printf ("\nBye~\nCoding by 1B-403410144-¬I«T¦Ð\n");
	return 0;
}
