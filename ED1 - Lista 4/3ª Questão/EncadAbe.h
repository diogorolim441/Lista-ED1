struct valor{
    int valor;
};

typedef struct{
    int qtd, TABLE_SIZE;
    struct valor **itens;
}Hash;

Hash* criaHash(int tamanho);
int buscaHash_EncadAbe(Hash* ha, int va);
int insereHash_EncadAbe(Hash* ha, int va);
int removeHash_EncadAbe(Hash* ha, int va);