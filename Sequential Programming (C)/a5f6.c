#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void Read(int pinakas[100],int N);
void ReadAB(int *A,int *B);
int metaji(int A,int B,int *plithosA,int *plithosB,int pinakas[100],int N);
void Print(int A,int B,int plithosA,int plithosB,int plithosAB,int pinakas[100],int N);

main()
{
    int plithos,pinakas[100],A,B,plithosA,plithosB,plithosAB,N;

    printf("Dwse thn timi tou N: ");
    N = GetInteger();
    Read(pinakas,N);
    ReadAB(&A,&B);
    plithosAB = metaji(A,B,&plithosA,&plithosB,pinakas,N);
    Print(A,B,plithosA,plithosB,plithosAB,pinakas,N);
    system("pause");
}
void Read(int pinakas[100],int N)
{
    int i;

    for(i=0; i<N; i++)
    {
        printf("?\n");
        pinakas[i] = GetInteger();
    }
}
void ReadAB(int *A,int *B)
{
    printf("Dwse mou ton Arithmo A: ");
    *A = GetInteger();
    printf("Dwse mou ton Arithmo B: ");
    *B = GetInteger();
}
int metaji(int A,int B,int *plithosA,int *plithosB,int pinakas[100],int N)
{
    int i,plithos;

    plithos=*plithosA=*plithosB=0;
    for(i=0; i<N; i++)
    {
        if(pinakas[i]<=A)
        {
            *plithosA +=1;
        }
        else if(pinakas[i]>=B)
        {
            *plithosB +=1;
        }
        else
        {
            plithos +=1;
        }
    }
    return(plithos);
}
void Print(int A,int B,int plithosA,int plithosB,int plithosAB,int pinakas[100],int N)
{
    int i;

    for(i=0; i<N; i++)
    {
        printf("%d ",pinakas[i]);
    }
    printf("\n");
    printf("O arithmos A einai: %d\n",A);
    printf("O arthmos B einai : %d\n",B);
    printf("To plithos twn arithmwn pou einai mikroteroi h isi tou %d einai : %d\n",A,plithosA);
    printf("To plithos twn  arithmwn pou einai megaliteroi h isi tou %d einai: %d\n",B,plithosB);
    printf("Kai autoi pou einai metaji twn %d kai %d einai :%d\n",A,B,plithosAB);
}
