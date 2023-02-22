#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){

long code;
double yearly_payment, weekly_payment,paymentPerHour;
int work_hours;

printf("Dwse ton kwdiko:");
code = GetLong();



if (code >= 1000){
    printf("Dwse ton ethsio mistho:");
    yearly_payment = GetReal();
    weekly_payment = yearly_payment/52;
}
else{
    printf("Dwse tis wres ebdomadiaias ergasias:");
    work_hours = GetInteger();
    printf("Dwse thn amoibh ana wra:");
    paymentPerHour = GetReal();
    weekly_payment = paymentPerHour * work_hours;
    if(work_hours > 40){
        weekly_payment += (work_hours - 40 )*paymentPerHour*50/100;

    }
}
printf("H ebdomadiaia amoibh einai:%g",weekly_payment);
}
