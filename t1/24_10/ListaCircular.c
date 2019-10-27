#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaCircular.h"

Lista* CriaLista(Lista *lista){
	Lista *nova = NULL;

	nova = (Lista*) malloc(sizeof(Lista));

	nova->inicio = NULL;
	nova->fim = NULL;

	return nova;
}

int ListaVazia(Lista *lista){
	if (lista->inicio == lista->fim && lista->inicio == NULL) return 1;
	return 0;
}

int InserirLista(Lista *lista, char *modelo, int nSerie){
	Brinquedo *novo_brinquedo, *atual;
	novo_brinquedo = malloc(sizeof(Brinquedo));
	if (novo_brinquedo == NULL) return 0;
	if (novo_brinquedo->modelo == NULL) return 0;

	if (ListaVazia(lista)){		
		strcpy (novo_brinquedo->modelo, modelo);
		novo_brinquedo->nSerie = nSerie;

		novo_brinquedo->prox = novo_brinquedo;
		lista->inicio = novo_brinquedo;
		lista->fim = novo_brinquedo;
		
		return 1;
	} else {

		atual = lista->fim;

		strcpy (novo_brinquedo->modelo, modelo);
		novo_brinquedo->nSerie = nSerie;

		if(atual != lista->fim) return 0;

		novo_brinquedo->prox = atual->prox;
		atual->prox = novo_brinquedo;
		lista->fim = novo_brinquedo;
		return 1;
	}
}

Lista* RemoverLista(Lista *lista, int nSerie){    
	Brinquedo *p, *q;
   
   p = lista->inicio;
   q = lista->inicio->prox;

   if (lista->inicio == lista->fim){
   	lista->inicio = NULL;
   	return lista;
   }

   if(p->nSerie == nSerie){
   lista->inicio = q;
   lista->fim->prox = q;
   free(p);
   return lista;
   }

   while(q != lista->fim && q->nSerie != nSerie){
   	p = q;
    q = q->prox;
   }
   p->prox = q->prox;
   free(q);
   return lista;
}