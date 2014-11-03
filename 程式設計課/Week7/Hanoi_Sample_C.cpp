#include <stdio.h>
 
void Move (int n, char from, char buffer, char to)
{
    if (n == 1)
    {
        printf("%c -> %c\n", from, to);
 
    }
    else
    {
        Move (n-1, from, to, buffer);
        printf ("%c -> %c\n", from, to);
        Move (n-1, buffer, from, to);
    }
}
 
int main()
{
    int n;
    scanf ("%d", &n);
    Move (n, 'A', 'B', 'C');
    return 0;
}
