#include <stdio.h>
#include <stdlib.h>

void populate_date(int rows,int columns,int matrixA[rows][columns]);
void print_array(int rows,int columns,int matrixA[rows][columns]);
void change_array(int rows,int columns,int matrixA[rows][columns]);

int main(){

int R, C;
int A[10][10];

printf("Dwse ton arithmo twn grammwn:");
scanf("%d",&R);

printf("Dwse ton arithmo twn sthlwn:");
scanf("%d",&C);

populate_date(R,C,A);

printf("ARXIKOS PINAKAS\n");
print_array(R,C,A);

printf("ALLAGMENOS PINAKAS\n");
change_array(R,C,A);

}


void populate_date(int rows,int columns,int matrixA[rows][columns]){

int i,j;

 for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        matrixA[i][j] = rand() % 100;
    }
 }
}

void print_array(int rows,int columns,int matrixA[rows][columns]){

int i,j;

 for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
        printf("%d ",matrixA[i][j]);
    }
    printf("\n");
 }
}

void change_array(int rows,int columns,int matrixA[rows][columns]){

int i,j,inde;
int max;

//EYRESH MAX
 for(i=0;i<rows;i++){
    max = 0 ;
    for(j=0;j<columns;j++){
        if(matrixA[i][j] > max){ max = matrixA[i][j];
            inde = j ;
        }
     }
    for(j=0;j<inde;j++){        //ANTIKATASTASH ARITHMWN APO MAX
            matrixA[i][j] = max;
        }

    for(j=0;j<columns;j++){         //EKTYPWSH APOTELESMATWN
        printf("%d ",matrixA[i][j]);
    }
    printf("\n");
 }
}
