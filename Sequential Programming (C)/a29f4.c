#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int gcd(int a,int b);
bool coprime(int a,int b);
int Euler(int N);

int main(){

int x,i;

printf("Enter X:");
x = GetInteger();

for(i=1;i<=x;i++){
    printf("phi(%d) = %d\n", i , Euler(i));
}
}

int gcd(int a,int b){

if(b != 0)return gcd(b,a%b);
return a;
}

bool coprime(int a , int b ){

if (gcd(a,b) == 1) return TRUE;
return FALSE;
}

int Euler(int N){

int j,counter = 0 ;

for(j=1;j<=N;j++){
    if(coprime(N,j)) counter++;
}
return counter;
}
