#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Candidato.h"

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

int busca_Votos(ArvAVL* raiz, int id){
    if (raiz == NULL || *raiz == NULL)
        return 0;

    struct No* atual = *raiz;

    while (atual != NULL){
        int votosDir = busca_Votos(&(atual->dir), id);
        if (votosDir != 0){
            return votosDir;
        }

        if (atual->candidato.id == id){
            return atual->candidato.votos;
        }

        int votosEsq = busca_Votos(&(atual->esq), id);
        if (votosEsq != 0){
            return votosEsq;
        }

        break;
    }
    return 0;
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

int insere_ArvAVL(ArvAVL *raiz, int id, int votos){
    int res;
    if(*raiz == NULL){
        struct No* novo;
        novo = (struct No*)malloc(sizeof(struct No));
        if(novo == NULL){
           return 0;
        }
    novo->candidato.votos = votos;
    novo->candidato.id = id;
    novo->alt = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    *raiz = novo;
    return 1;
    }

    struct No *atual = *raiz;
    if(votos < atual->candidato.votos){
        if((res = (insere_ArvAVL(&(atual->esq), id, votos))) == 1){
            if(fatorBalanceamento_No(atual) >= 2){
                if(votos < (*raiz)->esq->candidato.votos){
                   RotacaoLL(raiz);
                }else{
                   RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(votos > atual->candidato.votos){
            if((res = insere_ArvAVL(&(atual->dir), id, votos)) == 1){
                if(fatorBalanceamento_No(atual) >= 2){
                   if((*raiz)->dir->candidato.votos < votos){
                       RotacaoRR(raiz);
                   }else{
                       RotacaoRL(raiz);
                   }
                }
            }
        }else{
           return 0;
        }
    atual->alt = maior(alt_No(atual->esq), alt_No(atual->dir)) + 1;
    return res;
    }
    return 0;
}

void removeCandidate(ArvAVL *raiz, int id){
    if((*raiz) == NULL){
        return;
    }
    int votos = busca_Votos(&(*raiz), id);
    struct No *atual = *raiz;
    struct No* anterior = NULL;

    while(atual != NULL && atual->candidato.id != id){
        anterior = atual;

        if(votos < atual->candidato.votos){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }

    if(atual == NULL){
        return;
    }

    if (atual->esq == NULL && atual->dir == NULL) {
        if (anterior == NULL)
            *raiz = NULL;
        else if (anterior->esq == atual)
            anterior->esq = NULL;
        else
            anterior->dir = NULL;

        free(atual);
    } else if (atual->esq == NULL) {
        if (anterior == NULL)
            *raiz = atual->dir;
        else if (anterior->esq == atual)
            anterior->esq = atual->dir;
        else
            anterior->dir = atual->dir;

        free(atual);
    } else if (atual->dir == NULL) {
        if (anterior == NULL)
            *raiz = atual->esq;
        else if (anterior->esq == atual)
            anterior->esq = atual->esq;
        else
            anterior->dir = atual->esq;

        free(atual);
    } else {
        struct No* sucessor = minimo(atual->dir);
        atual->candidato.id = sucessor->candidato.id;
        atual->candidato.votos = sucessor->candidato.votos;
        removeCandidate(&(atual->dir), sucessor->candidato.id);
    }

    if (*raiz != NULL){
        (*raiz)->alt = maior(alt_No((*raiz)->esq), alt_No((*raiz)->dir)) + 1;
        int balanceamento = fatorBalanceamento_No(*raiz);

        if (balanceamento >= 2) {
            if (fatorBalanceamento_No((*raiz)->esq) >= 0) {
                RotacaoLL(raiz);
            } else {
                RotacaoLR(raiz);
            }
        } else if (balanceamento <= -2) {
            if (fatorBalanceamento_No((*raiz)->dir) <= 0) {
                RotacaoRR(raiz);
            } else {
                RotacaoRL(raiz);
            }
        }
    }
    return;
}


void imprime_Resultados(ArvAVL* raiz){
    if(raiz == NULL)
       return;
    if(*raiz != NULL){
        imprime_Resultados(&((*raiz)->dir));
        printf("------------------------------\n");
        printf("N do Candidato: %d\n", (*raiz)->candidato.id);
        printf("Total de Votos: %d\n", (*raiz)->candidato.votos);
        printf("------------------------------\n");
        imprime_Resultados(&((*raiz)->esq));
    }
}

int main(){
    ArvAVL* raiz = cria_AVL();
    insere_ArvAVL(raiz, 13, 190);
    insere_ArvAVL(raiz, 20, 90);
    insere_ArvAVL(raiz, 19, 175);
    insere_ArvAVL(raiz, 34, 65);
    insere_ArvAVL(raiz, 27, 203);
    insere_ArvAVL(raiz, 39, 119);
    imprime_Resultados(raiz);
    removeCandidate(raiz, 39);
    printf("\n\n\n");
    imprime_Resultados(raiz);
    removeCandidate(raiz, 13);
    printf("\n\n\n");
    imprime_Resultados(raiz);

    return 0;
}