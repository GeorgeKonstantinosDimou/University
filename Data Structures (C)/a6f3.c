#include <stdio.h>

#define QueueLimit 10

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){

    int i;
    QueueType Queue1;
    QueueElementType AnItem;

    CreateQ(&Queue1);

    printf("---a---\n");

    for(i=0;i<10;i++){
        AnItem = i;
        AddQ(&Queue1,AnItem);
    }
    if(FullQ)Queue1.Rear = Queue1.Front;    ///Η περίπτωση που είναι γεμάτη η ουρά θέτω το Rear = Front
    printf("Queue:");
    TraverseQ(Queue1);
	printf("Front=%d Rear=%d Count=%d",Queue1.Front ,Queue1.Rear ,Queue1.Count);        ///Εκτύπωση των δεδομένων Front,Rear,Count

	printf("\n");                   ///Ερώτημα b
	printf("---b----\n");
	AddQ(&Queue1,5);
	printf("\n");
	printf("Queue:");
	TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d",Queue1.Front ,Queue1.Rear ,Queue1.Count);

    printf("\n");               ///Ερώτημα c
    printf("---c----\n");
    RemoveQ(&Queue1,&AnItem);
    printf("Queue:");
    TraverseQ(Queue1);
    printf("Removed Item=%d Front=%d Rear=%d Count=%d",AnItem,Queue1.Front ,Queue1.Rear ,Queue1.Count);

    printf("\n");               ///Ερώτημα d
    printf("---d----\n");
    AddQ(&Queue1,18);
    printf("Queue:");
    TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d",Queue1.Front ,Queue1.Rear ,Queue1.Count);

    printf("\n");                   ///Ερώτημα e
	printf("---e----\n");
	AddQ(&Queue1,5);
	printf("\n");
	printf("Queue:");
	TraverseQ(Queue1);
    printf("Front=%d Rear=%d Count=%d",Queue1.Front ,Queue1.Rear ,Queue1.Count);

    printf("\n");                   ///Ερώτημα f
	printf("---f----\n");
    while(!EmptyQ(Queue1)){
        RemoveQ(&Queue1,&AnItem);
        printf("Queue:");
        TraverseQ(Queue1);
        printf("Removed Item=%d Front=%d Rear=%d Count=%d",AnItem,Queue1.Front ,Queue1.Rear ,Queue1.Count);
        printf("\n");
    }
}

void CreateQ(QueueType *Queue){

	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;   ///Αλλαγή στην συνάρτηση CreateQ για να συμπεριλαμβάνει και το πεδίο Count
}

boolean EmptyQ(QueueType Queue){

    return (Queue.Count == 0 );
}

boolean FullQ(QueueType Queue){

    //if(Queue.Count < (QueueLimit-1)) return FALSE;
    //else return TRUE;

    //if(Queue.Count == 0) return FALSE;
    //else if(Queue.Count == 10) return TRUE;
    //else return((Queue.Front) == ((Queue.Rear + 1) % QueueLimit));

    return (Queue.Count == 10);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item){

	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->Count = Queue->Count - 1;        ///Αλλαγή της συνάρτησης RemoveQ για να μειώνει επισης και το πεδίο Count
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item){

	if(!FullQ(*Queue) )
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Count = Queue->Count + 1;       ///Αλλαγή της συνάρτησης AddQ για να αυξάνει επισης και το πεδίο Count
	}
	else
		printf("Full Queue");
}

void TraverseQ(QueueType Queue) {

	int current,i;

	current = Queue.Front;

	for(i=0;i<Queue.Count;i++) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
