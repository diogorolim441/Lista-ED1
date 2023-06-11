#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncadAbe.h"

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

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int buscaHash_EncadAbe(Hash* ha, int va){
    if(ha == NULL){
       printf("Erro: Tabela Hash nao criada!\n");
       return 0;
    }

    int pos = chaveDivisao(va, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Valor nao encontrado\n");
        return 0;
    }
    if(va == ha->itens[pos]->valor){
        printf("\n===VALOR ENCONTRADO===\n");
        printf("Posicao: %d\n", pos);
        printf("Valor: %d\n", ha->itens[pos]->valor);
        return 1;
    }
    return 0;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EncadAbe(Hash* ha, int va){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
       return 0;
    }
    int pos = chaveDivisao(va, ha->TABLE_SIZE);
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            struct valor* novo = (struct valor*)malloc(sizeof(struct valor));
            if(novo == NULL){
               return 0;
            }
            novo->valor = va;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int main(){
    Hash* ha = criaHash(20);
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
        insereHash_EncadAbe(ha, num[i]);
    }
    buscaHash_EncadAbe(ha, 333);
    buscaHash_EncadAbe(ha, 7);
    return 0;
}