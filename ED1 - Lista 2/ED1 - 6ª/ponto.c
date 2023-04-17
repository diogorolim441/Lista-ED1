#include <stdio.h>
#include "ponto.h"
#include <stdlib.h>
#include <math.h>

Ponto* cria(float x,float y){
    Ponto*p =(Ponto*)malloc(sizeof(Ponto));
    if(ponto==NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    ponto->x=x;
    ponto->y=y;
    return ponto;
}

void libera(Ponto* p){
    free(p);
}

void acessa(Ponto* p,float*x,float*y){
    *x = p->x;
    *y = p->y;
}

void atribui(Ponto* p,float x,float y){
    p->x=x;
    p->y=y;
}

Ponto* soma(Ponto* a, Ponto* b){
    Ponto* c = cria(a->x + b->x, a->y + b->y);
    return c;
}

Ponto* subtracao(Ponto* a, Ponto* b){
    Ponto* c = cria(a->x - b->x, a->y - b->y);
    return c;
}

void imprime(Ponto* ponto){
    printf("X: %.1f\nY: %.1f\n\n", ponto->x, ponto->y);
}