#ifndef _los
#define _los
typedef int elem;

typedef struct los_no {
    elem info;
    struct los_no *prox;
} LOSNo;

typedef struct {
    LOSNo *ini, *sentinela;
} ListaOrdSent;

int LOScria(ListaOrdSent *l);
void LOSdestroi(ListaOrdSent *l);
int LOSinsere(ListaOrdSent *l, elem x);
int LOSremover(ListaOrdSent *l, elem x);
int LOSbusca(ListaOrdSent l, elem x);
void LOSimprime(ListaOrdSent l);
int LOSesta_vazia(ListaOrdSent l);
#endif
