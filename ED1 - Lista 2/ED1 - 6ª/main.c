#include <stdio.h>
#include "ponto.c"

int main(){
    Ponto* teste1 = cria(4,5);
    Ponto* teste2 = cria(2,-8);
    imprime(teste1);
    imprime(teste2);
    Ponto* teste3 = soma(teste1,teste2);
    imprime(teste3);
    teste3 = subtracao(teste1,teste2);
    imprime(teste3);
    libera(teste3);
    imprime(teste3);
    atribui(teste3, 10, 10);
    imprime(teste3);
    return 0;
}