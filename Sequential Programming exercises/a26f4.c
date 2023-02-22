#include <stdio.h>
#include "simpio.h"

int f_function(int x);
int g_function(int x,int y);

int main(){

int numb1,numb2;

printf("Enter x:");
numb1 = GetInteger();

printf("Enter y:");
numb2 = GetInteger();

printf("f(x) = f(%d) = %d\n " ,numb1,f_function(numb1));
printf("g(x,y) = g(%d,%d) = %d\n ", numb1,numb2,g_function(numb1,numb2));
printf("f(g(x,y)) = f(g(%d,%d)) = %d\n",numb1,numb2,f_function(g_function(numb1,numb2)));
}

int f_function(int x){

int result_of_f ;

if(x>0) result_of_f = x +2 ;
else result_of_f = -3 * x + 7;

return result_of_f;
}

int g_function(int x, int y){

int result_of_g;

if(x > 0 && y > 0 ) result_of_g = x - y;
else result_of_g = 7 * x - 5;

return result_of_g ;
}
