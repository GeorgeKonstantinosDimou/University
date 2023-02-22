#include <stdio.h>
#include <strlib.h>

#define Size1 23
#define Size2 2

void fillbandname(int rows,string array[]);
void fillschedule(int rows,int columns,string array[],double matrix[rows][columns]);
void fillpresentbands(int rows,int columns,double matrix[rows][columns],int arrayPresent[]);
int results(int arrayPresent[]);

string bandsname[Size1] = {

    "Accept",
    "Anthrax",
    "Black Sabbath",
    "Dio",
    "Helloween",
    "Iron Maiden",
    "Judas Priest",
    "Manowar",
    "Megadeth",
    "Metallica",
    "Mötley Crüe",
    "Nazareth",
    "Ozzy",
    "Pantera",
    "Queensrÿche",
    "Rammstein",
    "Raven",
    "Sabaton",
    "Saxon",
    "Scorpions",
    "Sepultura",
    "Slayer",
    "W.A.S.P.",
 };

double tableofSchedule[23][2] = {

    {20.00,23.00},
    {22.00,24.00},
    {19.00,20.00},
    {18.00,22.00},
    {19.00,21.00},
    {19.00,20.00},
    {21.00,23.00},
    {20.00,22.00},
    {20.00,21.00},
    {19.00,21.00},
    {20.00,22.00},
    {22.00,23.00},
    {18.00,21.00},
    {18.00,22.00},
    {23.00,24.00},
    {22.00,24.00},
    {19.00,24.00},
    {21.00,22.00},
    {20.00,23.00},
    {22.00,24.00},
    {19.00,23.00},
    {18.00,20.00},
    {20.00,21.00}
};



int main(){

int i;
int presentBands[7];


//fillbandname(Size1,bandsname);                            Η ΣΥΝΑΡΤΗΣΗ ΑΥΤΗ ΕΙΝΑΙ ΓΙΑ ΤΟ ΓΕΜΙΣΜΑ ΤΟΥ ΠΙΝΑΚΑ ΤΩΝ ΟΝΟΜΑΤΩΝ ΣΕ ΠΕΡΙΠΤΩΣΗ ΠΟΥ ΔΕΝ ΔΙΝΕΤΑΙ ΩΣ ΔΕΔΟΜΕΝΟΣ
//fillschedule(Size1,Size2,bandsname,tableofSchedule);      Η ΣΥΝΑΡΤΗΣΗ ΑΥΤΗ ΕΙΝΑΙ ΓΙΑ ΤΟ ΓΕΜΙΣΜΑ ΤΩΝ ΑΦΙΞΕΩΝ ΣΕ ΠΕΡΙΠΤΩΣΗ ΠΟΥ ΔΕΝ ΔΙΝΕΤΑΙ ΩΣ ΔΕΔΟΜΕΝΟΣ

 for(i=0;i<7;i++){
    presentBands[i] = 0;
 }

fillpresentbands(Size1,Size2,tableofSchedule,presentBands);     //ΜΟΥ ΕΠΙΣΤΡΕΦΕΙ ΕΝΑΝ ΠΙΝΑΚΑ presentBands που δείχνει ποσα συγκροτηματα υπαρχουν παρων στο bazzar
printf("The Best time to Party will be at %d!!!!!!!!\n",results(presentBands)); // ΒΡΙΣΚΕΙ ΤΗΝ ΚΑΛΥΤΕΡΗ ΩΡΑ

}


void fillbandname(int rows,string array[]){

int i;

 for(i=0;i<rows;i++){
    printf("Give me the Bands name: ");
    scanf("%s",&array[i]);
 }
}

void fillschedule(int rows,int columns,string array[],double matrix[rows][columns]){

int i;
 for(i=0;i<rows;i++){
    printf("Give me %s's time of arrival: ",array[i]);
    scanf("%g",&matrix[i][0]);
    printf("Give me %s's time of departure: ",array[i]);
    scanf("%g",&matrix[i][1]);
 }
}

void fillpresentbands(int rows,int columns,double matrix[rows][columns],int arrayPresent[]){

int i,sum = 0;
int departures[7];

 for(i=0;i<7;i++){
    departures[i] = 0;
 }



 for(i=0;i<rows;i++){                                    //Ο ΠΙΝΑΚΑΣ arrayPresent ΠΕΡΙΕΧΕΙ ΤΟ ΣΥΝΟΛΟ ΤΩΝ ΣΥΓΚΡΩΤΗΜΑΤΩΝ ΠΟΥ ΒΡΙΣΚΟΝΤΑΙ ΣΤΗΝ ΕΚΔΗΛΩΣΗ
        if(matrix[i][0] == 18.00 ){                      //ΑΝΑ ΩΡΑ.
            arrayPresent[0]++;
     }
        else if(matrix[i][0] == 19.00){
            arrayPresent[1]++;
        }
        else if(matrix[i][0] ==  20.00){
            arrayPresent[2]++;
        }
        else if(matrix[i][0] ==  21.00){
            arrayPresent[3]++;
        }
        else if(matrix[i][0] ==  22.00){
            arrayPresent[4]++;
        }
        else if(matrix[i][0] == 23.00 ){
            arrayPresent[5]++;
        }
        else{
            arrayPresent[6]++;
        }


    if(matrix[i][1] == 18.00){
            departures[0]--;
     }
        else if(matrix[i][1] == 19.00){
            departures[1]--;
        }
        else if(matrix[i][1] ==  20.00){
           departures[2]--;
        }
        else if(matrix[i][1] ==  21.00){
           departures[3]--;
        }
        else if(matrix[i][1] ==  22.00){
            departures[4]--;
        }
        else if(matrix[i][1] ==  23.00){
           departures[5]--;
        }
        else{
           departures[6]--;
        }
  }

  for(i=0;i<7;i++){
    sum += arrayPresent[i] + departures[i];  //O departures ΠΡΟΣΤΙΘΕΤΑΙ ΓΙΑΤΙ ΟΛΕΣ ΟΙ ΤΙΜΕΣ ΤΟΥ ΕΙΝΑΙ ΑΡΝΗΤΙΚΕΣ
    arrayPresent[i] = sum;
  }
 }

int results(int arrayPresent[]){

int i,potition,max = 0;

 for(i=0;i<7;i++){
    if(arrayPresent[i] > max){max = arrayPresent[i];
        potition = i;
    }
 }

 if(potition == 0)return 18;
 else if (potition == 1)return 19;
 else if (potition == 2)return 20;
 else if (potition == 3)return 21;
 else if (potition == 4)return 22;
 else if (potition == 5)return 23;
 else if (potition == 6)return 24;
}
