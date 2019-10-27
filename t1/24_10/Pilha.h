#ifndef _PILHA_H_
#define _PILHA_H_

#include "ListaCircular.h"

typedef struct Pilha{
	Brinquedo *brinquedo;
	int n;
}Pilha;

Pilha* Cria(int p);
int PilhaCheia(Pilha *s, int p);
int Push(Pilha *s, int p, Brinquedo *novoBrinquedo);
Brinquedo *Topo(Pilha *s);
int tamanho(Pilha *p);

#endif