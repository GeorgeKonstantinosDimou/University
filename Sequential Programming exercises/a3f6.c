#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

void swap(int *x,int *y);

main()
{
    int A,B,C;

    printf("Dwse ton Arithmo gia to A: ");
    A = GetInteger();
    printf("Dwse ton Arithmo gia to B:" );
    B = GetInteger();
    printf("Dwse ton Arithmo gia to C: ");
    C = GetInteger();
    if(A>B && A>C)
    {
        swap(&A,&C);
        if(A>B)
        {
            swap(&A,&B);
        }
    }
    else
    {
        if(B>C)
        {
            swap(&B,&C);
            if(B<A)
            {
                swap(&A,&B);
            }
        }
        else
        {
            if(A>B)
            {
                swap(&A,&B);
            }
        }
    }
    printf("%d<%d<%d\n",A,B,C);
    system("pause");
}
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
