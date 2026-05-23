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

BST ac(BST raiz, int x, int y){
    if(raiz == NULL) return NULL;

    if(raiz->chave == x || raiz->chave == y) return raiz;

    BST esq = ac(raiz->esq,x,y);
    BST dir = ac(raiz->dir,x,y);

    if(esq != NULL && dir != NULL) return raiz;

    return esq != NULL ? esq : dir ;
}

BST somaFilhos(BST raiz){
    if(raiz == NULL ) return;
    if(raiz->esq == NULL && raiz->dir == NULL) return;

    somaFilho(raiz->esq);
    somaFilho(raiz->dir);

    int valorEsq = (raiz->esq != NULL)? raiz->esq->chave: 0;
    int valorDir = (raiz->dir != NULL)? raiz->dir->chave: 0;
    
    raiz->chave = valorEsq + valorDir;

}

int distanciaAux(BST raiz,int x, int passos){
    if (raiz == NULL) return -1;

    if (raiz->chave == x) return passos;

    int esq = distanciaAux(raiz->esq,x,passos+1);
    if( esq != -1) return esq;

    return distanciaAux(raiz->dir, x, passos+1);
}

int distancia(BST raiz, int x, int y){
    BST ancestral = ac(raiz,x,y);

    int distP = distanciaAux(ancestral,x,0);
    int distQ = distanciaAux(ancestral,y,0);

    return distP + distQ;
}

void pares(BST raiz, BST raizOriginal, int k){
    if(raiz == NULL ) return;

    pares(raiz->esq, raizOriginal, k);

    int complemento = k - raiz->chave;

    if (complemento > raiz->chave && busca(raizOriginal, complemento))
        printf("(%d, %d)\n", raiz->chave, complemento);

    pares(raiz->dir, raizOriginal, k);
}

int altura(BST raiz){
    if(raiz == NULL) return -1;

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if(esq > dir ){
        return esq + 1;
    }else{
        return dir + 1;
    }
     
}

int isomorfas(BST r1, BST r2){
    if(r1 == NULL && r2 == NULL ) return 1;

    if(r1 == NULL || r2 == NULL ) return 0;

    return isomorfas(r1->esq, r2->esq) && isomorfas(r1->dir, r2->dir);
}

