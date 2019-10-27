#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "lo.h" // Lista Ordenada
#include "Tempos.h"
#include "pot10.h" // potência de 10 que retorna inteiro
typedef ListaOrd LO;

/* LOInsereTudo: Função que insere todos os elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   LO *a[]: Vetor de árvores LO contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem inseridos na árvore */
double LOInsereTudo(LO a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++)
    for(Ielem = 0; Ielem < N; Ielem++)
      LOinsere(&a[Iar], vet[Ielem]);
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LOBuscaEmTudo: Função que busca os primeiros N/2 elementos do vetor de inteiros nos vetores de Árvores
   Parâmetros:
   LO a[]: Vetor de árvores LO contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem buscados na árvore */
double LOBuscaEmTudo(LO a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LObusca(a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LObusca(a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LORemoveEmTudo: Função que remove metade dos elementos de cada árvore do vetor de árvores
                  a partir dos N/2 primeiro elementos do vetor de inteiro
   Parâmetros:
   LO a[]: Vetor de árvores LO contendo 10 árvores com N elementos cada
   int N: número de elementos a serem inseridos nas árvores. Também o tamanho do vetor
   int vet[]: Vetor contendo os elementos a serem removidos da árvore */
double LORemoveEmTudo(LO a[], int N, int vet[]){
  int Iar, Ielem; // índices da árvore e do elemento, respectivamente
  clock_t inicio, fim;
  inicio = clock();
  for (Iar = 0; Iar < 10; Iar++){
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca por N/2 elementos existentes
      LOremover(&a[Iar], vet[Ielem]);
    for(Ielem = 0; Ielem < N/2; Ielem++) // Busca N/2 vezes, um elemento inexistente
      LOremover(&a[Iar], -1); // Assumindo que não serão encontrados números negativos
  }
  fim = clock();
  double tempo = (fim - inicio) / (double) CLOCKS_PER_SEC;
  tempo /= 10.0; // divide o tempo por 10 para fazer uma média
  return tempo;
}

/* LOtempos: Função que realiza todos os cálculos de tempo para operações com árvores de 100, 1000, dez mil
              e cem mil elementos (0 a 3, respectivamente)
   Parâmetros
   int *vet[4]: Vetor de vetores de números inteiros de 100, 1000, 10000, 100000 elementos */
Ntempos LOtempos(int *vet[4]){
  // vetores para Árvore Binária de Busca
  LO LOcem[10], LOmil[10], LO10mil[10], LO100mil[10];
  LO *p[4] = {NULL, NULL, NULL, NULL}; // ponteiro auxiliar para o loop a seguir
  p[0] = LOcem; p[1] = LOmil; p[2] = LO10mil; p[3] = LO100mil;
  // Aloca memória para os vetores crescentes
  int i;
  // Operações de Criação das listas
  for (i = 0; i < 10; i++){
    LOcria( &LOcem[i] );
    LOcria( &LOmil[i] );
    LOcria( &LO10mil[i] );
    LOcria( &LO100mil[i] );
  }
  Ntempos retorno;
  int tam;
  // Escrevendo tempos de operações nas árvores para cada árvore
     // Escrevendo tempos para as Árvore de 100, 1000, 10000 e 100000 elementos
  for (i = 0; i < 4; i++){
    tam = pot10(i + 2);
    retorno.vet_esc[i].insercao = LOInsereTudo(p[i], tam, vet[i]);
    retorno.vet_esc[i].busca    = LOBuscaEmTudo(p[i], tam, vet[i]);
    retorno.vet_esc[i].remocao  = LORemoveEmTudo(p[i], tam, vet[i]);
  }
  // Destruição de todas as árvores criadas
  for (i = 0; i < 10; i++){
    LOdestroi(&LOcem[i]);
    LOdestroi(&LOmil[i]);
    LOdestroi(&LO10mil[i]);
    LOdestroi(&LO100mil[i]);
  }
  return retorno;
}
