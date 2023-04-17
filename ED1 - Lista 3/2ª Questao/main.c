#include <stdio.h>
#include <stdlib.h>
#include "ListaDupEncad.h"

//ITEM a)

lista_din* cria_lista_dupla(){
    lista_din* li = (lista_din*)malloc(sizeof(lista_din));
    li->cabeca = NULL;
    li->tamanho = 0;
    return li;
}


//ITEM b)

void insere_lista_dupla(lista_din* li, int num){
    nodo* no = (nodo*)malloc(sizeof(nodo));
    no->dados = num;
    no->prox = NULL;
    no->ante = NULL;
    if(li->cabeca == NULL){
        li->cabeca = no;
    }else{
        nodo *atual = li->cabeca;
        while(atual->prox != NULL){ 
            atual = atual->prox;           //achar o último da fila
        }
        atual->prox = no;
        no->ante = atual;
    }
    li->tamanho++;
}

//ITEM c)

void remover_lista_dupla(lista_din *li, int num){
    nodo *atual = li->cabeca;
    while(atual != NULL) {
    if(atual->dados == num) {
        if (atual->ante == NULL){
            li->cabeca = atual->prox;
            if (li->cabeca != NULL) {
                li->cabeca->ante = NULL;
            }
        }else{
            atual->ante->prox = atual->prox;
            if(atual->prox != NULL){
               atual->prox->ante = atual->ante;
            }
        }
        free(atual);
        return;
      }
      atual = atual->prox;
   }
}

int main(){
    lista_din* li = cria_lista_dupla();
    int n;
    n = 7;
    insere_lista_dupla(li,n);
    printf("%d\n", li->cabeca->dados); //imprime 7   lista = {7}
    insere_lista_dupla(li,8);
    printf("%d\n", li->cabeca->dados); //imprime 7   lista = {7,8}
    remover_lista_dupla(li,7);
    printf("%d", li->cabeca->dados);   //imprime 8   lista = {8}
    return 0;
}