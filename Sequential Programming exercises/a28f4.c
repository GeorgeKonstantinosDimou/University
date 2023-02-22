#include <stdio.h>
#include "simpio.h"
#include "math.h"

int get_code();
float discount_percentage(int code);
int product_points(int code,double fprice);

int main(){

int code,points;
double price,finalPrice,total,discount,discountSum;
total = discountSum = 0;
points = 0;

while(code = get_code()){
    printf("Dwse thn timh: ");
    price = GetReal();

    discount = discount_percentage(code)* price;
    discountSum += discount;
    finalPrice = price - discount;
    total += finalPrice;
    points += product_points(code,finalPrice);
}
printf("-------------\n");
printf("Teliko synolo: %.2f Euro\n",total);
printf("Ekptwsh: %.2f Euro\n", discountSum);
printf("Pontoi: %d\n",points);
return 0;
}


int get_code(){

int code ;

do{
    printf("Dwse kwdiko: ");
    code = GetInteger();
    if (code < 0 || code > 2000){
        printf("Lathos kwdikos (0-2000)\n");
    }
}while(code < 0  || code > 2000);
}

float discount_percentage(int code){

if(code>0 && code<=300)return 0.05;
else if (code<=500)return 0.10;
else if (code<=1000)return 0.15;
else return 0.2;
}

int product_points(int code,double fprice){

int points = 1 ;
if (code >=1000 && code<1500)
    points += ceil(fprice/5);
return points;
}

