#include <stdio.h>
#include <stdlib.h>
#include "ListaRemove.h"

//PROBLEMA 1

void remove_lista(lista_est* L1,lista_est* L2,lista_est* L3){
    for(int i=0;i<L2->tamanho;i++){
        L1->arr[L2->arr[i].dados-1].dados = 0; //Some com os valores da L2
    }

    for(int j=0;j<L3->tamanho;j++){
        L1->arr[L3->arr[j].dados-1].dados = 0; //Some com os valores da L3

    }     
   
    int j, i;
    for(i=0,j=0;i<L1->tamanho;i++){
        if(L1->arr[i].dados!=0){
            L1->arr[j++].dados=L1->arr[i].dados; //"Reagrupa" a L1
        }
    }
    for(int i=0;i<j+1;i++) {
        L1->tamanho--;
    }
}

int main(){
    lista_est L1 = {{1,2,3,4,5}, 5};
    lista_est L2 = {{2,4,8}, 3};
    lista_est L3 = {{2,5}, 2};

    for(int i=0;i<L1.tamanho;i++){
        printf("%d ", L1.arr[i].dados);
    }
    printf("\n");

    remove_lista(&L1,&L2,&L3);

    for(int i=0;i< L1.tamanho;i++){
        printf("%d ", L1.arr[i].dados);
    }
    
    return 0;
}