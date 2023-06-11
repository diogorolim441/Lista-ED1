#define TABLE_SIZE 100

struct cidade{
    char nome[30];
    struct cidade *prox;
};

typedef struct{
    int qtd, tam;
    struct cidade **itens;
}Hash;

Hash* criaHash();
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int insereCidade(Hash* ha, struct cidade ci);
void imprimeColisao(Hash* ha);