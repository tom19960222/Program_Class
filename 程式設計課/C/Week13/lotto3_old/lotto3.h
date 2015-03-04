/*
   Title: Simple Lotto manager (demo for class)
   Author: HTC
   Date: 12-7-2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100       // for max number of lottos
#define MAXWINNER 20  // for max winners per lotto

struct Date
{
    int year;
    int month;
    int day;
};

/* information for a winner */
struct WinnerInfo{
   char *name;
   char id[10];
   int moneywin;
}; 

/* information for a lotto */
struct Lotto
{
    int id;             // lotto id
    Date date;          // opening date
    int num[6];         // winning numbers
    int winnerCount;    // number of winners
    WinnerInfo *winners[MAXWINNER];  // winners info
};

void add(Lotto *lotto);   // add lotto information
void search(int N);              // search specific lotto infomration 
void list(Lotto *lotto);         // list information of a lotto
void listSome(Lotto *lotto[], int N1, int N2); // list lotto information from N1 to N2
void modify();                   // modify lotto information

void prarray(int s[],int size);  // print array from s[0] to s[size-1]
int duplicate(int num[], int pos);  // check if there is a duplicate number num[pos] from num[0]~num[pos-1]

