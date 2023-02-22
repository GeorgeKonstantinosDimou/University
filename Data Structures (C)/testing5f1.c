#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 1000

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);

boolean isFibonacci(int n,typos_synolou fibo);
void createFibonacciSet(int threshold,typos_synolou fibosynolo);

int main(){

    int max,n;
    boolean flag=1;
    typos_synolou synolofibonacci1;

    do{
    printf("Dwse ton megisto arithmo.");
    scanf("%d",&max);
    }while(max<2 && max>1000);

    createFibonacciSet(max,synolofibonacci1);
    displayset(synolofibonacci1);
    while(flag){
        printf("Enter number to check:");
        scanf("%d",&n);
        if(n<0){
            flag=0;
            break;
        }
        if(isFibonacci(n,synolofibonacci1))printf("Fibonacci!\n");
        else printf("Not Fibonacci...\n");
    }
}

void createFibonacciSet(int threshold,typos_synolou fibosynolo){

    int i,f1,f2,tmp;

    Dimiourgia(fibosynolo);
    f1=0;
    f2=1;
    Eisagogi(f1,fibosynolo);
    do{
        Eisagogi(f2,fibosynolo);
        tmp=f1+f2;
        f1=f2;
        f2=tmp;
    }while(f2<=threshold);
}

boolean isFibonacci(int n,typos_synolou fibo){

    if(Melos(n,fibo))return TRUE;
    else return FALSE;
}

void Dimiourgia(typos_synolou synolo){
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo){
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo){
    return synolo[stoixeio];
}

void displayset(typos_synolou set){
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}
