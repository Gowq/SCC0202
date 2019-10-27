#ifndef _lo_h
#define _lo_h
typedef int elem;

typedef struct LOno {
    elem info;
    struct LOno *prox;
} LONo;

typedef struct {
    LONo *ini;
} ListaOrd;

void LOcria(ListaOrd *l);
int LOinsere(ListaOrd *l, elem x);
int LOremover(ListaOrd *l, elem x);
int LObusca(ListaOrd l, elem x);
void LOimprime(ListaOrd l);
int LOesta_vazia(ListaOrd l);
void LOdestroi(ListaOrd *l);
#endif
