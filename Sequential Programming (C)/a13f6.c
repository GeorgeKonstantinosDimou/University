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

 int moduloAssis = 10; // Οπως συστήνει και το όνομα ο moduloAssis
 int dividor = 1;      // βοηθάει στην πράξη του πολλαπλασιασμού
 *digi = 1;            // ενώ ο dividor για την υλοποίηση της διαίρεσης
 *maxD = 1;
 *aver = 0;

 while(Numb%moduloAssis != Numb){(*digi)++; //Ο έλεγχος αυτός ουσιαστικα θα γίνει false όταν ο αριθμός που θα δώσει ο χρήστης δεν θα χωράει ΚΑΜΙΑ φορά στο mod με αποτελεσμα να δίνει τον ιδιο τον αριθμο
    *aver += (Numb%moduloAssis)/dividor; //αυξηση του (αργότερα) μέσου ορου
     if((Numb%moduloAssis)/dividor > *maxD ) *maxD = (Numb%moduloAssis)/dividor; //Ελεγχός για max
     moduloAssis *= 10; //αυξηση των βοηθητικών μεταβλητων
     dividor *= 10;
 }
 if(*aver == 0) *aver = Numb; //Ελεγχος για την περιπτωση μονοψηφιου αριθμου , αφου δεν θα μπει στην επαναληψη καμια φορα
 else{
    *aver += (Numb/dividor); //προσθεση τελικου ψηφιου
    *aver /= (double)*digi;
  }
}
