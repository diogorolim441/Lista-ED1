#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "TabelaHash.h"

typedef struct NO *ArvAVL;

struct hash {
    int qtd, TABLE_SIZE;
    struct discagem **itens;
};

// cria a tabela hash
Hash* criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash *) malloc(sizeof(Hash));
    if(ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct discagem**) malloc(TABLE_SIZE * sizeof(struct discagem*));
        if(ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i<ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

// libera a tabela hash
void liberaHash(Hash *ha) {
    if(ha != NULL) {
        int i;
        for(i=0; i<ha->TABLE_SIZE; i++) {
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

/*
Método da Divisao: Consiste em calcular o "resto da divisão" do valor inteiro que
representa o elemento pelo tamanho da tabela, "TABLE_SIZE".
- A operação de "E bit-a-bit" com o valor 0x7FFFFFFF elimina o bit de sinal do
valor da "chave".
- Evita o risco de ocorrer um overflow e obtermos um número negativo
*/

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

/*
Método da Multiplicação: Usa o valor "A", "0 < A < 1", para multiplicar o valor da
"chave" que representa o elemento. Em seguida, a "parte fracionaria" resultante é
multiplicada pelo tamanho da tabela para calcular a posição do elemento
*/

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; // constante 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

/*
Método da Dobra: Utiliza um esquema de dobrar e somar os dígitos do valor para calcular
a sua posição.
- Considera o "valor inteiro" que representa o elemento como uma sequência de dígitos
escritos num pedaço de papel. Enquanto esse valor for maior que o tamanho da tabela, o
papel é dobrado e os dígitos sobrepostos são somados, desconsiderando-se as dezenas.
- Pode ser usado com valores binários.
- Utiliza a operação de "ou exclusivo"
- A dobra é realizada de "k em k bits" o que resulta em um valor de posição entre "0 e 2k+1"
*/

int chaveDobra(int chave, int TABLE_SIZE) {
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}

/*
"Tratando uma string como chave"
- Calcular um valor numérico a partir dos valores ASCII dos caracteres
- Devemos considerar a posição da letra
"Cuidado"
- Não devemos apenas somar os caracteres, pois palavras com letras trocadas irão
produzir o mesmo valor
cama: 99 + 97 + 109 + 97 = 402
maca: 109 + 97 + 99 + 97 = 402
*/

int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

// insere uma arvore na tabela hash dentro da lsita encadeada
int insereHash(Hash *ha, int ddd, struct dados pessoa) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)  
        return 0;
    int chave = ddd;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct discagem* novo = (struct discagem*)malloc(sizeof(struct discagem));
    novo->prefixo = ddd;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL) {
        ha->itens[pos] = novo;  // coloca a árvore na tabela hash caso não exista nenhuma
    } else {
        struct discagem* aux = ha->itens[pos];
        while (aux != NULL) {
            if (aux->prefixo == ddd) {
                int resultInsereArv = insere_ArvAVL(aux->arv, pessoa);
                if (resultInsereArv == 0) {
                    free(novo); // libera a memória alocada para 'novo'
                    return 0;
                }
                return 1;
            }
            aux = aux->prox;
        }
        aux = novo; // atualiza o ponteiro aux para 'novo'
    }
    ArvAVL *arv = cria_ArvAVL();
    insere_ArvAVL(arv, pessoa);
    novo->arv = arv;
    ha->qtd++;
    return 1;
}


int buscaHash(Hash *ha, int prefixo, ArvAVL *arv) {
    if(ha == NULL)
        return 0;
    int pos = chaveDivisao(prefixo, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    struct discagem* aux = ha->itens[pos];
    while(aux != NULL){
        if(aux->prefixo == prefixo){
            *arv = (*aux->arv);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

/* varre toda a tabela hash e imprime os dados das arvores das discagems encadeadas que estao 
na tabela hash ordenado por numero*/
void imprimirTabelaOrdenadaNumero(int TABLE_SIZE, Hash *ha) {
    int i, existePessoa = 0;
    printf("\n------------------------TABELA--------------------------\n");
    for(i = 0; i < TABLE_SIZE; i++) {
        struct discagem* aux = ha->itens[i];
        while(aux != NULL){
            printf("DDD: %d\n", aux->prefixo);
            emOrdem_ArvAVL(aux->arv);
            aux = aux->prox;
            existePessoa++;
        } 
    }
    if(existePessoa == 0) {
        printf("Nao existe pessoas cadastradas no catalogo.\n");
    }
    printf("----------------------FIM TABELA------------------------\n");
}

void imprimirTabelaOrdenadaNome(int TABLE_SIZE, Hash *ha) {
    int existePessoa = 0;
    printf("\n------------------------TABELA--------------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct discagem* aux = ha->itens[i];
        while (aux != NULL) {
            ArvAVL* auxNome = cria_ArvAVL();
            reorganizarArvAVL(aux->arv,&auxNome);
            printf("DDD: %d\n", aux->prefixo);
            imprimirEmOrdemNome(*(auxNome)); // Passa o valor da árvore, não o ponteiro para a árvore
            aux = aux->prox;
            existePessoa++;
            libera_ArvAVL(auxNome);
        }
    }
    if (existePessoa == 0) {
        printf("Nao existe pessoas cadastradas no catalogo.\n");
    }
    printf("----------------------FIM TABELA------------------------\n");
}