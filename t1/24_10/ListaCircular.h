#ifndef _LISTA_CIRCULAR_H_
#define _LISTA_CIRCULAR_H_

typedef struct Brinquedo{
	char modelo[15];
	int nSerie;
	struct Brinquedo *prox;
}Brinquedo;

typedef struct ListaDetectada{
	Brinquedo *inicio;
	Brinquedo *fim;
}Lista;

int ListaVazia(Lista *lista);
Lista* CriaLista(Lista *lista);
int InserirLista(Lista *lista, char *modelo, int nSerie);
Lista* RemoverLista(Lista *lista, int nSerie);

#endif