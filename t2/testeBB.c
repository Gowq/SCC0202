#include <stdio.h>
#include "bb.h"

int main(){
  int i, tam = 100000;
  int v[tam];
  // Inicializa vetor para retirar testar as operações da TAD
  for (i = 0; i < tam; i++)
    v[i] = i;
  Vetor V;
  BBcria(&V, tam);
  // Insere os ítens do vetor na TAD
  for (i = 0; i < tam; i++){
    BBinsercao_ordenada(&V, v[i]);
    // Debugando o que está acontecendo
    printf("%d %d %d %d %d %d %d %d %d %d\n", V.v[0], V.v[1], V.v[2], V.v[3], V.v[4], V.v[5], V.v[6], V.v[7], V.v[8], V.v[9]);
  }
  // imprime
  BBimprime(V);
  // Busca
  int b;
    // Busca
  for (i = 0; i < tam; i++)
    printf("Posição do elemento encontrado: %d\n", bb(V, v[i]));

  // Remove
  int r;
  for (i = 0; i < tam; i++){
    r = BBremocao(&V, v[i]);
    // Debugando o que está acontecendo
    printf("%d %d %d %d %d %d %d %d %d %d\n", V.v[0], V.v[1], V.v[2], V.v[3], V.v[4], V.v[5], V.v[6], V.v[7], V.v[8], V.v[9]);
    printf("Elemento na posição %d depois da remoção: %d\nTamanho atual: %d Último: %d\n", i, V.v[i], V.ultimo, V.v[V.ultimo -1]);
  }
  // Imprime depois de remover tudo
  BBimprime(V);
  BBdestroi(&V);
  return 0;
}
