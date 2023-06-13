#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
       *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz, int id, int ano, char nome[], char titulo[]){
    if(raiz == NULL){
        printf("Árvore vazia!\n");
        return 0;
    }
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        printf("Erro na criação do nó!\n");
        return 0;
    }
    novo->ano = ano;
    novo->id = id;
    strcpy(novo->nome, nome);
    strcpy(novo->titulo, titulo);
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
       *raiz = novo;
    }else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(id == atual->id){
                free(novo);
                return 0;
            }
            if(id > atual->id){
               atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(id > ant->id){
           ant->dir = novo;
        }else{
           ant->esq = novo;
        }
    }
    return 1;
}

void encontrarLivros(ArvBin* raiz, char nome[], int ano_ini, int ano_fim){
    if(raiz == NULL){
        printf("Arvore vazia!\n");
        return;
    }
    while((*raiz) != NULL){
        if(strcmp((*raiz)->nome, nome) == 0 && (*raiz)->ano >= ano_ini && (*raiz)->ano <= ano_fim){
            printf("=====Livro de %s =====\n", nome);
            printf("Titulo: %s\n",(*raiz)->titulo);
            printf("Autor: %s\n", (*raiz)->nome);
            printf("ID: %d\n", (*raiz)->id);
            printf("Ano: %d\n", (*raiz)->ano);
            printf("-----------------------\n");
        }
        encontrarLivros(&((*raiz)->esq), nome, ano_ini, ano_fim);
        encontrarLivros(&((*raiz)->dir), nome, ano_ini, ano_fim);
        return;
    }
}

int main(){
    ArvBin* raiz = cria_ArvBin();
    insere_ArvBin(raiz, 187299, 1902, "Euclides da Cunha", "Os Sertoes");
    insere_ArvBin(raiz, 187300, 1956, "Guimaraes Rosa", "Grande Sertao - Veredas do Campo");
    insere_ArvBin(raiz, 170331, 1938, "Graciliano Ramos", "Vidas Secas");
    insere_ArvBin(raiz, 131465, 2005, "Markus Zusak", "A menina que roubava livros");
    insere_ArvBin(raiz, 130044, 2011, "Ernest Cline", "Jogador N 1");
    insere_ArvBin(raiz, 166122, 2020, "Ernest Cline", "Jogador N 2");
    insere_ArvBin(raiz, 159546, 2012, "Raphael Draccon", "Dragoes de Eter - Cacadores de Bruxas");
    insere_ArvBin(raiz, 186486, 2014, "Raphael Draccon", "Dragoes de Eter - Coracoes de Neve");
    insere_ArvBin(raiz, 173418, 2017, "Raphael Draccon", "Dragoes de Eter - Circulos de Chuva");
    insere_ArvBin(raiz, 166543, 2020, "Raphael Draccon", "Dragoes de Eter - Estandartes de Nevoa");
    encontrarLivros(raiz, "Ernest Cline", 2010, 2020);
    encontrarLivros(raiz, "Raphael Draccon", 2010, 2023);
    
    return 0;
}