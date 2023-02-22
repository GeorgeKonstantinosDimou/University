
#include <stdio.h>
#include "simpio.h"

#define HMbands 20
#define timeEvent 2
#define timeZones 6

void results(int a);

int main(){

string BandNames[HMbands];
int Schedule[HMbands][timeEvent];
int SumArrivals[timeZones];
int SumDepartures[timeZones];

int i,sum,max,bestTime;

// ������� ��� ������ �� �� ������� ��� ������� ��� ��� ���� ���������� ��� ������
printf("Give the names of the Bands:\n");
for(i=0;i<=19;i++){
    fgets(BandNames,20,stdin);
    }

for(i=0;i<=19;i++){
    printf("Give the time of arrival and departure of %s \n", BandNames[i]);
    printf("Arrival:");
    Schedule[i][0] = GetInteger();
    printf("Departure:");
    Schedule[i][1] = GetInteger();
    }

//������������ ����� ��� ������� SumArrivals , SumDeparture

for(i=0;i<6;i++){
    SumArrivals[i] = 0;
    SumDepartures[i] = 0;
}

// ����������� ��� ��������� ������������� ��� ��� ��� ���������� �����

for(i=0;i<=19;i++){
    switch(Schedule[i][0])
    {
    case 18 :
        SumArrivals[0]++;
        break;
    case 19 :
        SumArrivals[1]++;
        break;
    case 20 :
        SumArrivals[2]++;
        break;
    case 21 :
        SumArrivals[3]++;
        break;
    case 22 :
        SumArrivals[4]++;
        break;
    case 23 :
        SumArrivals[5]++;
        break;
    }

    switch(Schedule[i][2])
    {
    case 19 :
        SumDepartures[0]++;
        break;
    case 20 :
        SumDepartures[1]++;
        break;
    case 21 :
        SumDepartures[2]++;
        break;
    case 22 :
        SumDepartures[3]++;
        break;
    case 23 :
        SumDepartures[4]++;
        break;
    case 24 :
        SumDepartures[5]++;
        break;
    }
}

/*������� 2 ���������� SUM ��� �� �� �������� ��� ������ ��� �������
��� ���������� ���� ������� ������ ��� BAZZAR , ��� ��� ��� �� ����
����� ������� �� ���������� �������� ��� �������� ��� */

sum = SumArrivals[0];
max = SumArrivals[0];

for(i=1;i<=5;i++){
    sum = sum + SumArrivals[i] - SumDepartures[i-1];
    if(sum >= max){
        max = sum ;
        bestTime = i;
    }
results(bestTime);
}
}

void results(int a){

switch(a){
    case 18 :
            printf("The best time to be at the Xmas bazzar will be from 18 to 19");
            break;
    case 19 :
            printf("The best time to be at the Xmas bazzar will be from 19 to 20");
            break;
    case 20 :
            printf("The best time to be at the Xmas bazzar will be from 20 to 21");
            break;
    case 21 :
            printf("The best time to be at the Xmas bazzar will be from 21 to 22");
            break;
    case 22 :
            printf("The best time to be at the Xmas bazzar will be from 22 to 23");
            break;
    case 23 :
            printf("The best time to be at the Xmas bazzar will be from 23 to 24");
            break;
}
}






