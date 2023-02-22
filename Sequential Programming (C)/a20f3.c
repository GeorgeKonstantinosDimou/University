#include <stdio.h>
#include "simpio.h"

int main(){

int years_old,Max = 0,min = 200;


printf("Dwse ilikia:");
years_old = GetInteger();

while(years_old != -1){
    if(years_old > Max) Max = years_old;
    if(years_old < min) min = years_old;

printf("Dwse ilikia:");
years_old = GetInteger();
}

/*Το if εδω πέρα έγινε για την περίπτωση που
πάρω μόνο μια τιμή η καμία τιμή ώστε να μην
εκτυπώσει την αρχική τιμή του min( 200) που
έδωσα στην αρχή. */

printf("H megalyterh ilikia einai:%d\n",Max);
if(years_old == 200)printf("H mikroterh ilikia einai:0\n");
else printf("H mikroterh ilikia einai:%d\n",min);
}


