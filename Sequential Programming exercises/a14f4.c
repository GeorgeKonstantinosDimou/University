#include <stdio.h>
#include "simpio.h"

int max(int x,int v);
int gr(int x,int v,int z);

int main(){

int a,b,c;
double y;

printf("Dwse a: ");
a = GetInteger();

printf("Dwse b: ");
b = GetInteger();

printf("Dwse c: ");
c = GetInteger();

y = (2*max(a,b)+3*gr(a,b,c))/4.0;
printf("y = %.2f",y);
}

int max(int x,int v){

if(x>v)return x;
return v;
}

int gr(int x,int v,int z){

if(x>=v && x>z)return x;
else if(v>x && v>z)return v;
return z;
}
