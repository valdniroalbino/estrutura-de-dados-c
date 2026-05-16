#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    BST raiz = bst_nova();
    int opcao,chave;
    No *result = NULL;
    

    do{
        
        printf("##### MENU INTERATIVO BST #####\n");
        printf("1.insserir\n");
        printf("2.remover\n");
        printf("3.procurar\n");
        printf("4.imprimir em ordem\n");
        printf("5.sucessor\n");
        printf("6.antecessor\n");
        printf("7.sair\n");
        printf("opcao: \n");
        scanf("%d",&opcao);
        printf("-------------\n");

        switch(opcao){
            case 1:
                printf("chave: \n");
                scanf("%d",&chave);
                raiz = bst_inserir(raiz,chave);
                break;
            case 2:
                printf("chave: \n");
                scanf("%d",&chave);
                raiz = bst_remover(raiz,chave);
                break;
            case 3:
                printf("chave: \n");
                scanf("%d",&chave);
                result = bst_buscar(raiz,chave);
                if(result){
                    printf("chave encontrada!\n");
                }else{
                    printf("chave nao encontrada\n");
                }
                break;
            case 4:
                bst_em_ordem(raiz);
                break;
            case 5:
                printf("chave: \n");
                scanf("%d",&chave);
                result = bst_sucessor(raiz,chave);
                if(result){
                    printf("sucessor: %d \n",result->chave);
                }else{
                    printf("sucessor nao encontrado\n");
                }
                break;
            case 6:
                printf("chave: \n");
                scanf("%d",&chave);
                result = bst_antecessor(raiz,chave);
                if(result){
                    printf("antecessor: %d \n",result->chave);
                }else{
                    printf("antecessor nao encontrado\n");
                }
                break;
            case 7: 
                printf("saindo...\n");
                break;
            default:
                printf("opcao invalida. Saindo...\n");
        }
        printf("\n");
        printf("\n");
    }while(opcao != 7);

    bst_free(raiz);

    return 0;
    
}
