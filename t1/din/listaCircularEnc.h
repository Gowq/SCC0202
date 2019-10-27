/* TAD para a lista circular dinâmica */
#include "brinquedo.h"
#ifndef LISTACIRCULART1
#define LISTACIRCULART1

typedef Brinquedo elem;
typedef struct no No;

typedef struct {
  No *ini;
  int n;
} Lista;

/* Cria a Lista, zerando o número total de elementos, e colocando o elemento inicial como nulo */
void cria_lista(Lista *l);

/* Insere elemento b na lista. elem, na verdade é um 'alias' para o tipo Brinquedo
 *  *l: ponteiro para tipo Lista
 *  b : Brinquedo a ser inserido na lista
 *  retorno:
 *  -1 : Erro ao alocar memória para o ponteiro No
 *  0  : Sucesso */
int insere_na_lista(Lista *l, elem b);

/* Remove o i-ézimo elemento da lista
   *l: Ponteiro para tipo Lista
   i : ordem do elemento na lista
   retorno:
   B   : Brinquedo do tipo elemento que estava na posição i na lista
   NULO: Brinquedo Nulo do tipo elemento (id = -1, modelo[0] = NULL), caso elemento i não seja encontrado */
elem remove_da_lista(Lista *l, int i);

// Descobre se a lista está vazia, ou não.
int vazia_lista(Lista l); // 1 - se vazia, e 0 se não vazia

/* Atualiza os índices dos elementos da lista em caso de retirada do i-ézimo elemento:
   Útil somente para auxiliar a função remove_da_lista(). */
void atualiza_indice(Lista *l, int i);
#endif
