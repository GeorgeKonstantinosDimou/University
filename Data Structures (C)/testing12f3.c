#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 100

/* FINISHED PRODUCT!!! */
///dai18069
///dai18069, hereby disclaims all copyright interest in the program "testing12f3" writtern by George Konstantinos Dimou
///Copyright 2021
/*��������: �� ��� ������� ���� ������� ���������� � ����� ��� �������� ������� ������ ���� ��� ��� A ��� ���������
������ ������� �������� ���� �, ����������� �� ������������� ��� ������� ��� (�������, ��������, ������
���).  ���������  ���  �������  ����  ����  ������,  ���  �������  �������  ��������  ���  ���  ����  ���������  �
������������, � ����������� ��� ������� ������ ����� ��������� � ������������. ������ ��������� ��
����� ������������  �� ������� ������������ ��� ��������, ��������������� ��� ��� ����. ���� ������� ���
���������� ���� ������� ������� �� ��� ���� ��������. ��� ���� ������ ��� ���������� �� ���������� ��
����� ������, �� �������� ���������, ��� ���  �������, ��� ��� ����� ��� ������������. � �������� �������
������� ��� ������������� ���� ���� �������� ����� 3. �� ��������� �� �������� ��� ���� ������ ��� ���
������ ��� ��� ����� ��������� �� �� ����� ��������, ���������������. � ��� ������ ��� � ������
��������� ������� �� ����� ����������� ������ �������.  ���������� 3 �����������:  1. ��������� ��� �� �������� ��� ��� ������ ��� ��� ����� ��������� ��� ���� ������ �� �� �����
��������, ��������������� ��� �� ������� ��� ������ ���� ���� ��������. ��� ��� ��� ������� ���
��� �����  �� ������������ � ��������޻ ���� -1 (� �������� ��� ������� ���� ���� �������� ��������
���������� - ������ 7 ��� 7
��� ��������� �� ������� ������ ��� ���������� ���� �������). � ��������� �� ����� void �� ���������
��� ���� ��������. 2. ��������� � ����� ������������ ��� ����������� ��� �������. ������ ����-���� ��� ������ ��� ���
���� �������� ��� ��� ���� ������ ��� ������������� �� ���������� ��� ��� ������� ��� ����� ���
������������ ��� �� ��������� ��� ������ ���� ���� ��������������� (��� ����). � ��� ������� ���
������������ ��� ������� ����� � ������ ������ ��� ������ ������ (��� ��� ����������� ���������). �
��������� ���� ��� ��������� ��� ���� �������� ��� ���������� ��� ���� ��� ���������������. ��
��������� ��� ���������� �����  QueueType TimesInQueue(QueueType *Queue) 3. ��������� �� 2 �����������: ��� �������� ��� �����, ��� ��� ����. �� � ���� ��� ����� ����� ��
��������� ��� ���� ������ ��� ������������� �����������, ��� �� ����� ����� �� ��������� �������
������ (��� ��� ����������� ���������).  ��� �������� ������� ��� ���������� ����������� ���������. */

typedef struct {
    int timeofArrival,waitingTime,timeofStart,timeofFinish;
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(char *QueueName,QueueType Queue);
QueueType InsertinQueue(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);

int main(){

    int i;
    char *QueueName;
    QueueType Queue1,Queue2;    ///Queue1 = Queue of clients waiting , Queue2 = Queue of already served customers

    CreateQ(&Queue1);

    for(i=0;i<3;i++){
        printf("Give: arrival time,stay time for client %d: ",i+1);
        InsertinQueue(&Queue1);
    }
    QueueName="Waiting Queue";
    TraverseQ(QueueName,Queue1);

    Queue2=TimesInQueue(&Queue1);
    TraverseQ(QueueName,Queue1);

    QueueName="Served Queue";
    TraverseQ(QueueName,Queue2);
    return 0;
}

QueueType InsertinQueue(QueueType *Queue){

    QueueElementType times;

    scanf("%d,%d",&times.timeofArrival,&times.waitingTime);
    times.timeofStart=-1;
    times.timeofFinish=-1;
    AddQ(Queue,times);
}

QueueType TimesInQueue(QueueType *Queue){

    int earliestStart,currentStart,currentEnd;
    QueueType servedQueue;
    QueueElementType CurrentCust;

    earliestStart=0;
    currentStart=0;
    currentEnd=0;

    CreateQ(&servedQueue);

    while(!(EmptyQ(*Queue))){
        RemoveQ(Queue,&CurrentCust);
        if(CurrentCust.timeofArrival>earliestStart){
            currentStart=CurrentCust.timeofArrival;
        }
        else{
            currentStart=earliestStart;
        }
        currentEnd=currentStart+CurrentCust.waitingTime;
        earliestStart=currentEnd;

        CurrentCust.timeofStart=currentStart;
        CurrentCust.timeofFinish=currentEnd;

        AddQ(&servedQueue,CurrentCust);
        }
        return servedQueue;
    }

void CreateQ(QueueType *Queue){
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue){
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue){
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item){
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}

void TraverseQ(char *QueueName,QueueType Queue) {
	int current;
	int i=1;

	if(!EmptyQ(Queue)){
    printf("%s\n",QueueName);
	current = Queue.Front;
	printf("Client \t\tStart\tEnd\tArrival\tStay\n");

	while (current != Queue.Rear) {
        printf("Client %d \t%d\t%d\t%d\t%d\n",i ,Queue.Element[i-1].timeofStart,Queue.Element[i-1].timeofFinish,Queue.Element[i-1].timeofArrival,Queue.Element[i-1].waitingTime);
		current = (current + 1) % QueueLimit;
		i++;
	}
	}
	else printf("%s is Empty",QueueName);
	printf("\n");
}
