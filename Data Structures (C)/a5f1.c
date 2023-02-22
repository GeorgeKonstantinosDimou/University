#include <stdio.h>

//������ 5 �������� 1 ������ ����� ���������
//������ ���������� Fibonacci ����� ��� �����
//���� (min 2, max 1000) ��� ������� �������
//������� �� �����

#define megisto_plithos 1000

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

//��������� �����������
void createFibonacciSet(stoixeio_synolou n,typos_synolou setF);
boolean isFibonacci(stoixeio_synolou stoixeio,typos_synolou synolo);

//������� ����������� �������
void displayset(stoixeio_synolou max,typos_synolou set);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);


int main(){

    stoixeio_synolou max,fcheck;
    typos_synolou setFibonacci;

    printf("Dwse to megistoarithmo. ");
    scanf("%d",&max);
    while(!(max >= 2 && max <= 1000)){                                                       //������� ����� (����������� �� !) ��� � ������� ����� FALSE ���� ��� ! �� ������� TRUE ��� ����
          printf("Den einai egkrires oi times tou diasthmatos, parakalw dwste alles.");      //�� ��������� �� ��������� �� ������ �����.
          scanf("%d",&max);
    }
    createFibonacciSet(max,setFibonacci);
    displayset(max,setFibonacci);

    do{
    printf("Enter a number to check:");
    scanf("%d",&fcheck);
    if(fcheck >= 2 && fcheck <= 1000 && isFibonacci(fcheck,setFibonacci)){ //�� � ������� ����� ���� ��� ������� ��� ���� ��� ������
        printf("Fibonacci!\n");                                              //���� ���������� Fibonacci
        }
    else if(fcheck > 0 && !isFibonacci(fcheck,setFibonacci)){
        printf("Not Fibonacci..\n");
        }
    else{
        break;
        }
    }while(fcheck>0);

}


boolean isFibonacci(stoixeio_synolou stoixeio,typos_synolou synolo){

//����� ���������� ��� ������� ��� �������
//���������� Melos

    return Melos(stoixeio,synolo);
}

void createFibonacciSet(int n,typos_synolou setF){

//��������� ��� ��� ���������� ��� ����������
//Fibonacci ����� ���� ������ threshold ��� ���
//����� � �������. �� ������� �� 2 ����� ���
//�������� ����� �� 0, 1

    stoixeio_synolou x1,x2,temp;

    Dimiourgia(setF);
    x1 = 0;
    x2 = 1;
    Eisagogi(x1,setF);
    temp = x1 + x2;

    while(temp<=n){
        Eisagogi(temp,setF);
        x1 = x2;
        x2 = temp;
        temp = x1+x2;
    }
}

void displayset(stoixeio_synolou max,typos_synolou set){

	stoixeio_synolou i;

	for (i=0;i <= max;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo){

    return synolo[stoixeio];
}

void Dimiourgia(typos_synolou synolo){

    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo){

    synolo[stoixeio] = TRUE;
}
