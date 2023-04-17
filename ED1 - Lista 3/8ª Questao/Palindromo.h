#define MAX 100

typedef struct{
    char palavra[MAX];
    int topo;
}Pilha;

Pilha* inicializar_pilha();
void pull_pilha(Pilha* pi, char letra);
void verificar_palindromo(Pilha* pi);