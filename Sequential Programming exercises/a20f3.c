#include <stdio.h>
#include "simpio.h"

int main(){

int years_old,Max = 0,min = 200;


printf("Dwse ilikia:");
years_old = GetInteger();

while(years_old != -1){
    if(years_old > Max) Max = years_old;
    if(years_old < min) min = years_old;

printf("Dwse ilikia:");
years_old = GetInteger();
}

/*�� if ��� ���� ����� ��� ��� ��������� ���
���� ���� ��� ���� � ����� ���� ���� �� ���
��������� ��� ������ ���� ��� min( 200) ���
����� ���� ����. */

printf("H megalyterh ilikia einai:%d\n",Max);
if(years_old == 200)printf("H mikroterh ilikia einai:0\n");
else printf("H mikroterh ilikia einai:%d\n",min);
}


