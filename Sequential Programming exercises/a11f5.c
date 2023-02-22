#include <stdio.h>
#include "simpio.h"
#include <math.h>

#define CTS 10
#define S 3


int main(){

double temper[CTS][S];
double average[CTS];
double devnat[CTS][S];
double mdeviation[CTS];

double sum = 0;
double natavg = 0;
int i,j;

for(i=0; i<CTS; i++){
    for(j=0; j<S; j++){
        printf("Temp of City %d During %d slot:",i,j);
        temper[i][j] = GetReal();
    }
}

for(i=0; i<CTS; i++){
    for(j=0; j<S; j++){
        sum += temper[i][j];
    }
}
natavg = sum/ (CTS*S);

for(i=0; i<CTS; i++){
    average[i] = 0;
    for(j=0; j<S; j++){
        average[i] +=temper[i][j];
    }
    average[i] = average[i]/S;
}

for(i=0; i<CTS; i++){
    for(j=0; j<S; j++){
        devnat[i][j] = fabs(natavg-temper[i][j]);
    }
}

for(i=0; i<CTS; i++){
    mdeviation[i] = devnat[i][0];
    for(j=0; j<S; j++){
        if(mdeviation[i]<devnat[i][j]){
            mdeviation[i] = devmat[i][j];
        }
    }
}

printf("%.1f\n",natavg);

for(i=0;i<CTS;i++){
    printf("City %d %.1f %.1f\n",i,average[i],mdeviation[i]);
}

return 0;
}
