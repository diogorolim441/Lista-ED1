#include <stdio.h>
#include <stdlib.h>
#include "ListaInverte.h"

void insere_din(lista_din* din, nodo no){
    nodo_lista* novo_nodo = (nodo_lista*)malloc(sizeof(nodo_lista));
    novo_nodo->dados = no;
    novo_nodo->prox = NULL;

    if(din->cabeca == NULL){
        din->cabeca = novo_nodo;
    }else{
        nodo_lista* atual = din->cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo_nodo;
    }
    din->tamanho++;
}

void insere_est(lista_est* est, nodo no){
    est->arr[est->tamanho] = no;
    est->tamanho++;
}

void cria_pilha(pilha* pi){
    pi->topo = -1;
}

void push_pilha(pilha* pi, nodo no){
    pi->topo++;
    pi->arr[pi->topo] = no;
}

nodo pop_pilha(pilha* pi){
    nodo aux;
    aux = pi->arr[pi->topo]; 
    pi->topo--;
    return aux;
}

void inverte_lista_din(lista_din* din){
    pilha pi;
    cria_pilha(&pi);
    while(din->cabeca != NULL){
        push_pilha(&pi, din->cabeca->dados);
        nodo_lista *aux = din->cabeca;
        din->cabeca = din->cabeca->prox;
        free(aux);
    }
    din->tamanho = 0;
    while(pi.topo >= 0){
        insere_din(din, pop_pilha(&pi));
    }
}

void inverte_lista_est(lista_est* est){
    pilha pi;
    cria_pilha(&pi);
    for(int i=0;i<est->tamanho;i++){
        push_pilha(&pi, est->arr[i]);
    }
    for(int i=0;i<est->tamanho;i++){
        est->arr[i] = pop_pilha(&pi);
    }
}

int main(){
    lista_est est;
    est.tamanho = 0;
    nodo n;
    for(int i=0;i<5;i++){
        n.dados = i;
        insere_est(&est, n);
        printf("%d ", est.arr[i]);
    }
    printf("\n");

    inverte_lista_est(&est);

    for(int i=0;i<5;i++){
        printf("%d ", est.arr[i]);
    }

    printf("\n");
    printf("\n");

    lista_din din = {NULL, 0};
    for(int i=5;i<10;i++){
        n.dados = i;
        insere_din(&din, n);
    }

    nodo_lista* aux = din.cabeca;
    while(aux != NULL){
        printf("%d ", aux->dados.dados);
        aux = aux->prox;
    }
    printf("\n");
    inverte_lista_din(&din);
    aux = din.cabeca;
    while(aux != NULL){
        printf("%d ", aux->dados.dados);
        aux = aux->prox;
    }

    return 0;

}