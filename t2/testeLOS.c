#include <stdio.h>
#include "los.h"
typedef ListaOrdSent LOS;
int main(){
  int i, v[10], tam = 10;
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  LOS V;
  LOScria(&V);
  // Insere os ítens do vetor na TAD
  for (i = 0; i < tam; i++){
    LOSinsere(&V, v[i]);
  }
  // imprime
  LOSimprime(V);
  // Busca
  int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Resultado da busca (1 para sucesso): %d\n", LOSbusca(V, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    r = LOSremover(&V, v[i]);
    printf("Removeu? (1 para erro, 0 para sucesso): %d\n", r);
  }
  // Imprime depois de remover tudo
  LOSimprime(V);
  // Apaga a lista
  LOSdestroi(&V);
  printf("Lista Vazia? (1 para sim): %d\n", LOSesta_vazia(V));
  return 0;
}
