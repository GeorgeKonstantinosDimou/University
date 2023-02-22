#include <stdio.h>
#include "simpio.h"
#include "math.h"

#define Arithmo_Aytok 80000
#define orio         160000
#define ru8mos         0.07

int main(){

long  years,telikos_aritmos_autok;

years = 0;
telikos_aritmos_autok = Arithmo_Aytok;

while(telikos_aritmos_autok <= orio){
    telikos_aritmos_autok = ceil(telikos_aritmos_autok *(1+ru8mos));
    years++;
}
printf("%ld\n",years);
printf("%ld\n%",telikos_aritmos_autok);
}
