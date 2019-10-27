#include "listaCircularT1.h"
#include <stdlib.h>

struct no {
  /* ant : elemento anterior da lista
   * prox: próximo elemento da lista */
  struct no *ant, *prox;
  int ind; // índice do elemento
  elem info;
};

void cria_lista(Lista *l) {
  l->ini = NULL;
  l->n = 0;
  return;
}

int insere_na_lista(Lista *l, elem b) {
  No *p;
  // cria no
  p = (No *) malloc(sizeof(No));
  if (p == NULL)
    return -1; // erro
  l->n++;
  // atribui valores
  p->ind = l->n - 1;
  p->info = b;
  p->ant = l->ini->ant;
  p->prox = l->ini;
  // atualiza encadeamento
  if (l->ini == NULL){
    l->ini = p;
    p->ant = p;
    p->prox = p;
  }
  else
    l->ini->ant = p;
  return 0; // funcionou
}

elem remove_da_lista(Lista *l, int i) {
  No *p, *ant;
  elem elemento, NULO; // NULO = brinquedo Nulo
  NULO.id = -1;
  NULO.modelo[0] = NULL;
  if (!vazia_lista(*l)) {
    p = l->ini;
    while (p->prox != l->ini) { // buscando
      if (p->ind == i) { // achou
	elemento = p->info;
	l->n--;
	if (p == l->ini){
	  if (l->n == 1){
	    free(p);
	    return elemento;
	  }
	  // elimina primeiro
	  l->ini->prox->ant = l->ini->ant;
	  l->ini = l->ini->prox;
	}
	else
	  // elimina outro
	  p->prox->ant = p->ant;
	free(p);
	atualiza_indice(l, i);
        return elemento;
      }
      p = p->prox; // procura próximo elemento
    }
  }
  return NULO; // nao achou
}

int vazia_lista(Lista l) {
  if(l.ini == NULL)
    return 1;
  else
    return 0;
}

void atualiza_indice(Lista *l, int i){
  No *p;
  p = l->ini->ant;
  // atualiza índice até chegar no elemento de índice i a ser removido
  while (p->ant->ind < i){
    p->ant->ind--;
    p = p->ant->ant;
  }
  return;
}
