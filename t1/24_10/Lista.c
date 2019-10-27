#include "Pilha.h"
#include "Lista.h"
#include <stdlib.h>

Fila* CriaFila(){
	Fila *nova;
	nova = (Fila*) malloc(sizeof(Fila));

	nova->inicio = NULL;
	nova->n = -1;
	return nova;
}

int FilaVazia(Fila *fila){
	if (fila->n == -1) return 1;
	return 0;
}

int InserirFila(Fila *fila, Pilha *caixa){
	FilaCaixa *novaCaixa, *caixaAtual;
	novaCaixa = malloc(sizeof(FilaCaixa));
	if (novaCaixa == NULL) return 0;

	if (FilaVazia(fila)){				
		novaCaixa->pilha = caixa;

		novaCaixa->prox = NULL;
		fila->inicio = novaCaixa;
		fila->n++;
		return 1;
	} else {
		caixaAtual = fila->inicio;
		while(caixaAtual->prox != NULL){		
			caixaAtual = caixaAtual->prox;
		}

		novaCaixa->pilha = caixa;

		novaCaixa->prox = caixaAtual->prox;
		caixaAtual->prox = novaCaixa;
		fila->n++;
		return 1;
	}
}

FilaCaixa *RetornaCaixa(Fila *fila){
	return fila->inicio;
}

int RemoveFila(Fila *fila){
	FilaCaixa *q;
	q = fila->inicio;
	fila->inicio = fila->inicio->prox;
	fila->n--;
	free(q);
	return 1;
}