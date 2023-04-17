#include <stdio.h>

typedef struct{
    char Nome[30];
    int Jogos;
    int Gols;
    int Assistencias;
}Jogador;

void atribuir_jogador(Jogador* jogador, char Nome[], int Jogos, int Gols, int Assistencias);
void imprime_jogador(Jogador jogador);
void bom_jogador(Jogador jogador);