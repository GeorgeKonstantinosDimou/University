#include <stdio.h>
#include "simpio.h"
#include "math.h"

#define sizeStart 5
#define sizeFinish 4

int main(){

int i;
double arrayStart[sizeStart],arrayFinish[sizeFinish];

for(i=0;i<sizeStart;i++){
    printf("Enter number (%d): ",i);
    arrayStart[i] = GetReal();
}

for(i=0;i<sizeFinish;i++){
    arrayFinish[i] = fabs(arrayStart[i+1]-arrayStart[i]);
    printf("%.2f ",arrayFinish[i]);
}
}
