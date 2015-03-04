 /*
  Author: Hsing-Tai Chung
  Date: 2014, 11, 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX 700
 
// fill the number in d[N][N] from 1 to sizexsize horizontally (row major)
void hwalk(int d[][MAX], int N){
 
   int num=1;
   for(int i=0;i<N;i++){
    for (int j=0;j<N;j++)
     d[i][j] = num++; 
  }
}
 
// shuffle the numbers in d[N][N] to make it random
void shuffle(int d[][MAX], int N){
    int row=0, col=0;
    int temp;
    srand(time(NULL));
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
           // randomly choose a position
      row = rand()%N;
      col = rand()%N;
      // swap two numbers (d[i][j], d[row][col])
      temp = d[row][col];     
      d[row][col] = d[i][j];
           d[i][j] = temp;
        }  
    }
}
 
 
// randomly fill the numbers from 1 to NxN
void randomWalk(int d[][MAX], int N){
 
   hwalk(d,N);    // initially fill the numbers in d[N][N] in row major
   shuffle(d,N);  // shuffle the numbers in d[N][N]
 
}
 
// print two-dimensional array d[N][N]
void prarray(int d[][MAX], int N){
   for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%4d", d[i][j]);
    printf("\n");
   }  
}
 
int main(){
   int data[MAX][MAX]={0};
   int N;
   
   //printf("Enter N: ");
   //scanf("%d", &N);
   N=700;
   randomWalk(data,N);   // make the numbers in data[N][N] random 
   //prarray(data,N);      // print the array data[N][N]
}
