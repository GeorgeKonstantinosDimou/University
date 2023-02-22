#include <stdio.h>
#include "simpio.h"

#define size 5

int main(){

int i,temp;
int array[size];

for(i=0;i<size;i++){
    printf("Enter number: ");
    array[i] = GetReal();
}

temp = array[4];

for(i=3;i>-1;i--){
    array[i+1] = array[i];
}
array[0] = temp;

for(i=0;i<5;i++) printf("%d ",array[i]);
}

