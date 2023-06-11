#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncadSep.h"

//Cria a tabela

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct valor**)malloc(tamanho*sizeof(struct valor*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(int i = 0; i<ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

//Determina a chave com base no valor dado

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

//Busca na tabela hash o valor indicado

int buscaHash_EncadSep(Hash* ha, int va){
    if(ha == NULL){
        printf("Erro: Tabela Hash nao criada!\n");
        return 0;
    }
    int pos = chaveDivisao(va, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Valor nao encontrado\n");
        return 0;
    }
    struct valor* aux = ha->itens[pos];
    while(aux != NULL){
        if(va == aux->valor){
            printf("\n===VALOR ENCONTRADO===\n");
            printf("Posicao: %d\n", pos);
            printf("Valor: %d\n", aux->valor);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

//Insere na tabela Hash o valor, passando antes pelo sistema de chave para saber sua posição,
//caso já exista um valor na posição, ele reloca esse valor inserido usando um ponteiro

int insereHash_EncadSep(Hash* ha, int va){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = va;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct valor* novo = (struct valor*)malloc(sizeof(struct valor));
    if(novo == NULL){
        return 0;
    }
    novo->valor = va;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct valor* aux = ha->itens[pos];
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

//Remove o valor da tabela Hash, e em caso de já haver um valor no local, ele só o reloca

int removeHash_EncadSep(Hash* ha, int va){
   if(ha == NULL){
        printf("Erro: Tabela Hash nao criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(va, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Valor nao encontrado\n");
        return 0;
    }
    struct valor *atual = ha->itens[pos];
    struct valor *ant = NULL;
    while(atual != NULL){
        if(va == atual->valor){
            if(ant == NULL){
                ha->itens[pos] = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            return 0;
        }
        ant = atual;
        atual= atual->prox;
    }
    return 0;
}

int main(){
    Hash* ha = criaHash(12);
    int num[12] = {
        1,
        2,
        3,
        4,
        11,
        34,
        45,
        7,
        34,
        12,
        67,
        333
    };

    for(int i = 0; i<12; i++){
        insereHash_EncadSep(ha, num[i]);
    }
    buscaHash_EncadSep(ha, 333);
    buscaHash_EncadSep(ha, 7);
    removeHash_EncadSep(ha, 1);
    removeHash_EncadSep(ha, 7);
    buscaHash_EncadSep(ha, 1);
    buscaHash_EncadSep(ha, 7);

    return 0;
}