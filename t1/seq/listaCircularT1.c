#include "brinquedo.h"
#include "listaCircularT1.h"
#include <string.h>
// #include <stdlib.h>

void cria_lista(Lista *l) {
  l->n = 0;
  int i;
  // -1 : ID inválido ou de elemento vazio
  // se o brinquedo está vazio, modelo do brinquedo deve estar NULL
  for (i = 0; i < MAX; i++){
    l->ele[i].info.id = -1;
    strcpy(l->ele[i].info.modelo, "\0");
  }
  return;
}

int insere_na_lista(Lista *l, ele b) {
  if (l->n == MAX)
    return -1; // Lista cheia, erro
    No p;
    l->ele[l->n - 1].prox = l->n;
    // cria nó
    // atribui valores
    p.info = b;
    p.prox = 0; // aponta para o início da lista, que é sempre 0
    l->ele[l->n] = p;
    l->n++; // Atualiza o número de brinquedos
    return 0;
}

ele remove_da_lista(Lista *l, int i) {
  // Se Lista estiver vazia, devolve brinquedo nulo
  // Brinquedo Nulo: id = -1, modelo = NULL
  Brinquedo Nulo, B;
  Nulo.id = -1;
  strcpy(Nulo.modelo,"\0");
  if ( vazia_lista(*l) )
    return Nulo;
  B = l->ele[i].info;
  if (l->n > 1){
    l->ele[i-1].prox = l->ele[i].prox;
  }
  int j;
  for (j = i; j < l->n - 1; j++)
    l->ele[j] = l->ele[j+1];
    l->ele[l->n].prox = -1;
    l->ele[l->n].info.id = -1;
    strcpy(l->ele[l->n].info.modelo,"\0");
  l->n--;
  return B;
}

int vazia_lista(Lista l) {
	if(l.n == 0)
		return 1;
	else
		return 0;
}

int cheia_lista(Lista l) {
	if(l.n == MAX)
		return 1;
	else
		return 0;
}
