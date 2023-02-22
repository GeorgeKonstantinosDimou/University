 #include <stdio.h>
 #include "simpio.h"
 #include "string.h"

 int main(){

 char newN,number;
 char *pnumber;
 int L,counter;

 *pnumber = number;

 printf("Give me the number:%c",number);
 number = getchar();

  printf("\n");

 printf("Give me the Lenght of the new number:%d",L);
 L = GetInteger();

 printf("\n");

 counter = 0;

 while(number!=0){
    number= number/10;
    counter++;
 }

 while (counter < (L-1)){

    *(pnumber-1)= 0;
    counter++;
 }
 }
