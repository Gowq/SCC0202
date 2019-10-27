#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "los.h" // Lista Ordenada com Sentinela
#include "Tempos.h"
#include "pot10.h"
typedef ListaOrdSent LOS;

/* LOSInsereTudo: Função que insere todos os elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   LOS *a[]: Vetor de árvores LOS contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem inseridos na árvore */
double LOSInsereTudo(LOS a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++)
    for(Ielem = 0; Ielem < N; Ielem++)
      LOSinsere(&a[Iar], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;  
}

/* LOSBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   LOS a[]: Vetor de árvores LOS contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na árvore */
double LOSBuscaEmTudo(LOS a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LOSbusca(a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LOSbusca(a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LOSRemoveEmTudo: Função que remove metade dos elementos de cada árvore do vetor de árvores
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   LOS a[]: Vetor de árvores LOS contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da árvore */
double LOSRemoveEmTudo(LOS a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LOSremover(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LOSremover(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LOStempos: Função que realiza todos os cálculos de tempo para operações com árvores de 100, 1000, dez mil
              e cem mil elementos (0 a 3, respectivamente)
   Parâmetros
   int *vet[4]: Vetor de vetores de números inteiros de 100, 1000, 10000, 100000 elementos */
Ntempos LOStempos(int *vet[4]){
  // vetores para Árvore Binária de Busca
  LOS LOScem[10], LOSmil[10], LOS10mil[10], LOS100mil[10];
  // Aloca memória para os vetores crescentes
  int i;  
  // Operações de Criação das listas
  for (i = 0; i < 10; i++){
    LOScria( &LOScem[i] );
    LOScria( &LOSmil[i] );
    LOScria( &LOS10mil[i] );
    LOScria( &LOS100mil[i] );
  }
  Ntempos retorno;
  // Escrevendo tempos de operações nas árvores para cada árvore
     // Escrevendo tempos para as Árvore de 100, 1000, 10000 e 100000 elementos
  for (i = 0; i < 4; i++){
    retorno.vet_esc[i].insercao = LOSInsereTudo(LOScem, pot10(i + 2), vet[i]);
    retorno.vet_esc[i].busca    = LOSBuscaEmTudo(LOScem, pot10(i + 2) , vet[i]);
    retorno.vet_esc[i].remocao  = LOSRemoveEmTudo(LOScem, pot10(i + 2), vet[i]);
  }
  // Destruição de todas as árvores criadas
  for (i = 0; i < 10; i++){
    LOSdestroi(&LOScem[i]);
    LOSdestroi(&LOSmil[i]);
    LOSdestroi(&LOS10mil[i]);
    LOSdestroi(&LOS100mil[i]);
  }
  return retorno;
}
