#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCircular.h"
#include "Pilha.h"
#include "Lista.h"

int main(int argc, char const *argv[]){
	/*
	p = caixa
	k = intervalo
	n = total brinquedos
	*/
	int p, k, n, cheio;
	Brinquedo b, *a, *c;

	n = atoi(argv[1]);
	k = atoi(argv[2]);
	p = atoi(argv[3]);

	Lista *listaCircular;
	listaCircular = CriaLista(listaCircular);

	for(int i = 0; i < 2*n; i += 2){
		b.nSerie = atoi(argv[i+4]);
		strcpy(b.modelo, argv[i+5]);
		InserirLista(listaCircular, b.modelo, b.nSerie);
	}

	Pilha *pilha;
	pilha = Cria(p);

	Fila *fila;
	fila = CriaFila();

	a = listaCircular->inicio;
	int i = 0;
	int ra = p;
	while (!ListaVazia(listaCircular)){
		if(i > n){
			a = listaCircular->inicio;
			i = 0;
			k--;
			p--;
			if (k == 0) break;
		}
		if (i%k == 0){
			cheio = Push(pilha, p, a);
			if(cheio == 0){
				InserirFila(fila, pilha);
				pilha = Cria(p);
				cheio = Push(pilha, p, a);

			}
			//printf("%d %s\n", a->nSerie, a->modelo);
			c = a->prox;
			listaCircular = RemoverLista(listaCircular, a->nSerie);
			a = c;
			n--;
		}
		else a = a->prox;
		i++;
	}

	InserirFila(fila, pilha);

	//printf("Tam fila:%d\n", fila->n);
	FilaCaixa *fc;
	Brinquedo *br;
	int caixa = 0, tam;
	while(FilaVazia(fila) != 1){
		printf("caixa %d:", caixa);
		fc = RetornaCaixa(fila);
		br = Topo(fc->pilha);
		printf("brinquedo: %d - %s", br->nSerie, br->modelo);
		tam = tamanho(fc->pilha);
		printf(" - quantidade %d\n", tam);
		RemoveFila(fila);
		caixa++;

	}

	return 0;
}