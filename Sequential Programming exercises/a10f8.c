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
//ptr = (int*)calloc(numbofpackages,sizeof(int));    //думалийг дгкысг пимайа-долгс

ReadWorkpackages(numbofpackages,works, WP);
k = FindFirstWp(numbofpackages,works,WP);           //летабкгтг циа богхеиа стгм ейтупысг

printf("FIRST WP: %s start: %d duration: %d",works[k].name,works[k].startmonth,works[k].duration);

}


void ReadWorkpackages(int packages,workpdictionary works[],workpdictionary WP){

int i;

for(i=0;i<packages;i++){        //сулпкгяысг стоивеиым
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
