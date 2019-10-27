#include <stdio.h>
#include <stdlib.h>
int pot10(int x){
  int retorno = 1, i;
  for (i = 0; i < x; i++)
    retorno *= 10;
  return retorno;
}
/* int main(int argc, char** argv){ */
/*   int i = atoi(argv[1]); */
/*   printf("\n10^%d = %d\n", i, pot10(i) ); */
/*   return 0; */
/* } */
