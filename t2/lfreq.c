#include <stdlib.h>
#include <stdio.h>
#include "lfreq.h"

void LFREQcria(LFREQ *l) {
    l->ini = NULL;
    l->fim = NULL;
    return;
}

void LFREQbusca_interna(LFREQ *l, elem x, LFREQNo **ant, LFREQNo **p) {
  // ant, p => LFREQNo **
  // *ant, *p => LFREQNo *
  // **ant, **p => LFREQNo
  *ant = NULL;
  *p = l->ini;
  while (*p != NULL && (*p)->info < x) {
    *ant = *p;
    *p = (*p)->prox;
  }
  return;
}

int LFREQinsere(LFREQ *l, elem x) {
  LFREQNo *p;
  // cria no
  p = (LFREQNo *) malloc(sizeof(LFREQNo));
  if (p == NULL)
    return 1; // erro
  // atribui valores
  p->info = x;
  /* p->ant = l->ini->ant; */
  /* p->prox = l->ini; */
  // atualiza encadeamento
  if (l->ini == NULL){
    l->ini = p;
    l->fim = p;
    p->ant = l->ini;;
    p->prox = l->ini;
  }
  else{
    l->fim->prox = p;
    p->ant = l->fim;
    l->fim = p;
    l->fim->prox = l->ini;
    l->ini->ant = l->fim;
  }
  return 0; // funcionou
}

int LFREQremover(LFREQ *l, elem x) {
    LFREQNo *ant, *p;
    LFREQbusca_interna(l, x, &ant, &p);
    if (p == NULL || p->info != x)
        return 1; // erro
    if (l->ini == p)
        l->ini = l->ini->prox; // remove do inicio
    else
        ant->prox = p->prox; // remove do meio ou do final
    free(p);
    return 0; // sucesso
}

void LFREQimprime(LFREQ *l) {
  LFREQNo *aux = l->ini; // guarda valor inicial do início da lista
  LFREQNo *p = l->ini;
  printf("%d ", l->ini->info);
  p = p->prox;
  while (p == aux) { // Como a lista é circular, se l.ini voltar a ser igual ao início, para de imprimir
    printf("%d ", p->info);
    p = l->ini->prox; // se aproveitando do fato de que a lista foi inserida por valor na função
  }
  printf("\n");
  return;
}

/* Troca: Realiza a troca dos elementos entre o nó atual e o nó anterior
          Nesta TAD, Troca só roda depois que o elemento for encontrado
   Parâmetros: 
   LFREQNo *x: Nó em que o elemento foi encontrado */
void Troca(LFREQNo *x){
  elem aux = x->ant->info;
  x->ant->info = x->info;
  x->info = aux;
}

/* LFREQbusca(): Procura por x na busca, e o coloca na posição imediatamente anterior da lista.
                 Quando x e encontrado em um nó, apenas as informações dos nós é trocada, sem necessidade
		 de atualização dos encadeamentos. Deste modo, menos operações são realizadas.
		 Para isto, a função Troca é chamada
   Parâmetros:
   LFREQ *l: Lista a ser buscada
   elem   x: Número a ser buscado, e atualizado em caso de êxito
   retorno:1 em caso de sucesso na busca, e 0 em caso de falha */ 
int LFREQbusca(LFREQ *l, elem x) {
  LFREQNo *p = l->ini;
  if (p == NULL) // Não se acha nada em lista vazia
    return 0;
  if (p->info == x)
    return 1; // Se x estiver no início da lista, não é necessário atualizar
  // Como a lista é circular, se
  p = p->prox;
  while(p != l->ini && p->info != x)    
    p = p->prox;
  int retorno;
  if (p->info == x){
    retorno = 1;
    Troca(p);
  } else retorno = 0;
  return (p != NULL && retorno);
}

int LFREQesta_vazia(LFREQ l) {
    return (l.ini == NULL);
}
void LFREQdestroi(LFREQ *l){
  if (l->ini == NULL)
    return;
  LFREQNo *p;
  p = l->ini;
  do {
    l->ini = l->ini->prox;
    free(p);
    p = l->ini;
  } while (l->ini != l->fim);
  free(l->fim);
  l->fim = NULL;
  return;
}
