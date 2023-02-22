#include <stdio.h>
#include "simpio.h"
#include "math.h"



int main(){

long  orio,years,telikos_aritmos_autok,arxikos_arithmos;
double rythmos_auxhshs;

years = 0;

printf("Dwse ton arxiko arithmo autokinhtwn:");
arxikos_arithmos = GetLong();

printf("Dwse ton ethsio rythmo ayxhshs:");
rythmos_auxhshs = GetReal();

printf("Dwst to orio:");
orio = GetLong();

telikos_aritmos_autok = arxikos_arithmos;

while(telikos_aritmos_autok <= orio ){
    telikos_aritmos_autok = ceil(arxikos_arithmos *(1+rythmos_auxhshs));
    years++;
}
printf("Se %ld xronia ta autokinhta 8a 3eperasoun to orio\n",years);
printf("Ta autokinhta 8a einai:%ld\n%",telikos_aritmos_autok);
}
