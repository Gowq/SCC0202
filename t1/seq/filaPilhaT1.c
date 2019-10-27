#include "filaPilhaT1.h"

void cria_fila(Fila* f) {
    f->total = 0;
    f->ini = 0;
    f->fim = 0;
    return;
}

int insere_na_fila(Fila* f, caixa x) {
    if (cheia_fila(*f))
        return 1;
    f->vet[f->fim] = x;
    f->total++;
    if (f->fim == TamFila - 1)
        f->fim = 0;
    else
        f->fim++;
    return 0;
}

int remove_fila(Fila* f, caixa* x) {
    if (vazia_fila(*f))
        return 1;
    *x = f->vet[f->ini];
    f->total--;
    if (f->ini == TamFila -1)
        f->ini = 0;
    else
        f->ini++;
    return 0;
}

int vazia_fila(Fila f) {
    //return (f.total == 0);
    if (f.total == 0)
        return 1;
    return 0;
}

int cheia_fila(Fila f) {
    //return (f.total == TamFila);
    if (f.total == TamFila)
        return 1;
    return 0;
}
