#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 50

int Plithos();
void Read(int plithos,int A[N]);
void print(int plithos,int A[N]);
int Max(int plithos,int A[N],int index[N]);
main()
{
    int A[50],plitho,plithosindex,index[50],i;

    plitho = Plithos();
    Read(plitho,A);
    print(plitho,A);
    plithosindex = Max(plitho,A,index);
    printf("Maximum : %d\n",A[index[0]]);
    printf("Plithos maximum: %d\n",plithosindex);
    for(i=0; i<plithosindex; i++)
    {
        printf("%d ",index[i]);
    }
    printf("\n");
    system("pause");
}
int Plithos()
{
   int plithos;

   printf("Dwse to plithos twn stoixeiwn: ");
   plithos = GetInteger();
   return(plithos);
}
void Read(int plithos,int A[N])
{
    int i;
    for(i=0; i<plithos; i++)
    {
        A[i] = GetInteger();
    }
}
void print(int plithos,int A[N])
{
    int i;

    for(i=0; i<plithos; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int Max(int plithos,int A[N],int index[50])
{
    int i,plitho,max;

    plitho = 0;
    max = A[0];
    for(i=1; i<plithos; i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }
    }
    for(i=0; i<plithos; i++)
    {
       if(max == A[i])
       {
           index[plitho] = i;
           plitho +=1;
       }
    }
    return(plitho);
}
