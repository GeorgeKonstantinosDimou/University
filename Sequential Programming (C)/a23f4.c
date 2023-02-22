#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool Valid_Time(int hours,int minutes,int seconds);

int main(){

int x,z,y;

//ыяес
printf("Dwse tis ores:");
x = GetInteger();

//кепта
printf("Dwse ta lepta:");
z = GetInteger();

//деутеяокепта
printf("Dwse ta defterolepta:");
y = GetInteger();

if(Valid_Time(x,z,y))printf("WRA EGKYRH");
else printf("WRA MH EGKYRH");
}

bool Valid_Time(int hours,int minutes,int seconds){

return((hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59) && (seconds >= 0 && seconds <= 59) ) ;
}
