#include <stdio.h>
#include "abb.h"
typedef ABB ABBNO;

int main(){
  int i, v[100000], tam = 100000;
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  ABBNO V;
  ABBcria(&V);
  // Insere os ítens do vetor na TAD
  for (i = 0; i < tam; i++){
    ABBinsercao(&V, v[i]);
  }
  // imprime
  ABBimprime(V);
  // Busca
  //int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Resultado da busca (1 para sucesso): %d\n", ABBbusca(V, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    r = ABBremocao(&V, v[i]);
    printf("Removeu? (1 para erro, 0 para sucesso): %d\n", r);
  }
  // Imprime depois de remover tudo
  ABBimprime(V);
  // Apaga a lista
  ABBdestroi(&V);
  printf("Lista Vazia? (1 para sim): %d\n", V.raiz == NULL ? 0 : 1);
  return 0;
}
