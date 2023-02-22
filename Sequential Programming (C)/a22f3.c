#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
  int x;

  printf("give me the number\n");
  x=GetInteger();
  while(x!=-1)
  {
      printf("%d ",x);
      x=x-1;
  }

return 0;

}
