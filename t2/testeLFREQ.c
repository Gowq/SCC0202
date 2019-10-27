#include <stdio.h>
#include "lfreq.h"
typedef LFREQ LNO;

int main() {
  int i, v[10], tam = 10;
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  LNO V;
  LFREQcria(&V);
  // Insere os ítens do vetor na TAD
  for (i = 0; i < tam; i++){
    LFREQinsere(&V, v[i]);
  }
  // imprime
  LFREQimprime(&V);
  // Busca
  //int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Resultado da busca (1 para sucesso): %d\n", LFREQbusca(&V, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    r = LFREQremover(&V, v[i]);
    printf("Removeu? (1 para erro, 0 para sucesso): %d\n", r);
  }
  // Imprime depois de remover tudo
  LFREQimprime(&V);
  // Apaga a lista
  LFREQdestroi(&V);
  printf("Lista Vazia? (1 para sim): %d\n", LFREQesta_vazia(V));
  return 0;
}
