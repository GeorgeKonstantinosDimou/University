#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    long timh,plithos;
    double fpa,poso;

    printf("Dwse thn timh temaxiou: ");
    timh = GetLong();
    printf("Dwse to plithos twn temaxiwn: ");
    plithos = GetLong();
    printf("Dwse to pososto tou fpa: ");
    fpa = GetReal();
    poso = timh*plithos +(timh*plithos)*fpa;
    printf("To kostos ths paragelias einai: %g\n",poso);
    system("pause");
}
