#include <stdio.h>
#include <strlib.h>
#include <limits.h>

#define Size 100

int NumbofElement(int size,int array[]);
void findMinMax(int size1,int array[],int *min,int *max);

int main(){

 int x,y,i,k;
 int elemArray[Size];

 k = NumbofElement(100,elemArray);
 findMinMax(k,elemArray,&x,&y);
 printf("The range of values is %d-%d",x,y);
}

int NumbofElement(int size,int array[]){ //ΓΕΜΙΣΜΑ πινακα επιστροφη του μεγέθους του μεσω της i

 int i=0;

 printf("Enter the elements of array, one per line.\n");
 printf("Use -1 to signal the end of the list.\n");

 printf("? ");
 scanf("%d\n",&array[0]);

 while(i<size && array[i] != -1){
    i++;
    printf("? ");
    scanf("%d\n",&array[i]);
 }
 return i;
}


void findMinMax(int size1,int array[],int *min,int *max){ //Ευρεση Min max , στην περίπτωση που θα δωθεί ενας αριθμός μονο το πρόγραμμα θα επιστρέφει τον αριθμό
                                                          //ΚΑΙ ως Min και ως max.
 int i;

 *min = INT_MAX;
 *max = 0;

 for(i=0;i<size1;i++){
    if(array[i] > *max) *max = array[i];
    if(array[i] < *min) *min = array[i];
 }
}
