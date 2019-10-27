#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Tempos.h"
#include "BBtempos.h"
#include "LOtempos.h"
#include "LOStempos.h"
#include "ABBtempos.h"
#include "AVLtempos.h"
#include "LFREQtempos.h"
#include "pot10.h" // potências de 10 (10^x)
void exibe (NEstrut* EDD, int ord) {
	
  char strORD[3][12]; //Strings que guardam os nomes das ordens da estrutura
  strcpy(strORD[0], "crescente");
  strcpy(strORD[1], "decrescente");
  strcpy(strORD[2], "aleatoria");
  
  char strOP[3][9]; //Strings que guardam os nomes das operações em cada estrutura
  strcpy(strOP[0], "insercao");
  strcpy(strOP[1], "remocao");
  strcpy(strOP[2], "busca");
  
  char strEDD[6][6]; //Strings que guardam os nomes das estruturas
  strcpy(strEDD[0], "BB");
  strcpy(strEDD[1], "LO");
  strcpy(strEDD[2], "LOS");
  strcpy(strEDD[3], "ABB");
  strcpy(strEDD[4], "AVL");
  strcpy(strEDD[5], "LFREQ");
  
  int id = 3 * ord + 1;
  
  //NEstrut->Ntempos->Tempos
  //Ntempos est[6]->Tempos vet_esc[4]->double insercao, busca, remocao
  
	for (int op = 0; op < 3; op++) { //Iteração das operações
      printf("-\n");
      printf("Tabela %d: Tempo de %s %s\n", id++, strOP[op], strORD[ord]);
      printf("\t n=100\t n=1.000\t n=10.000\t n=100.000\n");
		for (int ed = 0; ed < 5; ed++) { //Iteração das estruturas de dados
	
			if (op == 0)
				printf("%s \t %e \t  %e \t %e \t %e\n", strEDD[ed], EDD->est[ed].vet_esc[0].insercao, EDD->est[ed].vet_esc[1].insercao, EDD->est[ed].vet_esc[2].insercao, EDD->est[ed].vet_esc[3].insercao);
			else if (op == 1)
				printf("%s \t %e \t  %e \t %e \t %e\n", strEDD[ed], EDD->est[ed].vet_esc[0].remocao, EDD->est[ed].vet_esc[1].remocao, EDD->est[ed].vet_esc[2].remocao, EDD->est[ed].vet_esc[3].remocao);
			else if (op == 2) //Redundancia proposital
				printf("%s \t %e \t  %e \t %e \t %e\n", strEDD[ed], EDD->est[ed].vet_esc[0].busca, EDD->est[ed].vet_esc[1].busca, EDD->est[ed].vet_esc[2].busca, EDD->est[ed].vet_esc[3].busca);	
		
		}
	}
}

void det_op (Ntempos* vetMod, int *vet[4], int flag) {
  switch (flag) {
  case 0: //BB
    //vetMod[0] = BBtempos(vet);
    break;
  case 1: //LO
    vetMod[1] = LOtempos(vet);
    break;
  case 2: //LOS
    vetMod[2] = LOStempos(vet);
    break;
  case 3: //ABB
    vetMod[3] = ABBtempos(vet);
    break;
  case 4: //AVL
    vetMod[4] = AVLtempos(vet);
    break;
  case 5: //LFREQ
    vetMod[5] = LFREQtempos(vet);
    break;   
  }
}

void embaralha_vet(int *vet, int tam) {  
  for (int i = 0; i < tam - 1; i++) {
    int pos = i + rand() / (RAND_MAX / (tam - i) + 1);
    int aux = vet[pos];
    vet[pos] = vet[i];
    vet[i] = aux;
  }
}

int* gera_vet(int tam, int flag) {
  int* vet = malloc(tam * sizeof(int));
  int x = 0;
  switch (flag) {
  case 0: //Ordem crescente
    for (int i = 0; i < tam; i++)
      vet[i] = i;
    break;  
  case 1: //Ordem decrescente
    for (int i = tam-1; i >= 0; i--)
      vet[x++] = i;
    break;
  case 2: //Ordem aleatória
    for (int i = 0; i < tam; i++)
      vet[i] = i;
    embaralha_vet(vet, tam);
    break;
  }
  return vet;
}

int main () {
  NEstrut EDD;
  int tam = 10;
  int *vetCr, *pVetCr[4]; //pVet -> ponteiro de vetor que guardam os 4 vetores -> cem, mil, dez mil e cem mil
  int *vetDr, *pVetDr[4]; //pVet -> ponteiro de vetor que guardam os 4 vetores -> cem, mil, dez mil e cem mil
  int *vetAl, *pVetAl[4]; //pVet -> ponteiro de vetor que guardam os 4 vetores -> cem, mil, dez mil e cem mil
  
  for (int y = 0; y < 4 ; y++) { //ITERAÇÃO DO TAMANHO DO VETOR
	
    tam = pot10(2 + y); //y = 0 tam = 100, y = 1 tam = 1000, y = 2 tam = 10000, y = 3 tam 100000
	
    vetCr = gera_vet(tam, 0);
    vetDr = gera_vet(tam, 1);
    vetAl = gera_vet(tam, 2);
    pVetCr[y] = vetCr;
    pVetDr[y] = vetDr;
    pVetAl[y] = vetAl;
  }
  
	det_op(&EDD.est[0], pVetCr, 0);	
	printf("det_op(&EDD.est[0], pVetCr, 0)\n");	
    det_op(&EDD.est[1], pVetCr, 1); 
    printf("det_op(&EDD.est[1], pVetCr, 1)\n"); 
    det_op(&EDD.est[2], pVetCr, 2); 
	printf("det_op(&EDD.est[2], pVetCr, 2)\n"); 
    det_op(&EDD.est[3], pVetCr, 3); 
	printf("det_op(&EDD.est[3], pVetCr, 3)\n");
	det_op(&EDD.est[4], pVetCr, 4); 
	printf("det_op(&EDD.est[4], pVetCr, 4)\n");
    det_op(&EDD.est[5], pVetCr, 5);
	printf("det_op(&EDD.est[5], pVetCr, 5)\n");
	exibe(&EDD, 0);	
	
	det_op(&EDD.est[0], pVetDr, 0); 
	printf("det_op(&EDD.est[0], pVetDr, 0)\n"); 
    det_op(&EDD.est[1], pVetDr, 1);
	printf("det_op(&EDD.est[1], pVetDr, 1)\n"); 
    det_op(&EDD.est[2], pVetDr, 2);
	printf("det_op(&EDD.est[2], pVetDr, 2)\n"); 
    det_op(&EDD.est[3], pVetDr, 3); 
	printf("det_op(&EDD.est[3], pVetDr, 3)\n");
	det_op(&EDD.est[4], pVetDr, 4);
	printf("det_op(&EDD.est[4], pVetDr, 4)\n");
    det_op(&EDD.est[5], pVetDr, 5);
	printf("det_op(&EDD.est[5], pVetDr, 5)\n");	
	exibe(&EDD, 1);	
		
	det_op(&EDD.est[0], pVetAl, 0); 
	printf("det_op(&EDD.est[0], pVetAl, 0)\n"); 
    det_op(&EDD.est[1], pVetAl, 1); 
	printf("det_op(&EDD.est[1], pVetAl, 1)\n"); 
    det_op(&EDD.est[2], pVetAl, 2); 
	printf("det_op(&EDD.est[2], pVetAl, 2)\n"); 
    det_op(&EDD.est[3], pVetAl, 3); 
	printf("det_op(&EDD.est[3], pVetAl, 3)\n");
	det_op(&EDD.est[4], pVetAl, 4); 
	printf("det_op(&EDD.est[4], pVetAl, 4)\n");
    det_op(&EDD.est[5], pVetAl, 5); 
	printf("det_op(&EDD.est[5], pVetAl, 5)\n");
	exibe(&EDD, 2);
		
}
