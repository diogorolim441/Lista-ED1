#ifndef TABELAHASH_H
#define TABELAHASH_H
#include "ArvoreAVL.h"
#include "ArvoreAVL.c"

struct discagem{
    int prefixo;
    ArvAVL *arv;
    struct discagem* prox;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash(Hash *ha, int ddd, struct dados pessoa);
int buscaHash(Hash *ha, int prefixo, ArvAVL *arv);
void imprimirTabelaOrdenadaNumero(int TABLE_SIZE, Hash *ha);
void imprimirTabelaOrdenadaNome(int TABLE_SIZE, Hash *ha);
#endif