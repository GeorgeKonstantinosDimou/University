#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define cardSize 16

long long GetLongLong(void);
bool firstcheck(long long array[]);
void oddcheck(long long array[]);
bool results(long long array[]);


int main(){

int count = 0;
long long cardnumber, number;  /* ха тгм вяеиасты нама тгм аявийг тилг */
long long cardNumb[cardSize];

number = cardnumber;

printf("Insert card number:");
cardnumber = GetLongLong();
while(cardnumber != 0){
    cardnumber /= 10;
    count++;
}

if(count != 0){

count = 0 ;
cardnumber = number;

while(cardnumber!=0){
    cardNumb[count] = cardnumber % 10;
    cardnumber /= 10;
    count++;
}
}

if(count==15 && firstcheck(cardNumb)){
    oddcheck(cardNumb);
    if(results) printf("%llg is VALID",cardnumber);
    else printf("%llg is invalid",cardnumber);
}
}

bool firstcheck(long long array[]){

if(array[0] < 4 || array[0] > 7 ) return FALSE;
else return TRUE;
}

void oddcheck(long long array[]){

int i;

for(i=1;i<16;i+=2){
    array[i] *= 2;
    if (array[i] % 10 != array[i]){
        array[i] = array[i] % 10 + 1;
    }
}
}

bool results(long long array[]){

int i,sum = 0 ;

for(i=0;i<16;i++){
    sum += array[i];
}

if(sum%10 == 0)return TRUE;
else return FALSE;
}

long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}
