#define MAX 1000
#include "pilhaT1.h"

void cria_pilha(Pilha* p){
    p->topo = -1;
    return;
}

int push(Pilha* p, elem x){
    if (cheia_pilha(*p))
        return 0;
    p->topo++;
    p->vet[p->topo] = x;
    return 1;
}

int pop(Pilha* p, elem* x) {
    if (isEmpty(*p))
        return 0;
    p->topo--;
    *x = p->vet[p->topo];
    return 1;
}

int top(Pilha p, elem* x) {
    if (isEmpty(p))
        return 0;
    *x = p.vet[p.topo];
    return 1;
}

int cheia_pilha(Pilha p) {
	return p.topo + 1 == MAX;
}


int isEmpty(Pilha p) {
    return p.topo == -1;
}
