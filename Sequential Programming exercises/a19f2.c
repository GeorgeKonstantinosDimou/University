#include <simpio.h>

int main(){

float roadtax;
int co2gramms;

printf("Dwse gram C02/khm:");
co2gramms = GetInteger();

if(co2gramms <=120){
    roadtax = co2gramms * 0.9;
}
else if(co2gramms <= 140){
    roadtax = co2gramms * 1.1;
}
else{
    roadtax = co2gramms * 1.7;
}
printf("To poso pliromis einai:%f",roadtax);
}

