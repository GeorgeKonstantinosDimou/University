#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int cube(int num);
int sum_cube(int num);
bool isArmostrong(int num);

int main(){
   int i;

   for(i=1;i<=999;i++){
        if (isArmostrong(i)){
            printf("%d\n",i);
        }

   }
}

int cube(int root){
    int product;
    int i;
    product = 1;

    for(i=1;i<=3;i++){
        product *= root;
    }
    return product;
}

int sum_cube(int num){
    int dig3,dig2,dig1;

    dig3 = num/100;
    dig2 = (num % 100) / 10 ;
    dig1 = num % 10;
    return cube(dig1)+ cube(dig2) + cube(dig3);
}

bool isArmostrong(int num){
    return (num == sum_cube(num));

}
