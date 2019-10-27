 #include <time.h>
#include <stdlib.h>
#include <math.h>
#include "lfreq.h" // Lista ordenada por frequência de busca
#include "Tempos.h"
#include "pot10.h"
/* LFREQInsereTudo: Função que insere todos os elementos do vetor de inteiros nos vetores de Listas
   Parâmetros:
   LFREQ *a[]: Vetor de listas LFREQ contendo 10 listas com N elementos cada
   int N: número de elementos a serem inseridos nas listas. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem inseridos na árvore */
double LFREQInsereTudo(LFREQ a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++)
    for(Ielem = 0; Ielem < N; Ielem++)
      LFREQinsere(&a[Iar], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LFREQBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Listas
   Parâmetros:
   LFREQ a[]: Vetor de listas LFREQ contendo 10 listas com N elementos cada
   int N: número de elementos a serem inseridos nas listas. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na árvore */
double LFREQBuscaEmTudo(LFREQ a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LFREQbusca(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LFREQbusca(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LFREQRemoveEmTudo: Função que remove metade dos elementos de cada árvore do vetor de listas
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   LFREQ a[]: Vetor de listas LFREQ contendo 10 listas com N elementos cada
   int N: número de elementos a serem inseridos nas listas. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da árvore */
double LFREQRemoveEmTudo(LFREQ a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LFREQremover(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LFREQremover(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LFREQtempos: Função que realiza todos os cálculos de tempo para operações com listas de 100, 1000, dez mil
              e cem mil elementos (0 a 3, respectivamente)
   Parâmetros
   int *vet[4]: Vetor de vetores de números inteiros de 100, 1000, 10000, 100000 elementos */
Ntempos LFREQtempos(int *vet[4]){
  // vetores para Árvore Binária de Busca
  LFREQ LFREQcem[10], LFREQmil[10], LFREQ10mil[10], LFREQ100mil[10];
  LFREQ *p[] = {NULL, NULL, NULL, NULL}; // ponteiro auxiliar para o loop a seguir
  p[0] = LFREQcem; p[1] = LFREQmil; p[2] = LFREQ10mil; p[3] = LFREQ100mil;
  // Aloca memória para os vetores crescentes
  int i;
  // Operações de Criação das listas
  for (i = 0; i < 10; i++){
    LFREQcria( &LFREQcem[i] );
    LFREQcria( &LFREQmil[i] );
    LFREQcria( &LFREQ10mil[i] );
    LFREQcria( &LFREQ100mil[i] );
  }
  Ntempos retorno;
  // Escrevendo tempos de operações nas listas para cada árvore
     // Escrevendo tempos para as Árvore de 100, 1000, 10000 e 100000 elementos
  for (i = 0; i < 4; i++){
    retorno.vet_esc[i].insercao = LFREQInsereTudo(p[i], (int) pot10(i + 2), vet[i]);
    retorno.vet_esc[i].busca    = LFREQBuscaEmTudo(p[i], (int) pot10(i + 2) , vet[i]);
    retorno.vet_esc[i].remocao  = LFREQRemoveEmTudo(p[i], (int) pot10(i + 2), vet[i]);
  }
  // Destruição de todas as listas criadas
  for (i = 0; i < 10; i++){
    LFREQdestroi(&LFREQcem[i]);
    LFREQdestroi(&LFREQmil[i]);
    LFREQdestroi(&LFREQ10mil[i]);
    LFREQdestroi(&LFREQ100mil[i]);
  }
  return retorno;
}
