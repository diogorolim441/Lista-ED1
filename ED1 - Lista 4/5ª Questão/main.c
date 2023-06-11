#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashEmpresa.h"

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct produto**)malloc(tamanho*sizeof(struct produto*));
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

int insereHash(Hash* ha, struct produto pro){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = pro.codigo;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct produto* novo = (struct produto*)malloc(sizeof(struct produto));
    if(novo == NULL){
       return 0;
    }
    *novo = pro;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct produto* aux = ha->itens[pos];
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

int buscaHash(Hash* ha, int pro){
    if(ha == NULL){
       printf("Erro: Tabela Hash nao criada!\n");
       return 0;
    }
    int pos = chaveDivisao(pro, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Produto com o codigo %d nao encontrado(a) na tabela!\n", pro);
        return 0;
    }
    struct produto* aux = ha->itens[pos];
    while(aux != NULL){
        if(pro == aux->codigo){
            printf("\n===Produto ENCONTRADO===\n");
            printf("Posicao: %d\n", pos);
            printf("Codigo: %d\n", aux->codigo);
            printf("Nome: %s\n", aux->nome);
            printf("Preco: %.2f\n", aux->preco);
            printf("Quantidade: %d\n", aux->quantidade);
            printf("-----------------\n");
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int atualizarPreco(Hash* ha, int pro, float preco){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int pos = chaveDivisao(pro, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Produto com o codigo %d nao encontrado(a) na tabela!\n", pro);
        return 0;
    }
    struct produto* aux = ha->itens[pos];
    while(aux != NULL){
        if(pro == aux->codigo){
            aux->preco = preco;
            printf("Preco atualizado para %.2f\n", aux->preco);
        }
        aux = aux->prox;
    }
    return 0;
}

int removeHash(Hash* ha, int pro){
    if(ha == NULL){
        printf("Erro: Tabela Hash não criada!\n");
        return 0;
    }
    if(ha->qtd == 0){
        printf("Erro: Tabela Hash vazia!\n");
        return 0;
    }
    int pos = chaveDivisao(pro, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        printf("Produto com o codigo %d nao encontrado(a) na tabela!\n", pro);
        return 0;
    }
    struct produto *atual = ha->itens[pos];
    struct produto *anterior = NULL;
    while(atual != NULL){
        if(pro == atual->codigo){
            if(anterior == NULL){
                ha->itens[pos] = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
            ha->qtd--;
            printf("Produto com codigo %d removido(a) com sucesso!\n", pro);
            return 0;
        }
    anterior = atual;
    atual = atual->prox;
    }
    return 0;
}

void buscaMaisCaro(Hash* ha) {
    if (ha == NULL) {
        printf("Erro: Tabela Hash nao criada!\n");
        return;
    }
    struct produto* prodCaro = NULL;
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        struct produto* aux = ha->itens[i];
        while (aux != NULL) {
            if (prodCaro == NULL || aux->preco > prodCaro->preco) {
                prodCaro = aux;
            }
            aux = aux->prox;
        }
    }

    if (prodCaro != NULL) {
        printf("\n===PRODUTO MAIS CARO===\n");
        printf("Nome: %s\n", prodCaro->nome);
        printf("Codigo: %d\n", prodCaro->codigo);
        printf("Preco: R$%.2f\n", prodCaro->preco);
        printf("Quantidade Disponivel: %d\n", prodCaro->quantidade);
        printf("==========================\n");
    } else {
        printf("Nenhum produto encontrado!\n");
    }
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
    printf("\n====Estoque de Produtos====\n");
    for(int i = 0; i<ha->TABLE_SIZE; i++){
        printf("Posicao: %d\n", i);
        struct produto *aux = ha->itens[i];
        while(aux != NULL){
            printf("Nome: %s\n", aux->nome);
            printf("Codigo: %d\n", aux->codigo);
            printf("Preco: R$%.2f\n", aux->preco);
            printf("Quantidade Disponivel: %d\n", aux->quantidade);
            printf("\n");
            aux = aux->prox;
        }
        printf("-------------------\n");
    }

}

int main(){
    Hash *ha = criaHash(13);
    struct produto p1, p2, p3, p4, p5;
    strcpy(p1.nome, "Leite Itambé - 2L");
    p1.codigo = 1552553;
    p1.preco = 8.90;
    p1.quantidade = 123;
    strcpy(p2.nome, "Cereal Nescau Radical - 300g");
    p2.codigo = 1665002;
    p2.preco = 11.99;
    p2.quantidade = 908;
    strcpy(p3.nome, "Xampu Palmo Live");
    p3.codigo = 9823371;
    p3.preco = 29.53;
    p3.quantidade = 33;
    strcpy(p4.nome, "Cerveja Skol - 2l");
    p4.codigo = 4444444;
    p4.preco = 8.74;
    p4.quantidade = 16;
    strcpy(p5.nome, "Caneta Esfereográfica Bic");
    p5.codigo = 1010101;
    p5.preco = 1.90;
    p5.quantidade= 367;
    insereHash(ha, p1);
    insereHash(ha, p2);
    insereHash(ha, p3);
    insereHash(ha, p4);
    insereHash(ha, p5);
    imprimeHash(ha);
    buscaHash(ha, 9900000);
    buscaHash(ha, 4444444);
    buscaMaisCaro(ha);
    atualizarPreco(ha, 9823371, 5.60);
    buscaMaisCaro(ha);
}