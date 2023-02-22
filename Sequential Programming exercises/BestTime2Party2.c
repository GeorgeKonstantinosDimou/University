void fillBand(char array[20]);
void fillTimeSchedule(int 20,int 2, double matrix[HMbands][timeEvent]);



int main(){

fillBand(BandNames);
fillTimeSchedule(Schedule);


}



void fillBand(char BandNames[20]){

int i;

printf("Give the names of the Bands:\n");
for(i=0;i<=19;i++){
    fgets(BandNames,20,stdin);
    }
}


void fillTimeSchedule(int 20,int 2, double matrix[HMbands][timeEvent]){

int i;

for(i=0;i<=19;i++){
    printf("Give the time of arrival and departure of %c \n", BandNames[i]);
    printf("Arrival:\n");
    Schedule[i][1] = GetReal();
    printf("Departure:\n");
    Schedule[i][2] = GetReal();
}
}
