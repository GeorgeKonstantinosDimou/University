#include <stdio.h>
#include <simpio.h>
#include "genlib.h"

long encode(long N);
bool check(long EN);


int main(){

long i,N,Lower_limit,Upper_limit,y;
char validation;

printf("Lower Limit:");
Lower_limit = GetLong();

printf("Upper Limit:");
Upper_limit = GetLong();

for(i=Lower_limit;i<=Upper_limit;i++){
    printf("Code: %ld Endoding: %ld isValid:%s\n",i,encode(i),check(encode(i))? "yes":"no");
}
}

long encode(long N){

int control_digits;
long result_code;

control_digits = (98-(N*100)%97)%97;
result_code = N * 100 + control_digits ;
return result_code ;
}

bool check(long EN){

return (EN % 97  == 1);
}


