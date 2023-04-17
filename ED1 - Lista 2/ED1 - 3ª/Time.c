#include <stdio.h>
#include "Time.h"
#include "Jogador.c"
#include <stdlib.h>
#include <string.h>

void atribuir_time(Time* time, char Nome[], Jogador Jogador[], int Vitorias, int Empates, int Derrotas) {
    strcpy(time->Nome, Nome);
    for(int i=0; i<11; i++) {
        time->Jogador[i] = Jogador[i];
    }
    time->Vitorias = Vitorias;
    time->Empates = Empates;
    time->Derrotas = Derrotas;
}

void imprime_time(Time time) {
    printf("Nome: %s\n", time.Nome);
    printf("Jogadores:\n");
    for(int i=0; i<11; i++) {
        printf("  %s\n", time.Jogador[i].Nome);
    }
    printf("Vitórias: %d\n", time.Vitorias);
    printf("Empates: %d\n", time.Empates);
    printf("Derrotas: %d\n", time.Derrotas);
}

int pontuacao(Time time) {
    return time.Vitorias * 3 + time.Empates;
}