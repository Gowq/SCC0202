    #ifndef PILHA
#define PILHA
#include "brinquedo.h"
#define TamPilha 100

typedef Brinquedo elem;

typedef struct pilha {
    elem vet[TamPilha];
    int topo;
} Pilha;

void cria_pilha(Pilha* p);

int push(Pilha* p, elem x);

int top(Pilha p, elem* x);

int cheia_pilha(Pilha p);

int isEmpty(Pilha p);

int pop(Pilha* p, elem* x);

#endif
