#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 100

/* FINISHED PRODUCT!!! */
///dai18069
///dai18069, hereby disclaims all copyright interest in the program "testing12f3" writtern by George Konstantinos Dimou
///Copyright 2021
/*Εκφώνηση: Σε μία τράπεζα κάθε πελάτης εισέρχεται σ αυτήν μία ορισμένη χρονική στιγμή έστω την ώρα A και παραμένει
κάποιο χρονικό διάστημα έστω Τ, προκειμένου να διεκπεραιώσει την εργασία του (ανάληψη, μεταφορά, δάνειο
κλπ).  Δεδομένου  ότι  υπάρχει  μόνο  ένας  ταμίας,  εάν  κάποιος  πελάτης  εισέλθει  ενώ  δεν  έχει  τελειώσει  ο
προηγούμενος, η εξυπηρέτησή του αρχίζει αμέσως μόλις τελειώσει ο προηγούμενος. Γράψτε πρόγραμμα το
οποίο μοντελοποιεί  το σύστημα εξυπηρέτησης της τράπεζας, χρησιμοποιώντας τον ΑΤΔ ουρά. Κάθε πελάτης που
εισέρχεται στην τράπεζα μπαίνει σε μια ουρά αναμονής. Για κάθε πελάτη μας ενδιαφέρει να γνωρίζουμε το
χρόνο άφιξης, τη διάρκεια παραμονής, την ώρα  έναρξης, την ώρα λήξης της εξυπηρέτησης. Ο μέγιστος αριθμός
πελατών που καταχωρούνται στην ουρά αναμονής είναι 3. Το πρόγραμμα θα διαβάζει για κάθε πελάτη την ώρα
άφιξης και τον χρόνο παραμονής με τη μορφή ώρα’φιξης, χρόνοςΠαραμονής. Η ώρα άφιξης και ο χρόνος
παραμονής μπορούν να είναι οποιοδήποτε θετικό μέγεθος.  Υλοποιήστε 3 συναρτήσεις:  1. Συνάρτηση που θα διαβάζει την ώρα άφιξης και τον χρόνο παραμονής του κάθε πελάτη με τη μορφή
ώρα’φιξης, χρόνοςΠαραμονής και θα εισάγει τον πελάτη στην ουρά αναμονής. Για την ώρα έναρξης και
ώρα λήξης  θα καταχωρείται η «εικονική» τιμή -1 (η εισαγωγή των πελατών στην ουρά αναμονής θεωρήστε
ΟΟυυρρέέςς - σελίδα 7 από 7
ότι συμβαίνει τη χρονική στιγμή που εισέρχεται στην τράπεζα). Η συνάρτηση θα είναι void με παράμετρο
την ουρά αναμονής. 2. Συνάρτηση η οποία προσομοιώνει την εξυπηρέτηση των πελατών. Εξάγει έναν-έναν τον πελάτη από την
ουρά αναμονής και για κάθε πελάτη που εξυπηρετείται θα υπολογίζει την ώρα έναρξης και λήξης της
εξυπηρέτησης και θα καταχωρεί τον πελάτη στην ουρά εξυπηρετηθέντων (νέα ουρά). Η ώρα έναρξης της
εξυπηρέτησης των πελατών είναι ο χρόνος άφιξης του πρώτου πελάτη (δες στο στιγμιότυπο εκτέλεσης). Η
συνάρτηση έχει μια παράμετρο την ουρά αναμονής και επιστρέφει την ουρά των εξυπηρετηθέντων. Το
πρωτότυπο της συνάρτησης είναι  QueueType TimesInQueue(QueueType *Queue) 3. Συνάρτηση με 2 παραμέτρους: την ονομασία της ουράς, και την ουρά. Αν η ουρά δεν είναι άδεια θα
εμφανίζει για κάθε πελάτη τις καταχωρημένες πληροφορίες, ενώ αν είναι άδεια θα εμφανίζει σχετικό
μήνυμα (δες στο στιγμιότυπο εκτέλεσης).  Στη συνέχεια δίνεται ένα ενδεικτικό στιγμιότυπο εκτέλεσης. */

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
