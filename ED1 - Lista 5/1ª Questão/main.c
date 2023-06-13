#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
       *raiz = NULL;
    }
    return raiz;
}

int somaNos(ArvBin* raiz, int *cont){
    if(raiz == NULL){
       return 0;
    }
    if(*raiz == NULL){
       return 0;
    }
    int soma_esq = somaNos(&((*raiz)->esq), cont);
    int soma_dir = somaNos(&((*raiz)->dir), cont);
    int total = soma_esq + soma_dir + (*raiz)->info;
    (*cont)++;

    return total;
}

//item a)
int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL){
        printf("Árvore vazia!\n");
        return 0;
    }
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        printf("Erro na criação do nó!\n");
        return 0;
    }
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
       *raiz = novo;
    }else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){
               atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor > ant->info){
           ant->dir = novo;
        }else{
           ant->esq = novo;
        }
    }
    return 1;
}

//item b)
void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        printf("Árvore vazia!\n");
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
        return;
    }
}

void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        printf("Árvore Vazia!\n");
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
        return;
    }
}

void posOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        printf("Árvore vazia!\n");
        return;
    }
    if(*raiz != NULL){
       posOrdem_ArvBin(&((*raiz)->esq));
       posOrdem_ArvBin(&((*raiz)->dir));
       printf("%d\n", (*raiz)->info);
       return;
    }
}

//item c)
int consulta_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL){
        printf("Arvore vazia!\n");
        return 0;
    }
    struct No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            printf("No encontrado: %d\n", atual->info);
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
           atual =  atual->esq;
        }
    }
    printf("No nao encontrado!\n");
    return 0;
}

//item d)
int maiormenorValor_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
       return -1;
    }
    if(*raiz == NULL){
       return -1;
    }
    struct No* atual = *raiz;
    while(atual->dir != NULL){
       atual = atual->dir;
    }
    printf("O maior valor eh %d\n", atual->info);
    atual = *raiz;
    while(atual->esq != NULL){
       atual = atual->esq;
    }
    printf("O menor valor eh %d\n", atual->info);
    return 1;
}

//item e)
int mediaArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
       return 0;
    }
    int cont = 0;
    int soma = somaNos(raiz, &cont);
    if(cont == 0)
       return 0;
    return soma/cont;
}

//item f)
int numeroNULLS(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 1;
    }
    int nulls_esq = numeroNULLS(&((*raiz)->esq));
    int nulls_dir = numeroNULLS(&((*raiz)->dir));
    return nulls_esq + nulls_dir;
}

//item g)
int somaChaveNos(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int soma_esq = somaChaveNos(&((*raiz)->esq));
    int soma_dir = somaChaveNos(&((*raiz)->dir));
    int soma_atual = (*raiz)->info;
    return soma_esq + soma_dir + soma_atual;
}

//item h)
int multiploTres(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int cont = 0;
    int mult_esq = multiploTres(&((*raiz)->esq));
    int mult_dir = multiploTres(&((*raiz)->dir));

    if((*raiz)->info % 3 == 0){
        cont = 1;
    }
    return mult_esq + mult_dir + cont;
}

//item i)
int totalNo(ArvBin* raiz){
    if(raiz == NULL){
        printf("Árvore Vazia!\n");
        return 0;
    }
    if(*raiz == NULL){
        printf("Árvore Vazia!\n");
        return 0;
    }
    int nos_esq = totalNo(&((*raiz)->esq));
    int nos_dir = totalNo(&((*raiz)->dir));
    printf("Número total de nós: ");
    return(nos_esq + nos_dir + 1);
}

//item j)
int numeroFolhas(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int folhas_esq = numeroFolhas(&((*raiz)->esq));
    int folhas_dir = numeroFolhas(&((*raiz)->dir));

    if((*raiz)->dir == NULL && (*raiz)->esq == NULL){
        return 1;
    }
    return folhas_esq + folhas_dir;
}

//item k)
int altura_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        printf("Árvore vazia!\n");
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int altura_esq = altura_ArvBin(&((*raiz)->esq));
    int altura_dir = altura_ArvBin(&((*raiz)->dir));
    if (altura_esq > altura_dir){
        return (altura_esq + 1);
    }else{
        return (altura_dir + 1);
    }
}

//item l)
int verifica_ArvBin(ArvBin* raiz){
    if(raiz == NULL || *raiz == NULL){
       return 1;
    }
    if(((*raiz)->esq == NULL && (*raiz)->dir != NULL) || ((*raiz)->esq != NULL && (*raiz)->dir == NULL)){
        return 0;
    }
    return verifica_ArvBin((*raiz)->esq) && verifica_ArvBin((*raiz)->dir);
}

int main(){
    return 0;
}