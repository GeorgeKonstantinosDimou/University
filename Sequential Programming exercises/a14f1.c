#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){

int weight, height , age ;
float BMR;

printf("Dwse varos se kila:");
weight = GetInteger();

printf("Dwse upsos se kila:");
height = GetInteger();

printf("Dwse ilikia se xronia:");
age = GetInteger();

//ейтупысг апотекеслатым

BMR = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
printf("To BMR einai:%f",BMR);

}
