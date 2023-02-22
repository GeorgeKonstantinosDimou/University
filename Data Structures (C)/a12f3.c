#include <stdio.h>

#define QueueLimit 4

typedef struct {
    int timeofArrival, timeofStay,startingTime,finishTime;
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);     ///Δωσμένες συναρτήσεις
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void Times(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);

int main(){

    QueueType service,finishedServing;
    QueueElementType timestamps;

    CreateQ(&service);


}

void Times(QueueType *Queue){       ///Ερώτημα 1

    int i;
    QueueElementType timestamps;

    for(i=0;i<3;i++){
        printf("Give arrival time,stay time for client %d: ",i+1);
        scanf("%d",&timestamps.timeofArrival);      ///Διάβασμα στοιχείων
        printf(",");
        scanf("%d",&timestamps.timeofStay);
        timestamps.startingTime = -1;
        timestamps.finishTime = -1;
        AddQ(Queue,timestamps);
    }


}

QueueType TimesInQueue(QueueType *Queue){

    QueueType finished;
    QueueElementType finishedQueueTimes,customers;

    while(!EmptyQ(Queue)){
        RemoveQ(Queue,&customers);
        finishedQueueTimes.startingTime = customers.timeofArrival;
        finishedQueueTimes.finishTime = customers.Ar + customers.

    }


    return finished;
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
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit; ;
	}
	else
		printf("Full Queue");
}
