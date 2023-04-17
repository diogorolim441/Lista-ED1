#define MAX 100
typedef struct{
    int dados;
}nodo;

typedef struct{
    nodo arr[MAX];
    int tamanho;
}lista_est;

typedef struct nodos_lista{
    nodo dados;
    struct nodos_lista* prox;
}nodos_lista;

typedef struct{
    nodos_lista* cabeca;
    int tamanho;
}lista_din;

void insere_din(lista_din* din, nodo no);
void insere_est(lista_est* est, nodo no);
void copiar_Est_para_Din(lista_est* est, lista_din* din);
void copiar_Din_para_Est(lista_est* est, lista_din* din);