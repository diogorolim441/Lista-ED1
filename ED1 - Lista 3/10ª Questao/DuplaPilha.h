#define MAX 100
typedef struct{
    int dados;
} Nodo;

typedef struct{
    Nodo arr[MAX];
    int topo1;
    int topo2;
} Pilha;

Pilha* inicializar_pilha_dupla();
void Empilha(Nodo A, Pilha* pi, int i);
void imprimir_pilha_dupla(Pilha pi);
int Desempilha(Pilha* pi, int i);