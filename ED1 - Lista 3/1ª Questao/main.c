#include <stdio.h>
#include <stdlib.h>
#include "ListaEst.h"

void insere_est(lista_est* est, nodo no){
    if(est->tamanho == MAX){
        printf("tem espaço n, maluco");
        return;
    }
    est->arr[est->tamanho] = no;
    est->tamanho++;
}

void insere_din(lista_din* din, nodo no){
    nodos_lista* novo_nodo = (nodos_lista*)malloc(sizeof(nodos_lista));
    novo_nodo->dados = no;
    novo_nodo->prox = NULL;

    if(din->cabeca == NULL){
        din->cabeca = novo_nodo;
    }else{
        nodos_lista* atual = din->cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo_nodo;
    }
    din->tamanho++;
}

void copiar_Est_para_Din(lista_est* est, lista_din* din){
    for(int i=0; i<est->tamanho;i++){
        insere_din(din, est->arr[i]);
    }
}

void copiar_Din_para_Est(lista_est* est, lista_din* din){
    nodos_lista* atual = din->cabeca;
    while(atual != NULL){
        insere_est(est,atual->dados);
        atual = atual->prox;
    }
}

int main(){
    lista_est est_1 = {{1,2,3,4}, 4};
    lista_din din_1 = {NULL, 0};
    lista_est est_2 = {{}};
    lista_din din_2 = {NULL, 0};

    //PROBLEMA 1

    printf("PROBLEMA 1\n");
    copiar_Est_para_Din(&est_1,&din_1);

    nodos_lista* aux = din_1.cabeca;
    while(aux != NULL){
        printf("%d\n", aux->dados.dados);
        aux = aux->prox;
    }

    //PROBLEMA 2

    printf("\nPROBLEMA 2\n");
    nodo n;

    for(int i = 5; i<9;i++){
        n.dados = i;
        insere_din(&din_2, n);
    }

    copiar_Din_para_Est(&est_2,&din_2);
    for(int j = 0; j<est_2.tamanho;j++){
        printf("%d\n", est_2.arr[j]);
    }
    return 0;
}