#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


void GetTime(long SysSecs,int *hours,int *minutes,int *seconds);

main()
{
    long deu;
    int  hours,minutes,seconds;

    printf("Enter Device Secs: ");
    deu = GetLong();
    GetTime(deu,&hours,&minutes,&seconds);
    printf("Time is %d:%d:%d:\n",hours,minutes,seconds);
    system("pause");
}
void GetTime(long SysSecs,int *hours,int *minutes,int *seconds)
{
    *hours = SysSecs / 3600;
    SysSecs = SysSecs % 3600;
    *minutes = SysSecs / 60;
    *seconds = SysSecs % 60;
}
