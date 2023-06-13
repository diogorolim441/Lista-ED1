typedef struct No* ArvBin;

struct No{
    int info;
    struct No* esq;
    struct No* dir;
};

ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin* raiz, int valor);
int consulta_ArvBin(ArvBin* raiz, int valor);
int maiormenorValor(ArvBin* raiz);
int mediaArvBin(ArvBin* raiz);
int numeroNULLS(ArvBin* raiz);
int somaChaveNos(ArvBin* raiz);
int multiploTres(ArvBin* raiz);
int totalNo(ArvBin* raiz);
int numeroFolhas(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int verifica_ArvBin(ArvBin* raiz);