#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 int v,i,s;
 double mo;
 i=0;
 s=0;
 printf("dwse ton vathmo: ");
 v=GetInteger();
 while (v!=-1){
  i=i+1;
  s=s+v;
  printf("dwse ton vathmo: ");
  v=GetInteger();

 }

  printf("%d\n",i);
  printf("%d\n",s);
  mo=(s*100.0)/(i*100.0);
  printf("%g\n",mo);
return 0;
}
