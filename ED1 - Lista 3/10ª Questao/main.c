#include <stdio.h>
#include <stdlib.h>
#include "DuplaPilha.h"

Pilha* inicializar_pilha_dupla(){
    Pilha* pi =(Pilha*)malloc(sizeof(Pilha));
    pi->topo1 = -1;
    pi->topo2 = MAX;
    return pi;
}

void imprimir_pilha_dupla(Pilha pi){
    for(int i = 0; i <= pi.topo1; i++){
        printf("%d ", pi.arr[i].dados);
    }
    for(int i = pi.topo2; i < MAX; i++){
        printf("%d ", pi.arr[i].dados);
    }
    printf("\n");
}

//ITEM a)

void Empilha(Nodo A, Pilha* pi, int i){
    Nodo* novo_no =(Nodo*)malloc(sizeof(Nodo));
    novo_no->dados = A.dados;
    if(pi->topo2 - pi->topo1 == 1){
        printf("Pilhas Cheias");
    }else if(i == 1){
        pi->topo1++;
        pi->arr[pi->topo1] = A;
    }else if(i == 2){
        pi->topo2--;
        pi->arr[pi->topo2] = A;
    }else{
        printf("Nao ha pilha com esse j");
    }
}

//ITEM b)

int Desempilha(Pilha* pi, int i){
    if(i == 1){
        if(pi->topo1 == -1){
            printf("A pilha 1 ta vazia!\n");
            return -1;
        }else{
            int j = pi->arr[pi->topo1].dados;
            pi->topo1--;
            return j;
        }
    }else if(i == 2){
        if(pi->topo2 == MAX){
            printf("A pilha 2 ta vazia!\n");
            return -1;
        }else{
            int j = pi->arr[pi->topo2].dados;
            pi->topo2++;
            return j;
        }
    }else{
        printf("Nao ha pilha com esse valor!\n");
        return -1;
    }
}

int main(){
    Pilha* pi = inicializar_pilha_dupla();
    Nodo n;
    for(int i = 0; i < 10; i++){
        n.dados = i;
        if(n.dados % 2 == 0){
            Empilha(n, pi, 1);
        }else{
            Empilha(n, pi, 2);
        }
    }

    imprimir_pilha_dupla(*pi);

    printf("%d\n",Desempilha(pi,1));
    imprimir_pilha_dupla(*pi);
    return 0;
}