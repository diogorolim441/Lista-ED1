typedef struct No* ArvAVL;

typedef struct{
    int votos, id;
}candidato;

struct No{
    candidato candidato; 
    int alt;
    struct No* esq;
    struct No* dir;
};

ArvAVL* cria_AVL();
int insere_ArvAVL(ArvAVL *raiz, int id, int votos);
void removeCandidate(ArvAVL *raiz, int id);