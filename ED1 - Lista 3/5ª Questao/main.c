#include <stdio.h>
#include <stdlib.h>
#include "TADListaDup.h"

lista_din* cria_lista_dupla(){
    lista_din* din = (lista_din*)malloc(sizeof(lista_din));
    din->cabeca = NULL;
    din->tamanho = 0;
    return din;
}

void libera_lista(lista_din* din){
    free(din);
}

void lista_vazia(lista_din * din){
    if(din->tamanho == 0){
        printf("Lista Vazia");
    }
}

void lista_cheia(lista_din* din){
    printf("Ta cheia nao");
}

void insere_lista_dupla_inicio(lista_din* din, nodo no){
    nodo* no_novo = (nodo*)malloc(sizeof(nodo));
    no_novo->dados = no.dados;
    no_novo->prox = din->cabeca;
    no_novo->ante = NULL;

    if(din->cabeca == NULL){
        din->cabeca->ante = no_novo;
    }

    din->cabeca = no_novo;
}

void insere_lista_dupla_ordenada(lista_din* din, nodo no){
    nodo* no_novo = (nodo*)malloc(sizeof(nodo));
    no_novo->dados = no.dados;

    if(din->cabeca == NULL){
        no_novo->prox = NULL;
        no_novo->ante = NULL;
        din->cabeca = no_novo;
        return;
    }
    
    if (no.dados < din->cabeca->dados){
        no_novo->ante = NULL;
        no_novo->prox = din->cabeca;
        din->cabeca->ante = no_novo;
        din->cabeca = no_novo;
        return;
    }

    nodo* atual = din->cabeca;
    while (atual->prox != NULL && atual->prox->dados < no.dados) { // encontrar o local de inserção
        atual = atual->prox;
    }

    no_novo->prox = atual->prox;
    no_novo->ante = atual;
    if (atual->prox != NULL) {
        atual->prox->ante = no_novo;
    }
    atual->prox = no_novo;
}

void insere_lista_dupla_final(lista_din* din, nodo no){
    nodo* no_novo = (nodo*)malloc(sizeof(nodo));
    no_novo->dados = no.dados;
    no_novo->prox = NULL;

    if(din->cabeca == NULL){
        no_novo->ante = NULL;
        din->cabeca = no_novo;
        return;
    }

    nodo* atual = din->cabeca;
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = no_novo;
    no_novo->ante = atual;
}

void remove_lista_dupla_inicio(lista_din* din){
    nodo* aux = din->cabeca;
    if (din->cabeca == NULL){
        return;
    }

    din->cabeca = din->cabeca->prox;
    if(din->cabeca != NULL) {
        din->cabeca->ante = NULL;
    }
    free(aux);
}

void remove_lista_dupla(lista_din* din, int num){
    nodo *aux = din->cabeca;
    if (din->cabeca == NULL){
        return;
    }
    int i = 1;
    while(i < num && aux != NULL){
        aux = aux->prox;
        i++;
    }

    if(aux == NULL){ // posição inválida
        return;
    }

    if(aux->ante != NULL){
        aux->ante->prox = aux->prox;
    } else {
        din->cabeca = aux->prox;
    }

    if(aux->prox != NULL){
        aux->prox->ante = aux->ante;
    }

    free(aux);
}

void remove_lista_dupla_final(lista_din* din){
    nodo* aux= din->cabeca;
    if (din->cabeca == NULL){
        return;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    if(aux->ante != NULL){
        aux->ante->prox = NULL;
    }else{
        din->cabeca = NULL;
    }
    free(aux);
}

void tamanho_lista(lista_din* din){
    printf("Tamanho da lista:%d\n", din->tamanho);
}

void imprimir_lista(lista_din* din){
    nodo *atual = din->cabeca;
    while (atual != NULL){
        printf("%d ", atual->dados);
        atual = atual->prox;
    }
    printf("\n");
}

int main(){
    lista_din* li = cria_lista_dupla();
    nodo n;
    remove_lista_dupla_inicio(&li);
    for(int i=0;i<5;i++){
        n.dados = i;
        insere_lista_dupla_ordenada(&li,n);
    }
    imprimir_lista(&li);

    return 0;
}
