#define MAX 100
typedef struct{
    int dados;
}nodo;

typedef struct{
    nodo arr[MAX];
    int tamanho;
}lista_est;

void remove_lista(lista_est* L1,lista_est* L2,lista_est* L3);