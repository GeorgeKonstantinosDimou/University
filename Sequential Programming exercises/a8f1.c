#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
  long eswteriko,ejwteriko;
  double poso;

  printf("Dwse ton arithmo epistolwn eswterikou: ");
  eswteriko = GetLong();
  printf("Dwse ton arithmo epistolwn ejwterikou: ");
  ejwteriko = GetLong();
  poso = 0.3 * eswteriko + 0.8 * ejwteriko;
  printf("To synoliko kostos apostolis einai: %g\n",poso);
  system("pause");
}
