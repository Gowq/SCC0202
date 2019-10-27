#include "bb.h"
#include <stdlib.h>
#include <stdio.h>

/* bb: Implementação iterativa da Busca Binária, influenciada por algoritmo similar da Wikipedia
       parâmetros:
          Vetor vet -> Vetor em que a chave ('key') será procurada
          key -> chave a ser procurada no vetor
      retorno:
          -1 -> caso não seja encontrado
          meio -> índice do vetor em que a chave foi encontrada
    */
int bb(Vetor vet, elem key)  {
  if (vet.ultimo == 0)
    return -1;
    elem inf = 0;     // limite inferior
    elem sup = vet.ultimo-1; // limite superior
    elem meio;

    while (inf <= sup) {
        meio = (inf + sup)/2;

        if (vet.v[meio] == key ) // verifica se encontrou
	         return meio;

	    if (vet.v[meio] > key )
	       sup = meio-1; //Procura na metade inferior
	    else
	       inf = meio+1; //Procura na metade superior

      }
    return -1;   // Não encontrado
}

// Cria Vetor dinamicamente, com tam elementos do tipo elem
int BBcria(Vetor *vet, int tam) {
  vet->v = malloc( tam*sizeof(elem) );
  if (vet->v == NULL)
    return 0; // Erro ao alocar memória para vetor
  vet->max = tam;
  vet->ultimo = 0;
  return 1; // Sucesso ao criar vetor
}

// Destrói vetor alocado dinâmicamente
void BBdestroi(Vetor *vet){
  free(vet->v);
  return;
}

int BBvazio(Vetor vet){
  if (vet.ultimo == 0)
    return 1; // vetor vazio
  return 0; // vetor não vazio
}

int BBcheio(Vetor vet){
  if (vet.ultimo == vet.max)
    return 1; // vetor cheio
  return 0; // vetor não cheio
}

// Insere elemento x no vetor na posiçao pos, shiftando os já existentes se necessário e aumentando
// o tamanho corrente do vetor
void insercao(Vetor *vet, int pos, elem x){
  int i;
  vet->ultimo++;
  // Nem entra no looping se ultimo-1 == 0
  for(i = vet->ultimo-1; i > pos; i--)
    vet->v[i] = vet->v[i-1];
  vet->v[pos] = x;
  return;
}

// Insere elemento de forma ordernada no vetor
int  BBinsercao_ordenada(Vetor *vet, elem x){
  if ( BBcheio(*vet) )
    return 0; // Vetor está cheio
  // pos recebe o tamanho corrente do vetor antes de este ser incrementado
  int i = 0, pos = vet->ultimo;
  while (i < vet->ultimo){
    if (x < vet->v[i]){
      pos = i;
      insercao(vet, pos, x);
      return 1; // Sucesso
    }
    i++;
  }
  // Se não houver nenhum elemento do vetor maior que x, posição de x será a última
  insercao(vet, pos, x); // insere elemento
  return 1; // Sucesso
}

/* void BBinsercao(elem *vet, int pos,  elem key) { */
/*     vet[pos++] = key; */
/* } */

/* int BBbusca(elem *v, int tam, elem key, int flag) { */
	
/* 	if (flag == 1) */
/* 		mergesort(v, 0, tam); */
		
/* 	int pos = bb(v, tam, key); */
/* 	return pos; */

/* } */

int BBremocao(Vetor *vetor, elem key) {
  int pos = bb(*vetor, key), i;
  if (pos == -1)
    return -1; // erro ao remover, elemento não encontrado
  for (i = pos; i < vetor->ultimo; i++)
    vetor->v[i] = vetor->v[i+1]; // shiftando os elementos à frente do elemento removido
  vetor->ultimo--;
  return 1;
}

// Imprime vetor criado
void BBimprime(Vetor V){
  int i;
  printf("Tamanho máximo: %d\n", V.max);
  printf("Tamanho atual: %d\n", V.ultimo);
  if (BBvazio(V))
    return;
  for (i = 0; i < V.ultimo; i++)
    printf("%d ", V.v[i]);
  printf("\n");
  return;
}

/* void merge(elem *v, int ini, int centro, int fim) { */

/* 	elem *aux = (elem*) malloc(sizeof(elem) * (fim-ini+1)); */

/* 	int i = ini; */
/* 	int j = centro+1; */
/*  	int k = 0; */

/* 	while (i <= centro && j <= fim) { */

/* 		if (v[i] < v[j]) { */
/* 			aux[k] = v[i]; */
/* 			i++; */
/* 		} */

/* 		else { */
/* 			aux[k] = v[j]; */
/* 			j++; */
/* 		} */

/* 		k++; */
/* 	} */

/* 	while (i <= centro) { */
/* 		aux[k] = v[i]; */
/* 		i++; k++; */
/* 	} */

/* 	while (j <= fim) { */
/* 		aux[k] = v[j]; */
/* 		j++; k++; */
/* 	} */

/* 	for (i = ini, k = 0; i <= fim; i++, k++) */
/* 		v[i] = aux[k]; */

/* 	free(aux); */
/* } */

/* void mergesort (elem *v, int ini, int fim) { */
/* 	if (fim <= ini) return; */
/* 	int centro = (int) ((fim+ini)/2.0); */
/* 	mergesort(v, ini, centro); */
/* 	mergesort(v, centro+1, fim); */
/* 	merge(v, ini, centro, fim); */
/* } */
