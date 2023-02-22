#include <stdio.h>
#include <strlib.h>

#define size 50

void populate(int Size,int arrayA[]);
void printArr(int Size,int arrayA[]);
int checkTable(int Numb,int Size,int arrayA[]);

int main(){

int N,appears;
int a[50];

populate(size,a);
printArr(size,a);

printf("\nDwse arithmo apo to 0 ews to 9: ");
scanf("%d",&N);

appears = checkTable(N,size,a);
printf("o Arithmos %d emfanizetai %d fores",N,appears);
printf("\nStis Theseis:\n");
printArr(appears,a);
printf("----------------------");
return 0;
}

void populate(int Size,int arrayA[]){

int i;

 for(i=0;i<Size;i++){
    arrayA[i] = rand() % 10 ;
 }
}

void printArr(int Size,int arrayA[]){

int i;

 for(i=0;i<Size;i++){
    printf("% d ",arrayA[i]);
 }
 printf("\n----------------");
}

int checkTable(int Numb,int Size,int arrayA[]){

int i,k = 0, NumbofAppears=0;

 for(i=0;i<Size;i++){
    if(arrayA[i]==Numb){arrayA[NumbofAppears] = i;  //амахетгсг тым стоивеиым тоу пимайа а циа летепеита ейтупысг
      NumbofAppears++;
    }
 }
 return NumbofAppears;
}
