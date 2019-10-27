#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

void AVLcria(AVL *a) {
	 a->raiz = NULL;
}

// DESALOCA A ARVORE INTEIRA
void liberar_ArvoreAVL(no_arvore no)
{
  if(no==NULL)
      //printf("Arvore vazia\n");
      return;
  liberar_ArvoreAVL(no->esquerda);
  liberar_ArvoreAVL(no->direita);
  free(no);
  return;
}

// Destrói a Árvore
void AVLdestroi(AVL *a){
  liberar_ArvoreAVL(a->raiz);
  return;
}

//Devolve a altura da árvore
int altura(no_arvore raiz)
{
  if( raiz == NULL )
    return 0;
  else
    return raiz->altura;
}

// Devolve a artura da árvore
int AVLaltura(AVL a){
  return altura(a.raiz);
}

//CALCULA A ALTURA
int CalculoAltura(no_arvore esquerda, no_arvore direita)
{
  int alturaEsquerda; 
  int alturaDireita;

  alturaEsquerda=altura(esquerda);
  alturaDireita=altura(direita);
    
  if(alturaEsquerda>alturaDireita)
    return alturaEsquerda+1;
  else
    return alturaDireita+1;
}


//"DEVOLVE" A MAIOR ALTURA DA ÁRVORE
int AlturaMaior(int a, int b)
{
  if (a>=b)
    return a;
  else 
    return b;
}


//FAZ ROTACAO DIREITA
no_arvore RotacaoDireita(no_arvore no)
{
  no_arvore aux;

  aux = no->esquerda;
  no->esquerda = aux->direita;
  aux->direita = no;
  no->altura = AlturaMaior(altura(no->esquerda),altura(no->direita))+1;
  aux->altura = AlturaMaior(altura(aux->esquerda),altura(no))+1;

  return aux; 
}

//FAZ ROTAÇÃO ESQUERDA
no_arvore Rotacao_Esquerda(no_arvore no)
{
  no_arvore aux;

  aux = no->direita;
  no->direita = aux->esquerda;
  aux->esquerda = no;
  no->altura = AlturaMaior(altura(no->esquerda),altura(no->direita))+1;
  aux->altura = AlturaMaior(altura(aux->direita),altura(no))+1;
    
  return aux; 
}

//FAZ ROTAÇÂO DUPLA esquerda-direita
no_arvore Rotacao_Esquerda_direita(no_arvore no)
{
  no->esquerda = Rotacao_Esquerda( no->esquerda );
  return RotacaoDireita(no);
}

//FAZ ROTAÇÂO DUPLA direita-esquerda
no_arvore Rotacao_Direita_Esquerda(no_arvore no)
{
  no->direita=RotacaoDireita(no->direita);
  return Rotacao_Esquerda(no);
}

// BALANCEIA A ARVORE AVL
void BalancearArvore(no_arvore *no)
{
  if ((*no)!=NULL)
    {
      if ( (altura((*no)->direita) - altura((*no)->esquerda))==-2)
	{
	  if ((altura((*no)->esquerda->direita) - altura((*no)->esquerda->esquerda))==-1)
	    *no=RotacaoDireita(*no);
	  else
	    *no=Rotacao_Esquerda_direita(*no);
	}
      else
	{
	  if ((altura((*no)->direita) - altura((*no)->esquerda))==2)
	    {
	      if((altura((*no)->direita->direita)-altura((*no)->direita->esquerda))==1)
		*no=Rotacao_Esquerda(*no);
	      else
		*no=Rotacao_Direita_Esquerda(*no);
	    }    
           
	  (*no)->altura=CalculoAltura((*no)->esquerda,(*no)->direita);   
	         
	  if((*no)->esquerda!=NULL)   
	    BalancearArvore(&((*no)->esquerda));
	  if((*no)->direita!=NULL)
	    BalancearArvore(&((*no)->direita));
	}   
    }
}

// insere 2
//Insere um elemento na Árvore ou diz se já existe um elemento igual na árvore
void insere(no_arvore *no, int x)
{
  no_arvore aux=NULL;
	
  if (*no == NULL)
    {
      no_arvore aux=(struct No_ArvoreAVL*)malloc(sizeof(struct No_ArvoreAVL));
      if (aux==NULL)
        {
	  //printf("NAO É POSSÍVEL ALOCAR MEMÓRIA\n"); 
        }
      else
        { 
	  *no = aux;	      
	  (*no)->numero=x;
	  (*no)->esquerda = NULL;
	  (*no)->direita = NULL;
	  (*no)->altura=CalculoAltura((*no)->esquerda,(*no)->direita);  //ESSA É A LINHA QUE ESTAVA FALTANDO NO CÓDIGO!!
	}
		
    }
  else 
    {
      if (x < (*no)->numero)
	{
	  insere(&((*no)->esquerda), x);
	  BalancearArvore(no);
	}
      else
	{
	  if (x > (*no)->numero)
	    {
	      insere(&((*no)->direita), x);
	      (*no)->altura=CalculoAltura((*no)->esquerda,(*no)->direita);
	      BalancearArvore(no);	
	    }	
	  if(x == (*no)->numero)
	    {
	      //printf("Chave existente\n");
	    }	
            
	}
    }     
  liberar_ArvoreAVL(aux);
}

// Insere elemento na árvore assumindo que sempre haverá memória para tal
void AVLinsercao(AVL *a, int x){
  insere (&a->raiz, x);
  return;
}

/* BUSCA ELEMENTO NA ARVORE */
int busca(no_arvore no,int x)
{
  int res=-1;
	
  int cont=0;
  if(no==NULL)
    {
      cont=0;
      res=0;
      return(res);
       
    }
  if(x==no->numero)
    {
      //printf("ELEMENTO ENCONTRADO!");
      cont=0;
      res=1;
      return(res);
       
    }
  if(x<no->numero)
    {
      cont++;
      return(busca(no->esquerda,x));
    }
  if(x>no->numero)
    {
      cont++;
      return(busca(no->direita,x));
    }
     
  return (res);     
}

// Realiza a busca do elemento x na árvore AVL
int AVLbusca(AVL a, int x){
  return busca(a.raiz, x);
}

// RETORNA MAIOR
no_arvore retorna_maior(no_arvore *no) {
  no_arvore aux;
  aux = *no;

  if (aux->direita==NULL)
    {
      *no=(*no)->esquerda;
      return (aux);
    }
  else
    return (retorna_maior(&((*no)->direita)));
}

// roda sub-arvore direita tendo raiz em y 
no_arvore roda_direita(no_arvore y) 
{
  no_arvore x = y->esquerda;
  no_arvore T2 = x->direita;

  /* efetua rotacao */
  x->direita = y;
  y->esquerda = T2;

  /* atualiza alturas */
  y->altura = AlturaMaior(altura(y->esquerda), altura(y->direita)) + 1;
  x->altura = AlturaMaior(altura(x->esquerda), altura(x->direita)) + 1;

  /* retorna novo no' */
  return x;
}

// roda sub-arvore esquerda tendo raiz em x
no_arvore roda_esquerda(no_arvore x) 
{
  no_arvore y = x->direita;
  no_arvore T2 = y->esquerda;

  /* efetua rotacao */
  y->esquerda = x;
  x->direita = T2;

  /*  atualiza alturas */
  x->altura = AlturaMaior(altura(x->esquerda), altura(x->direita)) + 1;
  y->altura = AlturaMaior(altura(y->esquerda), altura(y->direita)) + 1;

  /* retorna novo no' */
  return y;
}

int calc_balanceamento(no_arvore N) 
{
  if (N == NULL)
    return 0;
  return altura(N->direita) - altura(N->esquerda);

}

// percorre a arvore para encontrar o filho mais a direita
// NO com dois filhos: obtem sucessor menor- DIREITO) 
no_arvore avl_no_valormax(no_arvore no) 
{
  no_arvore nodoC = no;

  while (nodoC->direita != NULL)
    {
      nodoC = nodoC->direita;
    }
  return nodoC;
}

// percorre a arvore para encontrar o filho mais esquerda
no_arvore avl_no_valormin(no_arvore no) 
{
  no_arvore nodoC = no;

  while (nodoC->esquerda != NULL)
    {
      nodoC = nodoC->esquerda;
    }
  return nodoC;
}

//EXCLUI E BALANCEIA A ÁRVORE 
no_arvore exclui(no_arvore no, int x){
  if (no == NULL)
    return no;
  if (x<no->numero)
    no->esquerda = exclui(no->esquerda, x);        
  else if (x>no->numero)
    no->direita = exclui(no->direita, x);
  else {  
    if ((no->esquerda == NULL) || (no->direita == NULL)) {
      no_arvore temp = no->esquerda ? no->esquerda : no->direita;
      if (temp == NULL) {
	temp = no;
	no = NULL;
      }
      else {
	no->numero = temp->numero;
	no->esquerda = temp->esquerda;
	no->direita = temp->direita;
	no->altura = temp->altura;
      }
      
      
      free(temp);
    }
    else {
      no_arvore temp = avl_no_valormin(no->direita);
      
      no->numero = temp->numero;
      
      no->direita = exclui(no->direita, temp->numero);
    }
  }
  if (no == NULL)
    return no;
  no->altura = AlturaMaior(altura(no->esquerda), altura(no->direita)) + 1;
  int balance = calc_balanceamento(no);
  if (balance > 1) {
    if (calc_balanceamento(no->direita) < 0) {
      no->direita = roda_direita(no->direita);
      return roda_esquerda(no);
    }
    else {
      return roda_esquerda(no);
    }
  }
  else if (balance < -1) {
    
    if (calc_balanceamento(no->esquerda) > 0) 
      {
	no->esquerda = roda_esquerda(no->esquerda);
	return roda_direita(no);
      } 
    else {
      return roda_direita(no);
    }
  }
  
  return no;
}

// Remove elemento da árvore AVL
void AVLremocao(AVL *a, int x){
  a->raiz = exclui(a->raiz, x);
  return;
}



/*********************************VISUALIZAÇÕES*******************************************/

// MOSTRA EM_ORDEM 
void em_ordem(no_arvore no)
{
  if(no==NULL)
    {
      //printf("Arvore vazia\n");
    }     
  else
    {
      if(no->esquerda!=NULL)
	em_ordem(no->esquerda);
			
      printf("%d ",no->numero);
  
      if(no->direita!=NULL)
	em_ordem(no->direita);
    }
}

void AVLemOrdem(AVL a){
  em_ordem(a.raiz);
  return;
}

// MOSTRA EM PRE_ORDEM
void pre_ordem(no_arvore no)
{
  if(no==NULL)
    {
      //printf("Arvore vazia\n");
    }     
  else
    {	
      printf("%d ",no->numero); 
      if(no->esquerda!=NULL)
	pre_ordem(no->esquerda);
      if(no->direita!=NULL)
	pre_ordem(no->direita);
    }
}

void AVLpreOrdem(AVL a){
  pre_ordem(a.raiz);
  return;
}

// MOSTRA EM POS_ORDEM 
void pos_ordem(no_arvore no)
{
  
  if(no==NULL)
    {
      //printf("Arvore vazia\n");
    }     
  else
    {
      if(no->esquerda!=NULL)
	pos_ordem(no->esquerda);
      if(no->direita!=NULL)
	pos_ordem(no->direita);
      printf("%d ",no->numero);    
    }

}

void AVLposOrdem(AVL a){
  pos_ordem(a.raiz);
  return;
}

//Encontrando a altura da Arvore em nível - para imprimir em largura
int alturaemnivel(no_arvore no)
{
  int Ealtura;
  int Daltura;
	
  if (no==NULL)
    return 0;
  else
    {
      Ealtura = altura((no)->esquerda);
      Daltura = altura((no)->direita);
  
      if (Ealtura > Daltura)
	{
	  return(Ealtura+1);
	}   
      else
	{
	  return(Daltura+1);
	}
    }
}


// MOSTRAR EM LARGURA
//Imprimindo os nós no nível
void mostraremaltura(no_arvore no, int nivel)
{
  if(no == NULL)
    {
      return;
    }    
  if(nivel == 1)
    {
      printf("%d ", no->numero);
    }
  else 
    {
      if (nivel > 1)
	{ 
	  mostraremaltura(no->esquerda, nivel-1);
	  mostraremaltura(no->direita, nivel-1);
	}
    }
}

//IMPRIME EM LARGURA
void ImprimirLargura(no_arvore no)
{
  int A;
  int i;
  A = alturaemnivel(no);
    
  for(i=1; i<=A; i++)
    mostraremaltura(no, i);
		   
}    
