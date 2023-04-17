typedef struct nodo{
    int dados;
    struct nodo* prox;
    struct nodo* ante;
}nodo;

typedef struct{
    nodo* cabeca;
    int tamanho;
}lista_din;

lista_din* cria_lista_dupla();
void insere_lista_dupla(lista_din* lista, int no);
void remover_lista_dupla(lista_din *li, int num);