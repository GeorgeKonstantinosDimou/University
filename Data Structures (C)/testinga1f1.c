#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 200

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isPrime(int n);
void createPrimeSet(typos_synolou syn1,int first,int last);
void displayset(typos_synolou set,int first,int last);

int main(){

    int first,last,x,n;
    typos_synolou synolo1;

        printf("Please give numbers in the [2,200] space\n");
        do{
            printf("Give me the first number:");
            scanf("%d",&first);
        }while(first<2);

        do{
            printf("Give me the last number:");
            scanf("%d",&last);
        }while(last>200 || first>last);

    createPrimeSet(synolo1,first,last);
    displayset(synolo1,first,last);
}

boolean isPrime(int n){

    int i,flag = 0;

     for (i = 2; i <= n /2; ++i) {
        // condition for non-prime
        if (n % i == 0) {
        flag = 1;
        break;
        }
    }
        if(flag==0)return TRUE;
        else return FALSE;
}

void createPrimeSet(typos_synolou syn1,int first,int last){

    int i;

    Dimiourgia(syn1);
    for(i=first;i<=last;i++){
        if(isPrime(i)){
            Eisagogi(i,syn1);
        }
    }
}

void displayset(typos_synolou set,int first,int last)
{
	stoixeio_synolou i;

	for (i=first;i <= last;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
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
