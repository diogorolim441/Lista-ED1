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
void libera_lista(lista_din* din);
void lista_vazia(lista_din * din);
void lista_cheia(lista_din* din);
void insere_lista_dupla_inicio(lista_din* din, nodo no);
void insere_lista_dupla_ordenada(lista_din* din, nodo no);
void insere_lista_dupla_final(lista_din* din, nodo no);
void remove_lista_dupla_inicio(lista_din* din);
void remove_lista_dupla(lista_din* din, int num);
void remove_lista_dupla_final(lista_din* din);
void tamanho_lista(lista_din* din);
void imprimir_lista(lista_din* din);