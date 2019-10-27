#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "abb.h" // Árvore Binária de Busca
#include "Tempos.h"
#include "ABBtempos.h"
#include "pot10.h"

/* ABBInsereTudo: Função que insere todos os elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   ABB *a[]: Vetor de árvores ABB contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem inseridos na árvore */
double ABBInsereTudo(ABB a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++)
    for(Ielem = 0; Ielem < N; Ielem++)
      ABBinsercao(&a[Iar], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* ABBBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   ABB a[]: Vetor de árvores ABB contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na árvore */
double ABBBuscaEmTudo(ABB a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      ABBbusca(a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      ABBbusca(a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* RemoveEmTudo: Função que remove metade dos elementos de cada árvore do vetor de árvores
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   ABB a[]: Vetor de árvores ABB contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da árvore */
double RemoveEmTudo(ABB a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      ABBremocao(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      ABBremocao(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
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
Ntempos ABBtempos(int *vet[4]){
  // vetores para Árvore Binária de Busca
  ABB ABBcem[10], ABBmil[10], ABB10mil[10], ABB100mil[10];
  ABB *p[4] = {NULL, NULL, NULL, NULL}; //Vetor de ponteiros auxiliar para o loop
  p[0] = ABBcem; p[1] = ABBmil; p[2] = ABB10mil; p[3] = ABB100mil;
  int i;
  // Operações de Criação das listas
  for (i = 0; i < 10; i++){
    ABBcria( &ABBcem[i] );
    ABBcria( &ABBmil[i] );
    ABBcria( &ABB10mil[i] );
    ABBcria( &ABB100mil[i] );
  }
  Ntempos retorno;
  // Escrevendo tempos de operações nas árvores para cada árvore
     // Escrevendo tempos para as Árvore de 100, 1000, 10000 e 100000 elementos
  for (i = 0; i < 4; i++){
    retorno.vet_esc[i].insercao = ABBInsereTudo(p[i], pot10(i + 2), vet[i]);
    retorno.vet_esc[i].busca    = ABBBuscaEmTudo(p[i], pot10(i + 2) , vet[i]);
    retorno.vet_esc[i].remocao  = RemoveEmTudo(p[i], pot10(i + 2), vet[i]);
  }
  // Destruição de todas as árvores criadas
  for (i = 0; i < 10; i++){
    ABBdestroi(&ABBcem[i]);
    ABBdestroi(&ABBmil[i]);
    ABBdestroi(&ABB10mil[i]);
    ABBdestroi(&ABB100mil[i]);
  }
  return retorno;
}
