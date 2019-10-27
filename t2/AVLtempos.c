#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "pot10.h"
/* typedef struct tempos{ */
/* 	double insercao, busca, remocao; */
/* } Tempos; */

/* typedef struct ntempos{ */
/* 	Tempos vet_esc[4]; // 0 -> cem, 1 -> mil, 2 -> dez mil, 3 -> cem mil */
/* } Ntempos; */

#include "avl.h" // Árvore AVL
#include "Tempos.h"
#include "AVLtempos.h"

  /* AVLInsereTudo: Função que insere todos os elementos do vetor de inteiros nos vetores de Árvores
     Parâmetros:
     AVL *a[]: Vetor de árvores AVL contendo 10 árvores com N elementos cada
     int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
     int vet[]: Vetor contendo os elementos a serem inseridos na árvore */
double AVLInsereTudo(AVL a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++)
    for(Ielem = 0; Ielem < N; Ielem++)
      AVLinsercao(&a[Iar], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* AVLBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   AVL a[]: Vetor de árvores AVL contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na árvore */
double AVLBuscaEmTudo(AVL a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      AVLbusca(a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      AVLbusca(a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* AVLRemoveEmTudo: Função que remove metade dos elementos de cada árvore do vetor de árvores
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   AVL a[]: Vetor de árvores AVL contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da árvore */
double AVLRemoveEmTudo(AVL a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      AVLremocao(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      AVLremocao(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* AVLtempos: Função que realiza todos os cálculos de tempo para operações com árvores de 100, 1000, dez mil
              e cem mil elementos (0 a 3, respectivamente)
   Parâmetros
   int *vet[4]: Vetor de vetores de números inteiros de 100, 1000, 10000, 100000 elementos */
Ntempos AVLtempos(int *vet[4]) {
  // vetores para Árvore Binária de Busca
  AVL AVLcem[10], AVLmil[10], AVL10mil[10], AVL100mil[10];
  AVL *p[4] = {NULL, NULL, NULL, NULL}; // vetor auxiliar para o loop
  p[0] = AVLcem; p[1] = AVLmil; p[2] = AVL10mil; p[3] = AVL100mil;
  int i;
  // Operações de Criação das listas
  for (i = 0; i < 10; i++){
    AVLcria( &AVLcem[i] );
    AVLcria( &AVLmil[i] );
    AVLcria( &AVL10mil[i] );
    AVLcria( &AVL100mil[i] );
  }
  Ntempos retorno;
  // Escrevendo tempos de operações nas árvores para cada árvore
     // Escrevendo tempos para as Árvore de 100, 1000, 10000 e 100000 elementos
  for (i = 0; i < 4; i++){
    retorno.vet_esc[i].insercao = AVLInsereTudo(p[i], pot10(i + 2), vet[i]);
    retorno.vet_esc[i].busca    = AVLBuscaEmTudo(p[i], pot10(i + 2) , vet[i]);
    retorno.vet_esc[i].remocao  = AVLRemoveEmTudo(p[i], pot10(i + 2), vet[i]);
  }
  // Destruição de todas as árvores criadas
  for (i = 0; i < 10; i++){
    AVLdestroi(&AVLcem[i]);
    AVLdestroi(&AVLmil[i]);
    AVLdestroi(&AVL10mil[i]);
    AVLdestroi(&AVL100mil[i]);
  }
  return retorno;
}
