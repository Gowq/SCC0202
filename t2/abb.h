#ifndef abb
	#define abb

	typedef struct abbno {
		int info;
		struct abbno *esq, *dir;
	}ABBNo;

	typedef struct {
		ABBNo *raiz;
	}ABB;

	void ABBcria(ABB *a);
	void ABBdestroi(ABB *a);
	int ABBvazia(ABB a);
	void ABBimprime(ABB a);
	int ABBaltura(ABB a);
	void ABBpreOrdem(ABB a);
	void ABBemOrdem(ABB a);
	void ABBposOrdem(ABB a);
	int ABBbusca(ABB a, int x);
	int ABBinsercao(ABB *a, int x);
	int ABBremocao(ABB *a, int x);

#endif
