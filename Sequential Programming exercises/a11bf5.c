#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "math.h"

#define CTS 10
#define S 3

void ReadData(int rows,int columns,double table[rows][columns]);
double CalculateAverage(int rows,int columns,double table[rows][columns]);
void CalculateAvCity(int rows,int columns,double table[rows][columns],double average[rows][columns]);
void CalculateMaxDeviation(int rows,int columns,double table[rows][columns]
                          ,double md[rows]);
void Print_results(int rows, double avg,double average[rows],double md[rows]);

int main(){

double temper[CTS][S];
double natavg;
double average[CTS],mdeviation[CTS];


ReadData(CTS,S,temper);
natavg = CalculateAverage(CTS , S, temper);
CalculateAvCity(CTS, S , temper,average );
CalculateMaxDeviation(CTS, S, temper, mdeviation);
Print_results(CTS,natavg,average,mdeviation);
return 0;
}

void ReadData(int rows,int columns,double table[rows][columns]){
    int i,j;

    for(i=0; i<rows; i++)
        for(j=0; j<columns; j++){
            printf("Temp of City %d 8-hours period: ",i,j);
            table[i][j] = GetReal();
    }
}

double CalculateAverage(int rows,int columns,double table[rows][columns]){
    int i,j;
    double natavg;

    natavg = 0;
    for(i=0;i<rows;i++)
        for(j=0;j<columns;j++)
        natavg +=table[i][j];
    return natavg/(rows*columns);

}

void CalculateAvCity(int rows,int columns ,double table[rows][columns],double average[rows][columns]){
    int i,j;

    for(i=0;j<rows;i++){
        average[i][j]=0;
        for(j=0;j<columns;j++){
            average[i][j]+= table[i][j];
        }
            average[i][j] = average[i][j]/columns;
}
}

void CalculateMaxDeviation(int rows,int columns,double table[rows][columns],
                           double md[rows]){

     int i,j;
     double devnat[rows][columns];
     double natvag;


    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            devnat[i][j] = fabs(natvag-devnat[i][j]);
        }
    }
    for(i=0;i<rows;i++){
        md[i] = devnat[i][0];
        for(j=1;j<columns;j++){
                if(md[i]<devnat[i][j]) md[i] = devnat[i][j];
        }
    }
}

void Print_results(int rows, double avg,double average[rows],double md[rows]){
    int i;

    printf("%3.1f\n",avg);
    for(i=0;i<CTS;i++)
        printf("City %d %.1f %,1f\n",i,average[i],md[i]);
}
