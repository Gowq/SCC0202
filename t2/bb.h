#ifndef   bb_h
    #define bb_h

    typedef int elem;
/* Estrutura para armazenamento de vetor alocado dinâmicamente, mas acessado de forma sequêncial.
   A idéia é que, a medida que os elementos são inseridos, o vetor "aumente" de tamanho até chegar a tam
 */
typedef struct{
  elem *v;
  int max; // Tamanho a ser alocado para o vetor
  int ultimo; // Tamanho corrente do vetor
} Vetor;

int bb(Vetor vet, elem key);
int BBcria(Vetor *vet, int tam);
int BBvazio(Vetor vet);
int BBinsercao_ordenada(Vetor *vet, elem x);
int BBremocao(Vetor *vetor, elem key);
void BBdestroi(Vetor *vet);
void BBimprime(Vetor V);
/* void merge(elem *v, int ini, int centro, int fim); */
/* void mergesort (elem *v, int ini, int fim); */

#endif
