#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main(){

int hours;
long hourlyWage;
double rateOfTaxes, wageWithTaxes ,amountOfTaxes, monthlyWage;

printf("Dwse ton arithmo twn wrwn:");
hours = GetInteger();

printf("Dwse thn wriaia antimisthia:");
hourlyWage = GetLong();

printf("Dwse to pososto twn krathsewn:");
rateOfTaxes = GetReal();

monthlyWage = hours * hourlyWage ;
amountOfTaxes = monthlyWage * rateOfTaxes ;
wageWithTaxes = monthlyWage + amountOfTaxes ;

printf("Oi akatharistes apodoxes einai:%g\n",wageWithTaxes);
printf("Oi krathseis einai:%g\n",amountOfTaxes);
printf("Oi kathares apodoxes einai:%g\n",monthlyWage);






}
