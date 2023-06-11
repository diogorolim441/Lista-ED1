#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CidadesHash.h"

Hash* criaHash(){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        ha->tam = TABLE_SIZE;
        ha->itens = (struct cidade**)malloc(TABLE_SIZE*sizeof(struct cidade*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(int i = 0; i<ha->tam; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i = 0; i<ha->tam; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int tam){
    return (chave & 0x7FFFFFFF) % tam;
}

int valorString(char* str){
    int valor = 7;
    int tam = strlen(str);
    for(int i = 0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

int insereCidade(Hash* ha, struct cidade cidade){
    if(ha == NULL || ha->qtd == ha->tam)
        return 0;

    int chave = valorString(cidade.nome);
    int pos = chaveDivisao(chave, ha->tam);
    struct cidade* novo = (struct cidade*)malloc(sizeof(struct cidade));
    if(novo == NULL)
       return 0;
    *novo = cidade;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct cidade* aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

//Item b)

void imprimeColisao(Hash* ha){
    if(ha->qtd == 0){
        printf("Tabela Vazia!");
    }
    int col = 0;
    int num_ender[11] = {0};
    for(int i = 0; i<ha->tam; i++){
        int cont = 0;
        if(ha->itens[i] != NULL){
            struct cidade* aux = ha->itens[i];
            while(aux != NULL){
                cont++;
                aux = aux->prox;
            }
            if(cont > 1){
                col++;
            }
            if(cont <= 10){
                num_ender[cont]++;
            }else{
                num_ender[10]++;
            }
        }else{
            num_ender[0]++;
        }
        printf("Endereco: %d\n",i);
        struct cidade *aux = ha->itens[i];
        while(aux != NULL){
            printf("%s\n", aux->nome);
            aux = aux->prox;
        }
        printf("\n");
    }
    printf("\nNumero de colisoes: %d\n", col);
    for(int i = 0; i<=10; i++){
        printf("Numero de enderecos com %d cidade(s): %d\n", i, num_ender[i]);
    }
    printf("Numero de enderecos com mais de 10 cidades associadas: %d\n", num_ender[10]);
}

int main() {
    Hash* ha = criaHash();
    struct cidade cidades[31] = {
        {"Acarape"},
        {"Acarau"},
        {"Aquiraz"},
        {"Aracati"},
        {"Arneiroz"},
        {"Aratuba"},
        {"Assare"},
        {"Amontada"},
        {"Caridade"},
        {"Cascavel"},
        {"Caucaia"},
        {"Crato"},
        {"Cruz"},
        {"Carire"},
        {"Croata"},
        {"Fortaleza"},
        {"Farias Brito"},
        {"Forquilha"},
        {"Frecheirinha"},
        {"Pacajus"},
        {"Pacatuba"},
        {"Paraipaba"},
        {"Parambu"},
        {"Paramoti"},
        {"Pentecoste"},
        {"Pereiro"},
        {"Pindoretama"},
        {"Poranga"},
        {"Porteiras"},
        {"Potiretama"},
    };

    for (int i = 0; i<31; i++) {
        insereCidade(ha, cidades[i]);
    }
    imprimeColisao(ha);
    liberaHash(ha);

    return 0;
}