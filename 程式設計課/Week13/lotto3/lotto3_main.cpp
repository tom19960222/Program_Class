#include "lotto3.h"

/* available functions for main menu */
/*
#define ADD      1   // add a lotto
#define SEARCH   2   // search lotto by date
#define LIST     3   // list summary for some lottos   
#define MODIFY   4   // modify a lotto
#define DELETE   5   // delete a lotto
*/
enum {ADD=1, SEARCH, LIST, MODIFY, DELETE};

int main()
{
   Lotto *lotto[MAX];      // pointer array for MAX lottos  
   int lottoCount = 0;     // number of lottos stored
   int choice;             // menu choice
   int n1, n2;             // for selecting the range
   int ID;              
   Date searchdate;
   int searchresult[100];
   int i;
   while(1){
     printf("\n\nLotto Menu\n");
     printf("1. Add\n");
     printf("2. Search\n");
     printf("3. List\n");
     printf("4. Modify\n");
     printf("5. Delete\n"); 
     printf("6. Exit\n"); 
     printf("==> ");
     scanf("%d",&choice);
     if(choice==6) break;
     switch(choice){
       case ADD:
         do{             
           lotto[lottoCount] = (Lotto *)malloc(sizeof(struct Lotto)); 
           memset(lotto[lottoCount], 0, sizeof(struct Lotto));
           add(lotto, lotto[lottoCount], lottoCount);
           lottoCount++;
           printf("Add more (Y/N)? \n");
         }while(toupper(getch())=='Y');
         
         break;
       case SEARCH:
         printf ("Search by:\n");
         printf ("  [1] ID\n");
         printf ("  [2] date\n");
         printf ("    => ");
         scanf ("%d", &choice);
         switch(choice)
         {
         	case 1:
         		printf ("Enter ID: ");
         		scanf ("%d", &ID);
         		if (searchbyID(lotto, ID, lottoCount) != -1)
         			list(lotto[searchbyID(lotto, ID, lottoCount)]);
         		else
         			printf ("\nNot found!\n\n");
         	break;
         	case 2:
         		memset(searchresult, 0, sizeof(int)*100);
         		printf ("Enter date: ");
         		scanf ("%d %d %d", &searchdate.year, &searchdate.month, &searchdate.day);
         		if (searchbyDate(lotto, searchdate, lottoCount, searchresult) > 0){
         		for (i = 0; i < searchbyDate(lotto, searchdate, lottoCount, searchresult); i++)
         			list(lotto[searchresult[i]]);
         		}
         		else
         			printf ("Not found!\n\n");
         	break;
         }
         break;
       case LIST:
         printf("Enter id range: ");
         scanf("%d %d", &n1, &n2);
         listSome(lotto, n1, n2, lottoCount);
         break;
       case MODIFY:
     	 printf ("Enter id: ");
     	 scanf ("%d", &ID);
     	 if (getLottoFromId(lotto, ID, lottoCount) != -1){
     	 	modify(lotto[getLottoFromId(lotto, ID, lottoCount)]);
     	 }
     	 		
         break;
       case DELETE:
     	 printf ("Enter id: ");
     	 scanf ("%d", &ID);
     	 if (getLottoFromId(lotto, ID, lottoCount) != -1)
     	 	del(lotto, lotto[getLottoFromId(lotto, ID, lottoCount)], &lottoCount);
     	 else
     	 	printf ("Lotto not found\n");
         break;
     } 
  }
}

