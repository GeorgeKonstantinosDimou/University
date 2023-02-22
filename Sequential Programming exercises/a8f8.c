#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int width;
    int height;
    int depth;
    int area;
    int volume;
}cuboid;

void dimension(cuboid *box);
void areacalc(cuboid *box);
void volcalc(cuboid *box);

int main(){

cuboid box;

dimension(&box);
areacalc(&box);
volcalc(&box);

printf("To emvadon tou koutiou einai %d cm2\n",box.area);
printf("O ogkos tou koutiou einai %d cm3\n",box.volume);

}


void dimension(cuboid *box){


printf("Dose to mikos tou koutiou se cm:");
scanf("%d",&(*box).width);

printf("Dose to ypsos tou koutiou se cm:");
scanf("%d",&(*box).height);

printf("Dose to vathos tou koutiou se cm:");
scanf("%d",&(*box).depth);

}

void areacalc(cuboid *box){


box->area = 2*(box->width * box->depth + box->width * box->height + box->depth * box->height);
}

void volcalc(cuboid *box){


box->volume = box->width * box->height * box->depth;
}
