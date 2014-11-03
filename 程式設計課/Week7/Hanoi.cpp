#include <stdio.h>
 
void Move (int n, char peg1, char peg2, char peg3)
{
    if (n == 1)
    {
        printf("%c -> %c\n", peg1, peg3);
 
    }
    else
    {
        Move (n-1, peg1, peg3, peg2);
        printf ("%c -> %c\n", peg1, peg3);
        Move (n-1, peg2, peg1, peg3);
    }
}
 
int main()
{
    int n;
    scanf ("%d", &n);
    Move (n, 'A', 'B', 'C');
    return 0;
}
