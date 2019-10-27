#include <stdlib.h>
#include <stdio.h>
#include "los.h"

int LOScria(ListaOrdSent *l) {
    l->sentinela = malloc(sizeof(LOSNo));
    if (l->sentinela == NULL)
        return 1; // erro
    l->sentinela->prox = NULL;
    l->ini = l->sentinela;
    return 0; // sucesso
}

void LOSdestroi(ListaOrdSent *l) {
    LOSNo *aux;
    while (l->ini != NULL) {
        aux = l->ini;
        l->ini = l->ini->prox;
        free(aux);
    }
    l->sentinela = NULL;
    return;
}

void LOSbusca_interna(ListaOrdSent *l, elem x, LOSNo **ant, LOSNo **p) {
    // ant, p => LOSNo **
    // *ant, *p => LOSNo *
    // **ant, **p => LOSNo
    l->sentinela->info = x;
    *ant = NULL;
    *p = l->ini;
    while ((*p)->info < x) {
        *ant = *p;
        *p = (*p)->prox;
    }
    return;
}

int LOSinsere(ListaOrdSent *l, elem x) {
    LOSNo *novo, *ant, *p;
    LOSbusca_interna(l, x, &ant, &p); // busca primeiro maior ou igual a x
    if (p != l->sentinela && p->info == x)
        return 1; // erro, elemento repetido
    novo = (LOSNo *) malloc(sizeof(LOSNo));
    if (novo == NULL)
        return 1; // erro, memoria insuficiente
    novo->info = x; // copia informacao
    // atualiza ponteiros
    novo->prox = p;
    if (ant == NULL)
        l->ini = novo; // insere no inicio
    else
        ant->prox = novo; // insere no meio ou fim
    return 0; // sucesso
}

int LOSremover(ListaOrdSent *l, elem x) {
    LOSNo *ant, *p;
    LOSbusca_interna(l, x, &ant, &p);
    if (p == l->sentinela || p->info != x)
        return 1; // erro
    if (l->ini == p)
        l->ini = l->ini->prox; // remove do inicio
    else
        ant->prox = p->prox; // remove do meio ou do final
    free(p);
    return 0; // sucesso
}

void LOSimprime(ListaOrdSent l) {
    while (l.ini != l.sentinela) {
        printf("%d ", l.ini->info);
        l.ini = l.ini->prox;
    }
    printf("\n");
    return;
}

int LOSbusca(ListaOrdSent l, elem x) {
    l.sentinela->info = x;
    while(l.ini->info < x)
        l.ini = l.ini->prox;
    return (l.ini != l.sentinela && l.ini->info == x);
}

int LOSesta_vazia(ListaOrdSent l) {
    return (l.ini == l.sentinela);
}
