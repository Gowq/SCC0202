#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Pilha.h"
#include "ListaCircular.h"

Pilha* Cria(int p){
	Pilha *nova = NULL;
	nova = (Pilha*) malloc(sizeof(Pilha)*p);

	nova->n = -1;

	return nova;
}

int PilhaCheia(Pilha *s, int p){
	if (s->n >= p) return 1;
	return 0;    
}

int Push(Pilha *s, int p, Brinquedo *novoBrinquedo){
    if (PilhaCheia(s, p)) return 0;

    s->n++;
    Brinquedo g;
    g.nSerie = novoBrinquedo->nSerie;
    strcpy(g.modelo, novoBrinquedo->modelo);
    s[s->n].brinquedo = &g;
    //printf("Dentro do push: %s e tam %d\n", s[s->n].brinquedo->modelo, s->n);
    return 1;
}

Brinquedo* Topo(Pilha *s){
	printf("Dentro do topo: %s e tam %d\n", s[s->n].brinquedo->modelo, s->n);
    return s[s->n].brinquedo;
}

int tamanho(Pilha *p){
	return p->n;
}