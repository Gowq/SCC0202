#ifndef TEMPOS_H
	#define TEMPOS_H

	typedef struct tempos{
	  double insercao, busca, remocao;
	} Tempos;

	typedef struct ntempos{
	  Tempos vet_esc[4]; // 0 -> cem, 1 -> mil, 2 -> dez mil, 3 -> cem mil
	} Ntempos;

	typedef struct estrutura{
	  Ntempos est[6]; // 0 -> BB, 1 -> LO, 2 -> LOS, 3 -> ABB, 4 -> AVL e 5-> LFREQ  
	} NEstrut;
	
#endif
