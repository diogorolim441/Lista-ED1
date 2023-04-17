#include <stdio.h>
#include "Jogador.h"

typedef struct {
    char Nome[30];
    Jogador Jogador[11];
    int Vitorias;
    int Empates;
    int Derrotas;
}Time;

void atribuir_time(Time* time, char Nome[], Jogador Jogador[], int Vitorias, int Empates, int Derrotas);
void imprime_time(Time time);
int pontuacao(Time time);