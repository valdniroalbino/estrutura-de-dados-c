#include "bst.h"

BST bst_nova(void){
    return NULL;
}

No *bst_no(int chave){
    No *novo = malloc(sizeof(No));

    if(novo == NULL){
        printf("ero de alocacao");
        return NULL;
    }

    novo->chave = chave;
    novo->dir = NULL;
    novo->esq = NULL;
    
    return novo;
}

BST bst_inserir(BST raiz,int chave){
    if(raiz == NULL){
        return bst_no(chave);
    }

    if(chave < raiz->chave){
        raiz->esq = bst_inserir(raiz->esq,chave);
    }else if(chave > raiz->chave){
        raiz->dir = bst_inserir(raiz->dir,chave);
    }else{
        printf("chave %d ja existe",chave);
    }

    return raiz;
}

No *bst_buscar(BST raiz,int chave){
    if( raiz == NULL) return NULL;

    if (chave == raiz->chave) return raiz;

    if(chave < raiz->chave){
        return bst_buscar(raiz->esq,chave);
    }else{
        return bst_buscar(raiz->dir,chave);
    }
}

No *bst_maximo(BST raiz){
    if(raiz == NULL ) return NULL;
    if(raiz->dir != NULL){
        return bst_maximo(raiz->dir);
    }else{
        return raiz;
    }
}

No *bst_minimo(BST raiz){
    if(raiz == NULL ) return NULL;
    if(raiz->esq != NULL){
        return bst_minimo(raiz->esq);
    }else{
        return raiz;
    }
}

BST bst_remover(BST raiz, int chave) {
    if (raiz == NULL) return NULL;

    if (chave < raiz->chave) {
        raiz->esq =  bst_remover(raiz->esq,chave);
    } else if (chave > raiz->chave) {
        raiz->dir = bst_remover(raiz->dir,chave);
    } else {
        
        if(raiz->esq == NULL){
            No *tpm = raiz->dir;
            free(raiz);
            return tpm;
        }else if(raiz->dir == NULL){
            No *tpm = raiz->esq;
            free(raiz);
            return tpm;
        }else{
            No *suc = bst_minimo(raiz->dir);
            raiz->chave = suc -> chave;
            raiz->dir = bst_remover(raiz->dir, suc->chave);
        }
    }

    return raiz;
}

No *bst_sucessor(BST raiz, int chave) {
    No *atual    = raiz;
    No *sucessor = NULL;

    while (atual != NULL) {
        if (chave < atual->chave) {
            sucessor = atual;        /* guarda candidato */
            atual    = atual->esq;   /* desce à esquerda */

        } else if (chave > atual->chave) {
            atual = atual->dir;      /* desce à direita */

        } else {
            /* encontrou o nó */
            if (atual->dir != NULL) {
                return bst_minimo(atual->dir);  /* tem filho direito */
            }
            break;  /* não tem filho direito → sai, devolve candidato */
        }
    }

    return sucessor;
}

No *bst_antecessor(BST raiz, int chave) {
    No *atual    = raiz;
    No *antecessor = NULL;

    while (atual != NULL) {
        if (chave > atual->chave) {
            antecessor = atual;        /* guarda candidato */
            atual    = atual->dir;   /* desce à direita */

        } else if (chave < atual->chave) {
            atual = atual->esq;      /* desce à esquerda */

        } else {
            /* encontrou o nó */
            if (atual->esq != NULL) {
                return bst_maximo(atual->esq);  /* tem filho esquero */
            }
            break;  /* não tem filho direito → sai, devolve candidato */
        }
    }

    return antecessor;
}

void bst_pre_ordem(BST raiz){
    if(raiz != NULL){
        printf(" %d ",raiz->chave);
        bst_pre_ordem(raiz->esq);
        bst_pre_ordem(raiz->dir);
    }
}

void bst_em_ordem(BST raiz){
    if(raiz != NULL){
        bst_em_ordem(raiz->esq);
        printf(" %d ",raiz->chave);
        bst_em_ordem(raiz->dir);
    }
}

void bst_pos_ordem(BST raiz){
    if(raiz != NULL){
        bst_pos_ordem(raiz->esq);
        bst_pos_ordem(raiz->dir);
        printf(" %d ",raiz->chave);
    }
}

void bst_free(BST raiz){
    if(raiz != NULL){
        bst_free(raiz->esq);
        bst_free(raiz->dir);
        free(raiz);
    }
}

int bst_verificar_aux(BST raiz, int min, int max){
    if(raiz == NULL) return 1;
    if(raiz->chave <= min || raiz->chave >= max) return 0;
    
    return bst_verificar_aux(raiz->esq,min,raiz->chave) && bst_verificar_aux(raiz->dir,raiz->chave,max);
}

int bst_verificar(BST raiz)
{
    return bst_verificar_aux(raiz,INT_MIN, INT_MAX);
}

int bst_iguais(BST raiz1, BST raiz2){
    if(raiz1 == NULL && raiz2 == NULL) return 1;

    if(raiz1 == NULL || raiz2 == NULL) return 0;

    if(raiz1->chave == raiz2->chave){
        return bst_iguais(raiz1->esq, raiz2->esq) && bst_iguais(raiz1->dir, raiz2->dir);
    }

    return 0;
}

BST bst_free_folhas(BST raiz){
    if(raiz == NULL ) return NULL;

    if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        return NULL;

    }
    raiz->esq = bst_free_folhas(raiz->esq);
    raiz->dir = bst_free_folhas(raiz->dir);

    return raiz;
}