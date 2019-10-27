#include <stdio.h>
#include "avl.h"

int main(){
  int i, v[10], tam = 10;
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  No *raiz = NULL; // Nó Raíz
  //AVLcria(&V);
  // Insere os ítens do vetor na TAD

  for (i = 0; i < tam; i++){
    insercao_aux(&raiz, v[i]);
  }
  printf("todos inseridos!");
  getchar();
  // imprime
  em_ordem(raiz);
  // Busca
  int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Resultado da busca (1 para sucesso): %d\n", AVLbusca(raiz, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    AVLremocao(raiz, v[i]);
    printf("Removeu? (1 para erro, 0 para sucesso): %d\n", r);
  }
  // Imprime depois de remover tudo
  em_ordem(raiz);
  // Apaga a lista
  AVLdestroi(raiz);
  //printf("Lista Vazia? (1 para sim): %d\n", AVLesta_vazia(V));
  return 0;
}
