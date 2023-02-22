#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

typedef struct{
    char name[30];
    int apousies;
}studentT;

#define MAXS 100

void readInput(FILE *infile, studentT students[], int *pOver100, int *pStudents);
void WriteOut(FILE *outfile, int size, studentT students[], int total);

int main()
{
    FILE *infile, *outfile;
    char infilename[30];
    char outfilename[30];
    int pOver100,numstudents;

    studentT students[MAXS];

    while(TRUE){
    printf("Dwse onoma arxeiou eisodou:");
    gets(infilename);
    infile = fopen(infilename,"r");
    if(infile ==NULL) break;
    printf("Cannot input file %s. Please try again. \n",infilename);
    }

    printf("Dwse onoma arxeiou eiksodou:");
    gets(outfilename);
    infile = fopen(outfilename,"w");

    //computation
    readInput(infile,students,&pOver100,&numstudents);
    WriteOut(outfile,pOver100,students,numstudents);

    fclose(infile);
    fclose(outfile);

    return 0;
}


void readInput(FILE *infile, studentT students[], int *pOver100, int *pStudents)
{
    char name[30];
    char comments[68];
    int apousies;
    char termch;
    int nscan;
    *pStudents =0;
    *pOver100=0;

    while(TRUE){
      fscanf(infile,"%30[^,], %d, %68[^\n]%c", name,&apousies,comments, &termch); //30 χαρακτηρες το πολυ μεχρι να συναντήσει κομμα (^)=εκτος
      if(nscan==EOF) break;
      if(termch !='\n'|| nscan!=4)
        {printf("error");
         exit(1);}

     (*pStudents)++;

     if(apousies > 100)
     {
         students[*pOver100].apousies=apousies;
         strcpy(students[*pOver100].name, name);
         (*pOver100)++;
     }
    }

}

void WriteOut(FILE *outfile, int size, studentT students[], int total)
{
   int i;
   fprintf(outfile, "%-30s%-9s\n", "ONOMATEPVNYMO", "APOUSIES");
   for(i=1;i<=39; i++)
    fputc('-', outfile);
   fputc('\n',outfile);

   for(i=0; i<size;i++)
    fprintf(outfile,"%-30s%9d\n",students[i].name, students[i].apousies);

  for(i=1;i<=39; i++)
    fputc('-', outfile);
  fputc('\n',outfile);
  fprintf(outfile,"%-30s%9d\n","SYNOLO MATHITWN",total);
  fprintf(outfile,"%-30s%9d\n","SYNOLO APONTWN",size);
}

