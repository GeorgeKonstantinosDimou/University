#include <stdio.h>
#include <stdlib.h>


typedef struct{

    char name[60];
    int startmonth;
    int duration;
}workpdictionary;

void ReadWorkpackages(int packages,workpdictionary works[],workpdictionary WP);
int FindFirstWp(int packages,workpdictionary works[],workpdictionary WP);

int main(){

int numbofpackages,k;
workpdictionary WP;
workpdictionary works[100];

printf("Total work packages:");
scanf("%d",&numbofpackages);
//ptr = (int*)calloc(numbofpackages,sizeof(int));    //恼土躺是 那速忧 猩土柿-南糖?

ReadWorkpackages(numbofpackages,works, WP);
k = FindFirstWp(numbofpackages,works,WP);           //膛粤滤窃? 蒙? 孪侨派? 釉峭 攀哉匈忧

printf("FIRST WP: %s start: %d duration: %d",works[k].name,works[k].startmonth,works[k].duration);

}


void ReadWorkpackages(int packages,workpdictionary works[],workpdictionary WP){

int i;

for(i=0;i<packages;i++){        //诱绦饲奄忧 釉仙着少?
    printf("WP Name:\n");
    //gets(works[i].name);
    scanf("%s",&works[i].name);

    printf("WP Start Month:\n");
    scanf("%d",&works[i].startmonth);

    printf("WP Duration:");
    scanf("%d",&works[i].duration);
}
}


int FindFirstWp(int packages,workpdictionary works[],workpdictionary WP){

int i,min,index;

min = works[0].startmonth;
index = 0;

for(i=1;i<packages;i++){
    if(works[i].startmonth < min )
        min = works[i].startmonth;
        index = i;
}
return index;
}
