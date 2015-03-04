#include <stdio.h>
#define TRUE  1
#define FALSE 0

int IsLowerLetter (char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return TRUE;
	else
		return FALSE;
}

char ToLowerLetter (char ch)
{
	return ch + 32;
}

char ToUpperLetter (char ch)
{
	return ch - 32;
}

int main ()
{
	char in;
	printf ("Please input one letter: ");
	scanf ("%c", &in);
	if (((in >= 'a' && in <= 'z') ||  (in >= 'A' && in <= 'Z'))) // Is a letter
		printf ("%c", (IsLowerLetter(in)) ? ToUpperLetter (in) : ToLowerLetter(in));
	else
		printf ("What you input is not a letter.\n");
} 
