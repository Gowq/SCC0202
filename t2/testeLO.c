#include <stdio.h>
#include "lo.h"
typedef ListaOrd LO;
int main(){
  int i, tam = 100000;
  int v[tam];
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  LO V;
  LOcria(&V);
  // Insere os ítens do vetor na TAD
  for (i = 0; i < tam; i++){
    LOinsere(&V, v[i]);
  }
  // imprime
  LOimprime(V);
  // Busca
  int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Resultado da busca (1 para sucesso): %d\n", LObusca(V, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    r = LOremover(&V, v[i]);
    printf("Removeu? (1 para erro, 0 para sucesso): %d\n", r);
  }
  // Imprime depois de remover tudo
  LOimprime(V);
  // Apaga a lista
  LOdestroi(&V);
  printf("Lista Vazia? (1 para sim): %d\n", LOesta_vazia(V));
  return 0;
}
