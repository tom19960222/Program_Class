#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


struct Date
{
    int year;
    int month;
    int day;
};
typedef struct Date Date;
 
/* information for a winner */
struct WinnerInfo{
   char *name;
   char *id;
   int moneywin;
   WinnerInfo *next;
}; 
typedef struct WinnerInfo WinnerInfo;

/* information for a lotto */
struct Lotto
{
	int id;             // lotto id
    Date date;          // opening date
    int num[6];         // winning numbers
    int winnerCount;    // number of winners
    WinnerInfo *winners;  // winners info
    Lotto *next;
};
typedef struct Lotto Lotto;
