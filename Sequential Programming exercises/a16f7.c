#include <stdio.h>
#include <string.h>

#define size 100

int main(){

int i,k = 0,sum = 0;
char carray[size],numbs[k];

printf("Insert a string:");
gets(carray);

for(i=0;carray[i] != '\0';i++){
    if(carray[i] >= '0' && carray[i] <= '9'){   //екецвос циа аяихлоус-акжаяихлгтийа
        sum += (carray[i] - '0');       //пяосхесг тым акжаяихлгтийым
        numbs[k] = carray[i];           //пимайас поу йяатаеи тоуР аяихслоус-акжаяихлгтийа
        k++;
    }
}

if(sum != 0){                   //ейтупысг апотекеслатым
    printf("%c ",numbs[0]);
    for(i=1;i<k;i++){
        printf("+ %c ",numbs[i]);
    }
    printf("= %d",sum);
}
else{
    printf("No digits in input");
}
}
