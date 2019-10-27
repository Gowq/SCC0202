#ifndef AVL_h
#define AVL_h

//CRIANDO OS NÓS NA ÁRVORE AVL
typedef struct No_ArvoreAVL
{
  int numero;
  int altura;
  struct No_ArvoreAVL *esquerda; 
  struct No_ArvoreAVL *direita;
}*no_arvore;

typedef struct{
  no_arvore raiz;
} AVL;

void AVLcria(AVL *a);
void AVLdestroi(AVL *a);
int AVLaltura(AVL a);
void AVLinsercao(AVL *a, int x);
int AVLbusca(AVL a, int x);
void AVLremocao(AVL *a, int x);
void AVLemOrdem(AVL a);
void AVLpreOrdem(AVL a);
void AVLpreOrdem(AVL a);
void AVLposOrdem(AVL a);
#endif
