typedef struct No* ArvAVL;

struct No{
    int pontos, alt;
    char nome[30];
    struct No* esq;
    struct No* dir;
};

ArvAVL* cria_AVL();
int insere_ArvAVL(ArvAVL *raiz, char nome[], int pontos);
void alteraValor(ArvAVL* raiz, char nome[], int novoPonto); //Fiz um sistema de eliminar o valor antigo da árvore, reorganizar ela e depois inserir o time
                                                            //novamente com o novo valor de pontos