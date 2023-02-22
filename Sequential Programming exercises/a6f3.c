#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int prwtos,deuteros,athrisma,oroi,i;

    printf("Dwse mou to plithos twn orwn ths akolouthias fibonacci: ");
    oroi = GetInteger();
    prwtos = 0;
    deuteros = 1;
    printf("%d\n",prwtos);
    printf("%d\n",deuteros);
    for(i=0; i<oroi-2; i++)
    {
        athrisma = prwtos + deuteros;
        printf("%d\n",athrisma);
        prwtos = deuteros;
        deuteros = athrisma;
    }
    return 0;
}
