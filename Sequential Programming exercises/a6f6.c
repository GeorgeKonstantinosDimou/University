#include <stdio.h>
#include <stdlib.h>

#define N 5

void readData(int rows,int columns,int matrix[rows][columns]);
void FindMean(int rows,int columns,int matrix[rows][columns],float *average0,float *average1,int x);

int main(){

int index;
float avgM,avgF;
int info[N][4];

readData(N,4,info);
 for(index=1;index<4;index++){
    FindMean(N,4,info,&avgM,&avgF,index);
    if(index == 1){
        printf("Mesos oros barous andrwn: %.1f\n",avgM);
        printf("Mesos oros barous gynaikwn: %.1f\n",avgF);
        printf("\n");
    }
    else if(index == 2){
        printf("Mesos oros ypsous andrwn: %.1f\n",avgM);
        printf("Mesos oros ypsous gynaikwn: %.1f\n",avgF);
        printf("\n");
    }
    else{
        printf("Mesos oros hlikias andrwn: %.1f\n",avgM);
        printf("Mesos oros hlikias gynaikwn: %.1f\n",avgF);
    }
 }

}


void readData(int rows,int columns,int matrix[rows][columns]){

int i,j=0;

 for(i=0;i<rows;i++){
    printf("Dwse fylo: ");
    scanf("%d",&matrix[i][j]);
    j++;
    printf("Dwse baros: ");
    scanf("%d",&matrix[i][j]);
    j++;
    printf("Dwse ypsos: ");
    scanf("%d",&matrix[i][j]);
    j++;
    printf("Dwse ilikia: ");
    scanf("%d",&matrix[i][j]);
    printf("------\n");
    j = 0;
 }
}


void FindMean(int rows,int columns,int matrix[rows][columns],float *average0,float *average1,int x){

int numbofM,numbofF,i,sum0=0,sum1=0;

 numbofM = 0;   //аяихлос амдяым
 numbofF = 0;   //аяихлос цумаийым
*average0 = 0;
*average1 = 0;

 for(i=0;i<rows;i++){
    if(matrix[i][0] == 0){
        numbofM++;
        sum0 += matrix[i][x];
        }
    else{
        numbofF++;
        sum1 += matrix[i][x];
    }
 }
 *average0 = (float)sum0/numbofM;
 *average1 = (float)sum1/numbofF;
}
