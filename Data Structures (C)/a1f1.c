#include <stdio.h>
/*Το παρακάτω πρόγραμμα υπολογίζει σε 2 δωθεντα
/*όρια απο τον χρήστη (άνω και κάτω) με ελάχιστη και
/*μέγιστη τιμή το 2 και 200 αντίστοιχα και ελέγχει αν
/*είναι οι αριθμοί μεσα στα όρια πρώτοι και τους εκτυπώνει */


#define megisto_plithos 200

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isPrime(stoixeio_synolou stoixeio);
void createPrimeSet(stoixeio_synolou s1,stoixeio_synolou s2,typos_synolou synolo);
void displayset(typos_synolou synolo,stoixeio_synolou s1,stoixeio_synolou s2);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);


int main(){

    int first,last;
    typos_synolou set;

    printf("Dwse to katw orio tou synolou: ");
    scanf("%d",&first);
    printf("Dwse to anw orio tou synolou: ");
    scanf("%d",&last);
    while(!(first < last && first >= 2 && first < 200 && last > 2 && last <= 200)){
        printf("Den einai epitrepta oria , parakalw dwste alla!\n");
        scanf("%d",&first);
        scanf("%d",&last);
    }
    createPrimeSet(first,last,set);
    displayset(set,first,last);
}


boolean isPrime(stoixeio_synolou stoixeio){

    int i;

    for(i=2;i*i<=stoixeio;i++){
        if(stoixeio % i == 0)return FALSE;
    }
    return TRUE;
}

void createPrimeSet(stoixeio_synolou s1,stoixeio_synolou s2,typos_synolou synolo){

    int i;

    Dimiourgia(synolo);                 //Δημιουργία κενού συνόλου
    for(i=2;i<megisto_plithos;i++){
        if(isPrime(i)){                //Εισαγωγή στοιχείου όταν είναι Prime
            Eisagogi(i,synolo);
        }
    }
}

void displayset(typos_synolou synolo,stoixeio_synolou s1,stoixeio_synolou s2){

    int i;
    for(i=s1;i<s2;i++){
        if(Melos(i,synolo)){
            printf("%d ",i);
        }
    }
}

void Dimiourgia(typos_synolou synolo){

    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo){

    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo){

    return synolo[stoixeio];
}

