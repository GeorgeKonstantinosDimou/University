#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main()
{
    int Mathites[10][3],plithosapo,plithosepi,i,j;
    double mo;

    for(i=0; i<10; i++)
    {
        printf("Mathitis %d\n",i+1);
        printf("-------------\n");
        for(j=0; j<3; j++)
        {
            printf("Mathima %d :",j+1);
            Mathites[i][j] = GetInteger();
        }
    }
    plithosapo=plithosepi=0;
    for(i=0; i<10; i++)
    {
        mo = 0;
        for(j=0; j<3; j++)
        {
            mo += Mathites[i][j];
        }
        mo = mo/3.0;
        if(mo<9.5)
        {
            plithosapo +=1;
        }
        if(mo > 18.5)
        {
            plithosepi +=1;
        }
    }
    printf("Plithos Apotixhmenwn: %d \n",plithosapo,plithosapo*10);
    printf("Plithos Epitixhmenwn: %d \n",plithosepi,plithosepi*10);
    system("pause");
}
