#include <stdio.h>
#include <strlib.h>

void decompose(long Numb,long *digi,double *Aver,long *maxD);

int main(){

 long number;
 long x,z;
 double y;

 printf("Please instert non-negative number:");
 scanf("%ld",&number);
 decompose(number,&x,&y,&z);
 printf("Digits: %ld\n",x);
 printf("Average: %.3f\n",y);
 printf("Max: %ld\n",z);
}

void decompose(long Numb,long *digi,double *aver,long *maxD){

 int moduloAssis = 10; // ���� �������� ��� �� ����� � moduloAssis
 int dividor = 1;      // ������� ���� ����� ��� ���������������
 *digi = 1;            // ��� � dividor ��� ��� ��������� ��� ���������
 *maxD = 1;
 *aver = 0;

 while(Numb%moduloAssis != Numb){(*digi)++; //� ������� ����� ���������� �� ����� false ���� � ������� ��� �� ����� � ������� ��� �� ������ ����� ���� ��� mod �� ���������� �� ����� ��� ���� ��� ������
    *aver += (Numb%moduloAssis)/dividor; //������ ��� (��������) ����� ����
     if((Numb%moduloAssis)/dividor > *maxD ) *maxD = (Numb%moduloAssis)/dividor; //������� ��� max
     moduloAssis *= 10; //������ ��� ���������� ����������
     dividor *= 10;
 }
 if(*aver == 0) *aver = Numb; //������� ��� ��� ��������� ���������� ������� , ���� ��� �� ���� ���� ��������� ����� ����
 else{
    *aver += (Numb/dividor); //�������� ������� ������
    *aver /= (double)*digi;
  }
}
