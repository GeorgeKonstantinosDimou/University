#include <stdio.h>

typedef enum {
    FALSE, TRUE
} boolean;

typedef int stoixeio_synolou;

//boolean isPrime(stoixeio_synolou stoixeio);

int main(){

    boolean x=FALSE;

    printf(x ? "true" : "false");

}


/*boolean isPrime(stoixeio_synolou stoixeio){

    int i;

    for(i=2;i*i<=stoixeio;i++){
        if(stoixeio % i == 0)return FALSE;
    }
    return TRUE;
}
*/
