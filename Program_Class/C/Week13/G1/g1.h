#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
 
struct Date
{
    int year;
    int month;
    int day;
};
 
struct Lotto
{
    Date date;
    int num[6];
    char* winner = NULL;
};

void prarray(int s[],int size);
 
int duplicate(int num[], int pos);

void prlotto(Lotto lotto);
