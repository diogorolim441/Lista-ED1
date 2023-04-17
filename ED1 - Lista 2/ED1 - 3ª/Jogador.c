#include <stdio.h>
#include "Jogador.h"
#include <string.h>

void atribuir_jogador(Jogador* jogador, char Nome[], int Jogos, int Gols, int Assistencias){
    strcpy(jogador->Nome, Nome);
    jogador->Jogos = Jogos;
    jogador->Gols = Gols;
    jogador->Assistencias = Assistencias;
}

void imprime_jogador(Jogador jogador){
    printf("Nome: %s\nJogos: %d\nGols: %d\nAssistencias: %d\n", jogador.Nome, jogador.Jogos, jogador.Gols, jogador.Assistencias);
}

void bom_jogador(Jogador jogador){
    if(jogador.Gols+(jogador.Assistencias/2) > jogador.Jogos){
        printf("%s é bom", jogador.Nome);
    }else{
        printf("%s nao é bom", jogador.Nome);
    }
}

int main(){
    
}