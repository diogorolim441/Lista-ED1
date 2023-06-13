#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"CBLoL.h"

ArvAVL* cria_AVL(){
    ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int alt_No(struct No* no){
    if(no == NULL)
       return -1;
    else
       return no->alt;
}

int fatorBalanceamento_No(struct No* no){
    return labs(alt_No(no->esq) - alt_No(no->dir));
}

struct No* minimo(struct No* no){
    struct No* atual = no;
    while (atual->esq != NULL){
        atual = atual->esq;
    }
    return atual;
}

int maior(int x, int y){
    if(x > y)
       return x;
    else
       return y;
}

void RotacaoLL(ArvAVL *raiz){
    struct No *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(ArvAVL *raiz){
    struct No *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_No((*raiz)->esq),alt_No((*raiz)->dir)) + 1;
    no->alt = maior(alt_No(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void RotacaoLR(ArvAVL* A){
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL* A){
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, char nome[], int pontos){
    int res;
    if(*raiz == NULL){
        struct No* novo;
        novo = (struct No*)malloc(sizeof(struct No));
        if(novo == NULL){
           return 0;
        }
    novo->pontos = pontos;
    strcpy(novo->nome, nome);
    novo->alt = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    *raiz = novo;
    return 1;
    }

    struct No *atual = *raiz;
    if(pontos < atual->pontos){
        if((res = (insere_ArvAVL(&(atual->esq), nome, pontos))) == 1){
            if(fatorBalanceamento_No(atual) >= 2){
                if(pontos < (*raiz)->esq->pontos)
                   RotacaoLL(raiz);
                else
                   RotacaoLR(raiz);
            }

        }
    }else{
        if(pontos > atual->pontos){
            if((res = insere_ArvAVL(&(atual->dir), nome, pontos)) == 1){
                if(fatorBalanceamento_No(atual) >= 2){
                   if((*raiz)->dir->pontos < pontos)
                       RotacaoRR(raiz);
                    else
                       RotacaoRL(raiz);

               }
            }

       }else
           return 0;
    }
    atual->alt = maior(alt_No(atual->esq), alt_No(atual->dir)) + 1;
    return res;
}

void removeNo(ArvAVL *raiz, char nome[]){
    if(*raiz == NULL){
        printf("Árvore vazia\n");
        return;
    }

    if(strcmp((*raiz)->nome, nome) == 0){
        if(((*raiz)->esq == NULL) || ((*raiz)->dir == NULL)){
            struct No *temp = *raiz;
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(temp);
        }else{
            struct No *temp = minimo((*raiz)->dir);
            strcpy((*raiz)->nome, temp->nome);
            (*raiz)->pontos = temp->pontos;
            removeNo(&(*raiz)->dir, temp->nome);
        }
    }

    if(*raiz != NULL){
        (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
        int balanceamento = fatorBalanceamento_No(*raiz);
        
        if(balanceamento >= 2){
            if(fatorBalanceamento_No((*raiz)->esq) >= 0){
                RotacaoLL(raiz);
            }else{
                RotacaoLR(raiz);
            }
        }else if(balanceamento <= -2){
            if(fatorBalanceamento_No((*raiz)->dir) <= 0){
                RotacaoRR(raiz);
            }else{
                RotacaoRL(raiz);
            }
        }
    }
}

void alteraValor(ArvAVL* raiz, char nome[], int novoPonto){
    if(raiz == NULL){
        printf("Arvore vazia\n");
        return;
    }
    removeNo(raiz, nome);
    insere_ArvAVL(raiz, nome, novoPonto);
}

void classificao_Arv(ArvAVL* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        classificao_Arv(&((*raiz)->dir));
        printf("Time: %s\n", (*raiz)->nome);
        printf("Pontuacao: %d\n", (*raiz)->pontos);
        printf("----------------------\n");
        classificao_Arv(&((*raiz)->esq));
    }
}

int main(){
    ArvAVL* raiz = cria_AVL();
    insere_ArvAVL(raiz, "Pain Gaming", 17);
    insere_ArvAVL(raiz, "LOUD", 20);
    insere_ArvAVL(raiz, "Fluxo", 15);
    insere_ArvAVL(raiz, "INTZ", 6);
    insere_ArvAVL(raiz, "Red Kalunga", 35);
    insere_ArvAVL(raiz, "Vivo KeyD", 38);
    insere_ArvAVL(raiz, "Los Grandes", 11);
    insere_ArvAVL(raiz, "KaBuM", 25);
    insere_ArvAVL(raiz, "Furia", 9);
    classificao_Arv(raiz);
    printf("\n\n\n");
    alteraValor(raiz, "KaBuM", 39);
    classificao_Arv(raiz);
    return 0;
}