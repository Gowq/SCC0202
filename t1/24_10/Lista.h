#ifndef _LISTA_H_
#define _LISTA_H_

#include "Pilha.h"

typedef struct Fila{
	Pilha *pilha;	
	struct Fila *prox;
}FilaCaixa;

typedef struct FilaDetectada{
	FilaCaixa *inicio;
	int n;
}Fila;

Fila* CriaFila();
int FilaVazia(Fila *fila);
int InserirFila(Fila *fila, Pilha *caixa);
FilaCaixa *RetornaCaixa(Fila *fila);
int RemoveFila(Fila *fila);
#endif