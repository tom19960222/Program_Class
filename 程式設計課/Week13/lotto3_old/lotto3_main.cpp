#include "lotto3.h"

/* available functions for main menu */
#define ADD      1   // add a lotto
#define SEARCH   2   // search lotto by date
#define LIST     3   // list summary for some lottos   
#define MODIFY   4   // modify a lotto
#define DELETE   5   // delete a lotto

int main()
{
   Lotto *lotto[MAX];      // pointer array for MAX lottos  
   int lottoCount = 0;     // number of lottos stored
   int choice;             // menu choice
   int n1, n2;             // for selecting the range
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
           lottoCount++;
           lotto[lottoCount] = (Lotto *)malloc(sizeof(struct Lotto)); 
           add(lotto[lottoCount]);
           printf("Add more (Y/N)? ");
         }while(toupper(getch())=='Y');
         
         break;
       case SEARCH:
         
         break;
       case LIST:
         printf("Enter id range: ");
         scanf("%d %d", &n1, &n2);
         listSome(lotto, n1, n2);
         break;
       case MODIFY:
     
         break;
       case DELETE:
     
         break;
     } 
  }
}

