struct aluno{
    int mat;
    char nome[30];
    struct aluno* prox;
};

typedef struct{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
}Hash;

Hash* criaHash(int tamanho);
int buscaHash(Hash* ha, int mat);
int insereHash(Hash* ha, struct aluno al);
int removeHash(Hash* ha, int mat);
float mediaMatricula(Hash* ha);