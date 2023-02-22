#include <stdio.h>
#include "genlib.h"
#include <math.h>

int main()
{
    int year = 0;
    long Exhange = 13500000;

    while(Exhange > 7500000)
    {
        Exhange = ceil(Exhange*(1-0.025));
        year += 1 ;
    }
    printf("%d\n",year);
    printf("%ld\n",Exhange);
}
