#ifndef LISTA
#define LISTA
typedef Brinquedo ele;
// Nó foi criado aqui porque não foi implementado como ponteiro.
typedef struct no {
  int prox;
  ele info;
} No;

typedef struct {
  /* n  : número atual de brinquedos na lista. Se n == 0, então a lista está vazia      */
  int n, inicio, fim;
  No ele[MAX];
} Lista;

void cria_lista(Lista *l);
int insere_na_lista(Lista *l, ele b);
Brinquedo remove_da_lista(Lista *l, int i);
int vazia_lista(); // 1 - se vazia, e 0 se não vazia
int cheia_lista(); // 1 -  se nº de elementos é igual a MAX, 0 se não

#endif
