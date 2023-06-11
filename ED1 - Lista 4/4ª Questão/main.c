#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alunos.h"

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct aluno**)malloc(tamanho*sizeof(struct aluno*));
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

int buscaHash(Hash* ha, int mat){
    if(ha == NULL){
       printf("Erro: Tabela Hash nao criada!\n");
       return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Aluno(a) com a matricula %d nao encontrado(a) na tabela!\n", mat);
        return 0;
    }
    struct aluno* aux = ha->itens[pos];
    while(aux != NULL){
        if(mat == aux->mat){
            printf("\n===ALUNO ENCONTRADO===\n");
            printf("Posicao: %d\n", pos);
            printf("Nome: %s\n", aux->nome);
            printf("Matricula: %d\n", aux->mat);
            printf("-----------------\n");
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int insereHash(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.mat;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL){
       return 0;
    }
    *novo = al;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct aluno* aux = ha->itens[pos];
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

int removeHash(Hash* ha, int mat){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Aluno(a) com matricula %d nao encontrado(a)!\n", mat);
        return 0;
    }
    struct aluno *atual = ha->itens[pos];
    struct aluno *anterior = NULL;
    while(atual != NULL){
        if(mat == atual->mat){
            if(anterior == NULL){
                ha->itens[pos] = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            printf("Aluno(a) com matricula %d removido(a) com sucesso!\n", mat);
            return 0;
        }
    anterior = atual;
    atual = atual->prox;
    }
    return 0;
}

float mediaMatricula(Hash* ha){
    if(ha == NULL || ha->qtd == 0){
        printf("Erro na tabela Hash");
    }
    int total = 0, alunos = 0;
    for(int i = 0; i<ha->TABLE_SIZE;i++){
        struct aluno* aux = ha->itens[i];
        while(aux != NULL){
            total += aux->mat;
            aux = aux->prox;
            alunos++;
        }
    }
    float media = (float)total/alunos;
    return media;
}

void imprimeHash(Hash* ha){
    if(ha == NULL){
        printf("Erro: Tabela Hash nao criada!\n");
        return ;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return;
    }
    printf("\n====TABELA HASH====\n");
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        printf("Posicao: %d\n", i);
        struct aluno *aux = ha->itens[i];
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Matricula: %d\n", aux->mat);
            printf("\n");
            aux = aux->prox;
        }
        printf("-------------------\n");
    }

}


int main(){
    Hash *ha = criaHash(10);
    struct aluno a1, a2, a3, a4, a5;
    strcpy(a1.nome, "Diogo");
    a1.mat = 1595469;
    strcpy(a2.nome, "Lucas");
    a2.mat = 1676589;
    strcpy(a3.nome, "Vinicius");
    a3.mat = 1612520;
    strcpy(a4.nome, "Kalil");
    a4.mat = 1345652;
    strcpy(a5.nome, "Maria");
    a5.mat = 1553452;
    insereHash(ha, a1);
    insereHash(ha, a2);
    insereHash(ha, a3);
    insereHash(ha, a4);
    insereHash(ha, a5);
    imprimeHash(ha);
    buscaHash(ha, 1612520);
    buscaHash(ha, 1676589);
    buscaHash(ha, 1595469);
    buscaHash(ha, 1228831);
    printf("\n%.2f\n",mediaMatricula(ha));
    removeHash(ha, 1612520);
    removeHash(ha, 1218524);
    buscaHash(ha, 1612520);
    buscaHash(ha, 1218524);
    printf("\n%.2f\n",mediaMatricula(ha));

    return 0;
}