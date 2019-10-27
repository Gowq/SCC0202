#include "filaPilhaT1.c"
#include "pilhaT1.c"
#include "listaCircularT1.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//k -> salto, n -> quantidade de brinquedos, p -> capacidade da caixa
	if (argc < 4)
		printf("Expressao errada\n");

	//Adiciona os argumentos k, n e p nas variáveis
	int n = atoi(argv[1]), k = atoi(argv[2]), p = atoi(argv[3]), nroCaixa = 0;
	Lista l;
	Fila f;
	Pilha *pi;
	Brinquedo b[n], auxV[n];
	int nroBrinq[n];

	if (n % p == 0)
		pi = malloc((n/p) * sizeof(Pilha));
	else
		pi = malloc((n/p+1) * sizeof(Pilha));

	cria_lista(&l);
	cria_pilha(pi);
	cria_fila(&f);

	//Atribui aos brinquedos os valores de argc e adiciona à lista circ.
	int ind = 0;
	for (int x = 4; x < argc; x += 2) {
		// 0 4 5 | 2 6 7| 4 8 9|
		b[ind].id = atoi(argv[x]);
		printf("ID: %d\n", b[ind].id);

		strcpy(b[ind].modelo, argv[x+1]);
		printf("MODELO: %s\n", b[ind].modelo);

		insere_na_lista(&l, b[ind]);
		printf("ELEMENTOS DA LISTA: %d\n", l.n);

		ind++;
	}

	printf("-------------------\n");
	int emp = 0;

	//Retira da lista circular e insere na pilha

	while(k != 0) {
		printf("\nL.n: %d\n", l.n);
		printf("K: %d\n", k);

		for (int x = 0; x < l.n; x += k) {
			printf("X: %d\n", x);
			printf("EMP: %d\n", emp);

			Brinquedo aux = remove_da_lista(&l, x);
			printf("AUX: %s\n\n", aux.modelo);
			push(&pi[nroCaixa], aux);
			emp++;

			if (emp == p) {
				nroCaixa++;
				emp = 0;
				printf("VALIDOU \n");
			}

		}

		k--;
	}

	printf("\nNROCAIXA: %d\n", nroCaixa);

	if(isEmpty(*pi))
		printf("Tá vazio\n");
	else
		printf("Não tá vazio\n");

	//Insere a pilha na fila
	for(int x = 0; x < nroCaixa; x++)
		insere_na_fila(&f, pi[x]);

	//Retira a pilha da fila
	for(int x = 0; x < nroCaixa; x++) {
		 remove_fila(&f, &pi[x]);

		int y = 0;
		while(pop(&pi[x], &auxV[y])) {
			y++;
			nroBrinq[auxV[x].id]++;
		}

		printf("caixa %d: brinquedo <%d,%s> - quantidade %d\n", x, auxV[x].id, auxV[x].modelo, nroBrinq[auxV[x].id]);
	}

	return 0;
}
