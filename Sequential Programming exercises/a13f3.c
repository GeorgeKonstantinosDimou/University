#include <stdio.h>
#include "simpio.h"

int main(){

int limit,i;
float sum;

printf("Dwse to orio:");
limit = GetInteger();

sum = 1;

for(i=2;i<=limit;i++){
    sum = sum + (1.0 /i) ;
}
printf("To athroisma einai %.2f",sum);
}
