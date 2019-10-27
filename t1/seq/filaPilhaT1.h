#ifndef FILA
#define FILA
#define TamFila 100
#include "pilhaT1.h"

typedef Pilha caixa;

typedef struct fila {
    caixa vet[TamFila];
    int ini, fim, total;
} Fila;

void cria_fila(Fila* f);

int insere_na_fila(Fila* f, caixa x);

int remove_fila(Fila* f, caixa* x);

int vazia_fila(Fila f);

int cheia_fila(Fila f);

#endif
