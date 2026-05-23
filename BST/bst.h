#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no {
    int chave;
    struct no *dir;
    struct no *esq;
} No;

typedef No *BST;

BST bst_nova(void);
No *bst_no(int n);

BST bst_inserir(BST raiz,int chave);
BST bst_remover(BST raiz,int chave);
No *bst_buscar(BST raiz,int chave);

No *bst_sucessor(BST raiz,int chave);    //revisar
No *bst_antecessor(BST raiz,int chave);   //revisar

No *bst_minimo(BST raiz);
No *bst_maximo(BST raiz);

void bst_em_ordem(BST raiz);
void bst_pre_ordem(BST raiz);
void bst_pos_ordem(BST raiz);

void bst_free(BST raiz);

//exer5
int bst_verificar_aux(BST raiz, int min, int max);
int bst_verificar(BST raiz);

//exer6
int bst_iguais(BST raiz1, BST raiz2);

//Eexer7
BST bst_free_folhas(BST raiz);

//exer8
BST ac(BST raiz, int x,int y);

//exer9
BST somaFilhos(BST raiz);

//exer10
int distanciaAux(BST raiz,int x, int passos);
int distancia(BST raiz, int x, int y);

//exer11
void pares(BST raiz, BST raizOriginal, int k);



#endif