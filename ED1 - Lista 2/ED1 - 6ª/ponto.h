#include <stdio.h>

typedef struct{
    float x;
    float y;
}Ponto;

Ponto* cria(float x,float y);
void libera(Ponto* ponto);
void acessa(Ponto* ponto,float*x,float*y);
void atribui(Ponto* ponto,float x,float y);
Ponto* soma(Ponto* a, Ponto* b);
Ponto* subtracao(Ponto* a, Ponto* b);
void imprime(Ponto* ponto);