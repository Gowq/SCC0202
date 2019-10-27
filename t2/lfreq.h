#ifndef lfreq
#define lfreq

typedef int elem;

typedef struct no{
  elem info;
  struct no *ant, *prox;
} LFREQNo;

typedef struct {
  LFREQNo *ini, *fim;
} LFREQ; // Lista Ordenada pela frequência de busca


void LFREQcria(LFREQ *l);
int LFREQinsere(LFREQ *l, elem x);
int LFREQremover(LFREQ *l, elem x);
int LFREQbusca(LFREQ *l, elem x);
void LFREQimprime(LFREQ *l);
int LFREQesta_vazia(LFREQ l);
void LFREQdestroi(LFREQ *l);
#endif
