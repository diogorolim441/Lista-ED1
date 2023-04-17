#define MAX 100
typedef struct{
    int dados;
}nodo;

typedef struct{
    nodo arr[MAX];
    int tamanho;
}lista_est;

typedef struct nodo_lista{
    nodo dados;
    struct nodo_lista* prox;
}nodo_lista;

typedef struct{
    nodo_lista* cabeca;
    int tamanho;
}lista_din;

typedef struct{
    nodo arr[MAX];
    int topo;
}pilha;

void insere_din(lista_din* din, nodo no);
void insere_est(lista_est* est, nodo no);
void cria_pilha(pilha* pi);
void push_pilha(pilha* pi, nodo no);
nodo pop_pilha(pilha* pi);
void inverte_lista_din(lista_din* din);
void inverte_lista_est(lista_est* est);