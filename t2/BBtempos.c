#include <time.h>
#include <math.h>
#include "bb.h" // Busca Binária
#include "BBtempos.h"
#include "pot10.h"

/* InsereTudo: Função que insere todos os elementos do vetor de inteiros na matriz
   Parâmetros:
   elem a[][10]: vetor de tipo Vetor contendo 10 vetores com N elementos do tipo elem cada
   int N: número de elementos a serem inseridos nos vetores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem inseridos na matriz */
double BBInsereTudo(Vetor v[],  int N, elem vet[]) {
  int Im, Ielem; // índices da matriz e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Im = 0; Im < 10; Im++)
    for(Ielem = 0; Ielem < N; Ielem++)	
      BBinsercao_ordenada(&v[Im], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* BBBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   ABB a[][10]: Matriz BB contendo 10 vetores com N elementos cada
   int N: número de elementos a serem inseridos nos vetores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na matriz */
double BBBuscaEmTudo(Vetor v[], int N, elem vet[]) {
  int Im, Ielem; // índices da matriz e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Im = 0; Im < 10; Im++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      bb((v[Im]), vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      bb((v[Im]), -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* BBRemoveEmTudo: Função que remove metade dos elementos de cada vetor da matriz
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   ABB a[][10]: Matriz contendo 10 vetores com N elementos cada
   int N: número de elementos a serem inseridos nos vetores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da matriz */
double BBRemoveEmTudo(Vetor v[], int N, elem vet[]) {
  int Im, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Im = 0; Im < 10; Im++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      BBremocao(&v[Im], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      BBremocao(&v[Im], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* ABBtempos: Função que realiza todos os cálculos de tempo para operações com árvores de 100, 1000, dez mil
              e cem mil elementos (0 a 3, respectivamente)
   Parâmetros
   int *vet[4]: Vetor de vetores de números inteiros de 100, 1000, 10000, 100000 elementos */
Ntempos BBtempos(elem *vet[4]) {
  // vetores para Busca Binária
  Vetor BBcem[10], BBmil[10], BB10mil[10], BB100mil[10];
  Vetor *BB[4] = {NULL, NULL, NULL, NULL};
  // 0 -> 100, 1 -> 1000, 2 -> 10000, 3 - > 100000
  BB[0] = BBcem, BB[1] = BBmil, BB[2] = BB10mil, BB[3] = BB100mil;
  // Aloca memória para os vetores crescentes
  int i, x;
  // Operações de criação das listas
  for (i = 0; i < 4; i++) { //Iteração do tamanho do vetor
    for (x = 0; x < 10; x++) { 
      int tam =  pot10(i + 2);
      BBcria( &BB[i][x], tam);
    }
  }
  Ntempos retorno;
  
  // Escrevendo tempos para os vetores de 100, 1000, 10000 e 100000 elementos 
  for (x = 0; x < 4; x++) {
    int tam = pot10(x + 2);
    retorno.vet_esc[x].insercao = BBInsereTudo(BB[x], tam, vet[x]);
    retorno.vet_esc[x].busca    = BBBuscaEmTudo(BB[x], tam, vet[x]);
    retorno.vet_esc[x].remocao  = BBRemoveEmTudo(BB[x], tam, vet[x]);
  }
 
  return retorno;
}
