#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void ABBcria(ABB *a) {
    a->raiz = NULL; // ABBcria uma arvore vazia
    return;
}

void ABBdestroiSub(ABBNo *p) {
    if (p == NULL)
        return;
    ABBdestroiSub(p->esq); // destroi subarvore esquerda
    ABBdestroiSub(p->dir); // destroi subarvore direita
    free(p); // apaga o raiz da subarvore
    return;
}

void ABBdestroi(ABB *a) {
    ABBdestroiSub(a->raiz); // inicia recursao
    a->raiz = NULL;
    return;
}

int ABBvazia(ABB a) {
    return a.raiz == NULL;
}

void ABBimprimeSub(ABBNo *p) {
    printf("{");
    if (p != NULL) {
        printf("%d, ", p->info);
        ABBimprimeSub(p->esq);
        printf(", ");
        ABBimprimeSub(p->dir);
    }
    printf("}");
    return;
}

void ABBimprime(ABB a) {
    ABBimprimeSub(a.raiz);
    printf("\n");
    return;
}

int ABBalturaSub(ABBNo *p) {
    int aesq, adir;
    if (p == NULL)
        return 0; // arvore nula
    aesq = ABBalturaSub(p->esq); // ABBaltura da subarvore esquerda
    adir = ABBalturaSub(p->dir); // ABBaltura da subarvore direita
    return (aesq > adir)? aesq + 1 : adir + 1;
}

int ABBaltura(ABB a) {
    return ABBalturaSub(a.raiz); // inicia recursao
}

void ABBpreOrdemSub(ABBNo *p) {
    if (p != NULL) {
        printf("%d ", p->info); // processa antes de varrer subarvores
        ABBpreOrdemSub(p->esq); // varre lado esquerdo
        ABBpreOrdemSub(p->dir); // varre lado direito
    }
    return;
}

void ABBpreOrdem(ABB a) {
    ABBpreOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

void ABBemOrdemSub(ABBNo *p) {
    if (p != NULL) {
        ABBemOrdemSub(p->esq); // varre lado esquerdo
        printf("%d ", p->info); // processa entre uma subarvore e a outra
        ABBemOrdemSub(p->dir); // varre lado direito
    }
    return;
}

void ABBemOrdem(ABB a) {
    ABBemOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

void ABBposOrdemSub(ABBNo *p) {
    if (p != NULL) {
        ABBposOrdemSub(p->esq); // varre lado esquerdo
        ABBposOrdemSub(p->dir); // varre lado direito
        printf("%d ", p->info); // processa apos subarvores
    }
    return;
}

void ABBposOrdem(ABB a) {
    ABBposOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

int ABBbuscaSub(ABBNo *p, int x) {
    if (p == NULL)
        return 0; // nao achou
    if (p->info == x)
        return 1; // achou
    return (x < p->info) ? ABBbuscaSub(p->esq, x) : ABBbuscaSub(p->dir, x);
}

int ABBbusca(ABB a, int x) {
    return ABBbuscaSub(a.raiz, x); // inicia recursao
}

ABBNo *ABBcriaNo(int info, ABBNo *esq, ABBNo *dir) {
    ABBNo *nova = malloc(sizeof(ABBNo));
    if (nova != NULL) {
        nova->info = info;
        nova->esq = esq;
        nova->dir = dir;
    }
    return nova;
}

int ABBinsercaoSub(ABBNo **p, int x) {
    // p => ABBNo **; *p => ABBNo *; **p => ABBNo
    if (*p == NULL) {
        *p = ABBcriaNo(x, NULL, NULL); // insere
        return *p == NULL; // erro de memoria ou sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, achou
    return (x < (*p)->info) ? ABBinsercaoSub(&((*p)->esq), x) : ABBinsercaoSub(&((*p)->dir), x);
}

int ABBinsercao(ABB *a, int x) {
    return ABBinsercaoSub(&(a->raiz), x); // inicia recursao
}

int ABBremocaoSub(ABBNo **p, int x) {
    // p => ABBNo **; *p => ABBNo *; **p => ABBNo
    int numFilhos = 0;
    ABBNo *aux, *paiAux;
    if (*p == NULL)
        return 1; // erro, intento nao existe
    if ((*p)->info == x) { // achou, entao remove
        if ((*p)->esq != NULL)
            numFilhos++;
        if ((*p)->dir != NULL)
            numFilhos++;
        switch (numFilhos) {
            case 0: // nenhum filho
                free(*p); // apaga
                *p = NULL; // atualiza encadeamento
                return 0;
            case 1: // um filho
                aux = *p;
                *p = ((*p)->esq != NULL) ? (*p)->esq : (*p)->dir; // atualiza encadeamento
                free(aux);
                return 0;
            case 2: // dois filhos
                // acha maior filho na subarvore esquerda (aux)
                aux = (*p)->esq;
                paiAux = *p;
                while (aux->dir != NULL) {
                    paiAux = aux;
                    aux = aux->dir;
                }
                (*p)->info = aux->info; // copia info
                return (paiAux->esq == aux) ? ABBremocaoSub(&(paiAux->esq),aux->info) : ABBremocaoSub(&(paiAux->dir),aux->info); // apaga aux e atualiza encadeamento
        }
    }
    return (x < (*p)->info) ? ABBremocaoSub(&((*p)->esq), x) : ABBremocaoSub(&((*p)->dir), x);
}

int ABBremocao(ABB *a, int x) {
    return ABBremocaoSub(&(a->raiz), x); // inicia recursao
}
