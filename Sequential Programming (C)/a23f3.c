#include <stdio.h>
#include "simpio.h"

int main(){

int i,x,numb;

printf("Enter number:");
numb = GetInteger();

if(numb%2 == 0) x = 0 ;
else x = 1;

for(i=x;i<=numb;i+=2){
    printf("%d ",i);
}
}
