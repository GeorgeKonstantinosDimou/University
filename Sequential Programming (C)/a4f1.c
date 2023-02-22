#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){

int rate;
double saleAmount,profit;
long purchaseAmount;

printf("Dwse thn katharh axia:");
purchaseAmount = GetLong();


printf("\nDwse to pososto kerdous: ");
rate = GetInteger();


profit = purchaseAmount*rate/100.0;
printf("\nTo kerdos tou emporou einai:%g\n",profit);


saleAmount = profit + purchaseAmount ;
printf("\nTo synoliko poso einai:%g\n",saleAmount);

}
