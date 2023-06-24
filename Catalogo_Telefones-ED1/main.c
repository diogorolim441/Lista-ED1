#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.c"
#include <time.h>

int validarDDD(int ddd);

// funcao responsavel por inserir os dados na tabela hash.
int inserir_ArvAVL_DDD(int ddd, Hash *ha, int numero) {
    clock_t start, end;
    double cpu_time_used;

    char nome[100];
    printf("Digite o nome: ");
    scanf(" %[^\n]s", nome);
    char endereco[100];
    printf("Digite o endereco: ");
   
    scanf(" %[^\n]s", endereco);
    

    struct dados pessoa;
    pessoa.numero = numero;
    strcpy(pessoa.nome, nome);
    strcpy(pessoa.endereco, endereco);
    
    if(validarDDD(ddd) == 1){
        start = clock(); // marca o início da contagem do tempo
        int inserePessoaTabelaHash = insereHash(ha, ddd, pessoa);
        end = clock(); // marca o fim da contagem do tempo
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calcula o tempo usado em segundos
        printf("\nTempo de execução: %.10lf segundos\n", cpu_time_used);
        if(inserePessoaTabelaHash == 1){
            
                    return 1;
        }
            
        else{
            return 0;
        }
    }

}

// funcao responsavel por buscar os dados de uma pessoa na tabela hash.
int busca_ArvAVL(Hash *ha, int ddd, int numero, ArvAVL *arv2) {
    int consultaHashListaArv = buscaHash(ha, ddd, arv2);
    if(consultaHashListaArv == 1) {
        clock_t start, end;
        double cpu_time_used;
        start = clock(); // marca o início da contagem do tempo
        int resultConsulta = consulta_ArvAVL(arv2, numero);
        end = clock(); // marca o fim da contagem do tempo
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calcula o tempo usado em segundos
        printf("\nTempo de execução: %.10lf segundos\n", cpu_time_used);
        if(resultConsulta == 1)
            return 1;
    }
    return 0;
}

// funcao responsavel por excluir uma pessoa da tabela hash
int excluiPessoa_ArvAVL(Hash *ha, int ddd, int numero, ArvAVL *arvExclusao) {
    clock_t start, end;
    double cpu_time_used;
    start = clock(); // marca o início da contagem do tempo
   
   
    int consultaHashListaArv = buscaHash(ha, ddd, arvExclusao);
    if(consultaHashListaArv == 1) {
        int resultAlturaAntes = altura_ArvAVL(arvExclusao);
        int resultExclusao = remove_ArvAVL(arvExclusao, numero);
        if(resultExclusao == 1) {
            end = clock(); // marca o fim da contagem do tempo
            printf("A altura da arvore antes da exclusao era: %d\n", resultAlturaAntes);
            int resultAlturaDepois = altura_ArvAVL(arvExclusao);
            printf("A altura da arvore depois da exclusao e: %d\n", resultAlturaDepois);
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calcula o tempo usado em segundos
            printf("\nTempo de execução: %.10lf segundos\n", cpu_time_used);
            return 1;
        }
    }
    return 0;
}

// funcao responsavel por imprimir os dados da pessoa escolhida em diferentes formas
int impressao_ArvAVL(Hash *ha, int ddd, ArvAVL *arv3){
    int consultaHashListaArv = buscaHash(ha, ddd, arv3);
    if (consultaHashListaArv == 1){
        int resposta;

        do{
            printf("Escolha uma opcao:\n");
            printf("1 - Pre-Ordem\n");
            printf("2 - Em-Ordem\n");
            printf("3 - Pos-Ordem\n");
            printf("4 - Sair\n");
            scanf(" %d", &resposta);

            switch (resposta){
            case 1:
                preOrdem_ArvAVL(arv3);
                break;

            case 2:
                emOrdem_ArvAVL(arv3);
                break;

            case 3:
                posOrdem_ArvAVL(arv3);
                break;
            
            default:
                printf("Digite uma opcao valida!\n");
                break;
            }
        }while(resposta != 4);
        
    }else{
        printf("Nao existem numeros cadastrados nesse DDD.\n");
    }
}

//Gerador dos numeros de telefones
int gerador_numero(){
    int i, n = 9; //para o primeiro digito ser 9;

	for (i=1; i < 9; i++){
        srand(rand()); //Gera um valor aleatoria que serve como inicial para a funcao rand() do for.
		n = n * 10; //Adiciona um 0 ao numero para concaternar com os novos numeros gerados.
		n += rand() % 9; // gera os numeros no intervalo de 0 a 9.
	}

	return n;   
}

// funcao que gera numeros de telefone validos e que n estejam cadastrados no sistema ainda
int* gerar_telefones(ArvAVL *arv, int ddd){
    int* numero = malloc(3 * sizeof(int));
    int i;

    printf("Sugestao de numeros: \n");
    if(arv == NULL) {
        for(i = 0; i < 3; i++){
            numero[i] = gerador_numero();
            printf("  %d - %d\n", i+1, numero[i]);
        }
        return numero;
    }else {
        for(i = 0; i < 3; i++){
            numero[i] = gerador_numero();
            int res = consulta_ArvAVL(arv, numero[i]);

            if(res == 1){ 
                numero[i] = gerador_numero();
            }else{
                printf("  %d - %d\n", i+1, numero[i]);
            }
        }
        return numero;
    }
}

// funcao para validar ddd
int validarDDD(int ddd) {
    if(ddd == 11 || ddd == 12 || ddd == 13 || ddd == 14 || ddd == 15 || ddd == 16 || ddd == 17 || ddd == 18 || ddd == 19 || ddd == 21 || ddd == 22 || ddd == 24 || ddd == 27 || ddd == 28|| ddd == 31 || ddd == 32 || ddd == 33 || ddd == 34 || ddd == 35 || ddd == 37 || ddd == 38 || ddd == 41 || ddd == 42 || ddd == 43 || ddd == 44 || ddd == 45 || ddd == 46 || ddd == 47 || ddd == 48 || ddd == 51 || ddd == 53 || ddd == 54 || ddd == 55 || ddd == 61 || ddd == 62 || ddd == 63 || ddd == 64 || ddd == 65 || ddd == 66 || ddd == 67 || ddd == 68 || ddd == 69 || ddd == 71 || ddd == 73 || ddd == 74 || ddd == 75 || ddd == 77 || ddd == 79 || ddd == 81 || ddd == 82 || ddd == 83 || ddd == 84 || ddd == 85 || ddd == 86 || ddd == 87 || ddd == 88 || ddd == 89 || ddd == 91 || ddd == 92 || ddd == 93 || ddd == 94 || ddd == 95 || ddd == 96 || ddd == 97 || ddd == 98 || ddd == 99) {
        return 1;
    }
    return 0;
}

// funcao que gera uma lista ordenada por numero e nome dos dados cadastrados no sistema
void gerarListaTabelaHash(Hash *ha) {
    int opcao;
    do{
        printf("Gerar lista ordenada por: \n");
        printf("1 - Numero\n");
        printf("2 - Nome\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
            {
                clock_t start, end;
                double cpu_time_used;
                start = clock(); // marca o início da contagem do tempo

                imprimirTabelaOrdenadaNumero(1427, ha);

                end = clock(); // marca o fim da contagem do tempo
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calcula o tempo usado em segundos
                printf("\nTempo de execução: %.10lf segundos\n", cpu_time_used);
                break;
            }
            case 2:
            {
                clock_t start, end;
                double cpu_time_used;
                start = clock(); // marca o início da contagem do tempo

                imprimirTabelaOrdenadaNome(1427, ha);

                end = clock(); // marca o fim da contagem do tempo
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calcula o tempo usado em segundos
                printf("\nTempo de execução: %.10lf segundos\n", cpu_time_used);
                break;
            }
            case 3:
            {
                break;
            }

            default:
                printf("Escolha uma opcao valida.\n");
                break;
        }
    }while(opcao != 3);
}

// funcao que gera telefones e o usuario escolho um deles para cadastrar no sistema
int inserirNumeroAleatorio(Hash *ha, int ddd) {
    ArvAVL *arv6 = cria_ArvAVL();
    int* telefone = malloc(3 * sizeof(int));

    buscaHash(ha, ddd, arv6);
    int op = 1;
    do{
        telefone = gerar_telefones(arv6, ddd);
        printf("\n");
        printf("Gostaria de cadastrar algum dos numeros?\n");
        printf("  1 - Sim\n");
        printf("  2 - Gerar novos numeros\n");
        printf("  3 - Sair\n");
        scanf(" %d", &op);

        switch(op){
            case 1:
            {
                int n;
                printf("\n");
                printf("Escolha um dos numeros gerados:\n");
                for(int i = 0; i < 3; i++){
                    printf("  %d - %d\n", i+1, telefone[i]);
                }
                scanf(" %d", &n);

                int telefone2 = telefone[n-1];
                return telefone2;
            }
            break;

            case 2:
                op = 2;
            break;

            case 3:
                printf("Saindo...");
            break;

            default:
                printf("Opcao selecionada nao e valida\n");
        }
    }while(op == 2);
}

int main(){
    
    Hash *ha = criaHash(1427);
    int escolha;
    printf("Bem vindo ao Catalogo Nacional de Telefones e Enderecos\n");

    do{
        printf("Escolha a opcao que voce deseja escolher: \n");
        printf("1 - Inserir uma pessoa no catalogo\n");
        printf("2 - Buscar pessoa no catalogo pelo telefone\n");
        printf("3 - Remover pessoa do catalogo\n");
        printf("4 - Listar todos os numeros de telefone por DDD\n");
        printf("5 - Gerar lista telefonica por DDD\n");
        printf("6 - Sair\n");
        scanf(" %d", &escolha);

        switch(escolha) {
            case 1:
            {
                int ddd, numero, escolhaNumero;
                printf("Digite o numero do DDD da pessoa a ser inserida: \n");
                scanf(" %d", &ddd);
                int resultDDD = validarDDD(ddd);
                if(resultDDD != 1) {
                    printf("Digite um DDD valido\n");
                    break;
                }
                do{
                    printf("Voce deseja digitar o numero ou escolher um numero que ainda nao esteja cadastrado no programa?\n");
                    printf("1 - Digitar um numero\n");
                    printf("2 - Escolher um numero gerado\n");
                    scanf("%d", &escolhaNumero);
                    switch(escolhaNumero) {
                        case 1:
                            printf("Digite o numero do telefone: ");
                            scanf(" %d", &numero);
                            break;
                        
                        case 2:
                            numero = inserirNumeroAleatorio(ha, ddd);
                            break;

                        default:
                            printf("Opcao invalida, tente novamente!\n");
                            break;
                    }
                    
                    
                }while(escolhaNumero != 1 && escolhaNumero != 2);
                
                int resultInserir = inserir_ArvAVL_DDD(ddd, ha, numero);
                
                if(resultInserir == 1) {
                    
                    printf("Pessoa inserida com sucesso!\n");
                                   
                }else{
                    printf("Erro ao inserir pessoa!\n");
                }
                break;
            }

            case 2:
            {
                int numero, ddd;
                ArvAVL *arv2 = cria_ArvAVL();
                printf("Digite o DDD do telefone da pessoa a ser buscada: \n");
                scanf(" %d", &ddd);
                int resultDDD = validarDDD(ddd);
                if(resultDDD != 1) {
                    printf("Digite um DDD valido\n");
                    break;
                }
                printf("Digite o numero do telefone da pessoa a ser buscada: \n");
                scanf(" %d", &numero);
                int resultBusca = busca_ArvAVL(ha, ddd, numero, arv2);
                if(resultBusca != 1) {
                    printf("Pessoa nao esta cadastrada no catalogo\n");
                    break;
                }
                break;
            }

            case 3:
            {
                int numero, ddd;
                ArvAVL *arvExclusao = cria_ArvAVL();
                printf("Digite o DDD do telefone da pessoa a ser buscada: \n");
                scanf(" %d", &ddd);
                int resultDDD = validarDDD(ddd);
                if(resultDDD != 1) {
                    printf("Digite um DDD valido\n");
                    break;
                }
                printf("Digite o numero do telefone da pessoa a ser buscada: \n");
                scanf(" %d", &numero);
                int resultExclusao = excluiPessoa_ArvAVL(ha, ddd, numero, arvExclusao);
                if(resultExclusao != 1) {
                    printf("Pessoa nao esta cadastrada no catalogo\n");
                    break;
                }
                printf("Pessoa removida com sucesso!\n");
                break;
            }
            

            case 4:
            {
                int ddd;
                ArvAVL *arv4 = cria_ArvAVL();

                printf("Digite o numero do DDD:\n");
                scanf(" %d", &ddd);
                int resultDDD = validarDDD(ddd);
                if(resultDDD != 1) {
                    printf("Digite um DDD valido\n");
                    break;
                }
                impressao_ArvAVL(ha, ddd, arv4);
                break;
            }

            case 5:
            {
                gerarListaTabelaHash(ha);
                break;
            }

            case 6:
                printf("Saindo...\n");
            break;

            default:
                printf("Opcao selecionada nao e valida\n");
        }
        printf("\n\n");
    } while(escolha != 6);
    return 0;
}