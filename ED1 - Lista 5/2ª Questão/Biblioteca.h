typedef struct No* ArvBin;

struct No{
    int id, ano;
    char nome[30], titulo[50];
    struct No* esq;
    struct No* dir;
};

/*Agora, você precisa desenvolver uma função que encontre todos os livros de um
determinado autor em um determinado intervalo de anos.*/

ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin* raiz, int id, int ano, char nome[], char titulo[]);
void encontrarLivros(ArvBin* raiz, char nome[], int ano_ini, int ano_fim);