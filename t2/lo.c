#include <stdlib.h>
#include <stdio.h>
#include "lo.h"

void LOcria(ListaOrd *l) {
    l->ini = NULL;
    return;
}

void busca_interna(ListaOrd *l, elem x, LONo **ant, LONo **p) {
    // ant, p => LONo **
    // *ant, *p => LONo *
    // **ant, **p => LONo
    *ant = NULL;
    *p = l->ini;
    while (*p != NULL && (*p)->info < x) {
        *ant = *p;
        *p = (*p)->prox;
    }
    return;
}

int LOinsere(ListaOrd *l, elem x) {
    LONo *novo, *ant, *p;
    busca_interna(l, x, &ant, &p); // busca primeiro maior ou igual a x
    if (p != NULL && p->info == x)
        return 1; // erro, elemento repetido
    novo = (LONo *) malloc(sizeof(LONo));
    if (novo == NULL)
        return 1; // erro, memoria insuficiente
    novo->info = x; // copia informacao
    // atualiza ponteiros
    novo->prox = p;
    if (ant == NULL)
        l->ini = novo; // LOinsere no inicio
    else
        ant->prox = novo; // LOinsere no meio ou fim
    return 0; // sucesso
}

int LOremover(ListaOrd *l, elem x) {
    LONo *ant, *p;
    busca_interna(l, x, &ant, &p);
    if (p == NULL || p->info != x)
        return 1; // erro
    if (l->ini == p)
        l->ini = l->ini->prox; // remove do inicio
    else
        ant->prox = p->prox; // remove do meio ou do final
    free(p);
    return 0; // sucesso
}

void LOimprime(ListaOrd l) {
    while (l.ini != NULL) {
        printf("%d ", l.ini->info);
        l.ini = l.ini->prox;
    }
    printf("\n");
    return;
}

int LObusca(ListaOrd l, elem x) {
    while(l.ini != NULL && l.ini->info < x)
        l.ini = l.ini->prox;
    return (l.ini != NULL && l.ini->info == x);
}

int LOesta_vazia(ListaOrd l) {
    return (l.ini == NULL);
}

void LOdestroi(ListaOrd *l){
  LONo *p = l->ini;
  while (l->ini != NULL){
    l->ini = l->ini->prox;
        free(p);
        p = l->ini;
  }
  return;
}
