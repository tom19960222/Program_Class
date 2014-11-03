#include <stdio.h>
 
void tower (int n, char aux, char to, char from)
{
    if (n == 1)
    {
        printf("%c -> %c\n", from, to);
 
    }
    else
    {
        tower (n-1, to, aux, from);
        printf ("%c -> %c\n", from, to);
        tower (n-1, from, to, aux);
    }
}
 
int main()
{
    int n;
    scanf ("%d", &n);
    tower (n, 'B', 'C', 'A');
    return 0;
}
