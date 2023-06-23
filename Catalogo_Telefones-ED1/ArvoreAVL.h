#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

struct dados {
    float numero;
    char nome[100];
    char endereco[100];
};

typedef struct NO *ArvAVL;

int insere_ArvAVL(ArvAVL *raiz, struct dados pessoa);
int remove_ArvAVL(ArvAVL *raiz, int numero);
ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int numero);

#endif