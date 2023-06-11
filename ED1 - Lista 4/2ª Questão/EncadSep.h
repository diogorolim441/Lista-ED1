
struct valor{
    int valor;
    struct valor* prox;
};

typedef struct{
    int qtd, TABLE_SIZE;
    struct valor **itens;
}Hash;

Hash* criaHash(int tamanho);
int buscaHash_EncadSep(Hash* ha, int va);
int insereHash_EncadSep(Hash* ha, int va);
int removeHash_EncadSep(Hash* ha, int va);