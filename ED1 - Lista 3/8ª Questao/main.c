#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Palindromo.h"

Pilha* inicializar_pilha(){
    Pilha* pi =(Pilha*) malloc(sizeof(Pilha));
    pi->topo = -1;
    return pi;
}

void push_pilha(Pilha* pi, char letra){
    pi->topo++;
    pi->palavra[pi->topo] = letra;
}

void verificar_palindromo(Pilha* pi){
    int i;
    char oposto;

    if((pi->topo + 1) % 2 == 0){
        for(i = 0; i <=(pi->topo + 1) / 2; i++){
            oposto = pi->palavra[pi->topo - i];
            if(pi->palavra[i] != oposto){
                printf("Nao eh Palindromo");
                return;
            }
        }
    }else{
        for(i = 0; i < pi->topo / 2; i++){
            oposto = pi->palavra[pi->topo - i];
            if(pi->palavra[i] != oposto){
                printf("Nao eh Palindromo");
                return;
            }
        }
    }
    printf("Eh Palindromo");
}

int main(){
    char palavra[MAX];
    int tam, i;
    Pilha* pi = inicializar_pilha();

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    tam = strlen(palavra);
    for(i = 0; i < tam; i++){
        push_pilha(pi, palavra[i]);
    }

    verificar_palindromo(pi);

    return 0;
}