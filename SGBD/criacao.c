// criacao.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criacao.h"
#include "estruturas.h"
#include "visualizacao.h"

// ** - cria array de duas dimensões, *** - cria array de três dimensões.

void criarTabela(Tabela **todasTabelas, int *todasTabelas_size) {
    char nome[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nome);
    
   // se o nome da tabela já existir,pedir pra escrever outro nome
    for (int i = 0; i < *todasTabelas_size; i++) {
        if (strcmp((*todasTabelas)[i].nomeTabela, nome) == 0) {
            printf("Nome da tabela já existe, digite outro nome\n");
            scanf(" %[^\n]", nome);
            i = -1;
        }
    }

    int nCol;
    printf("Quantidade de colunas: ");
    scanf("%d", &nCol);


    // criar uma coluna fixa para o id
    nCol++;

    char **nomesColunas = (char **)malloc(nCol * sizeof(char *));

    int *tiposColunas = (int *)malloc(nCol * sizeof(int));


    for (int i = 0; i < nCol; i++) {
        nomesColunas[i] = (char *)malloc(100 * sizeof(char));
        if (i == 0) {
            printf("Digite o nome da Primary key(int): ");
            scanf(" %[^\n]", nomesColunas[0]);
            tiposColunas[0] = 1;
            continue;
        }
        printf("Digite o nome da coluna %i: ",i);
        scanf(" %[^\n]", nomesColunas[i]);
        printf("Digite o tipo da coluna (1 - int, 2 - float, 3 - char, 4 - string): ");
        scanf("%d", &tiposColunas[i]);
    }

    //char ***valoresColunas = (char ***)malloc(sizeof(char **) * 100);
    int numeroLinhas;
    printf("Digite o numero de entradas(linhas): ");
    scanf(" %d", &numeroLinhas);

    void ***valoresColunas = (void ***)malloc(sizeof(void **) * numeroLinhas);

    for (int i = 0; i < numeroLinhas; i++) {
        valoresColunas[i] = (void **)malloc(sizeof(void *) * nCol);
        for (int j = 0; j < nCol; j++) {
            // Alocar memória de acordo com o tipo de dados.
            switch (tiposColunas[j]) {
                case 1: // int
                    valoresColunas[i][j] = (int *)malloc(sizeof(int));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf("%d", (int *)valoresColunas[i][j]);
                    break;
                case 2: // float
                    valoresColunas[i][j] = (float *)malloc(sizeof(float));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf("%f", (float *)valoresColunas[i][j]);
                    break;
                case 3: // char
                    valoresColunas[i][j] = (char *)malloc(sizeof(char));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf(" %c", (char *)valoresColunas[i][j]);
                    break;
                case 4: // string
                    valoresColunas[i][j] = (char *)malloc(100 * sizeof(char));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf(" %[^\n]", (char *)valoresColunas[i][j]);
                    break;
                default:
                    // Handle unknown data type
                    break;
            }
        }
    }

    Tabela *nova = (Tabela *)malloc(sizeof(Tabela));
    nova->nomeTabela = strdup(nome);
    nova->nCol = nCol;
    nova->numeroLinhas = numeroLinhas;
    nova->nomesColunas = nomesColunas;
    nova->listaValores = (void ***)valoresColunas;
    nova->tiposColunas = tiposColunas;

    *todasTabelas = (Tabela *)realloc(*todasTabelas, sizeof(Tabela) * (*todasTabelas_size + 1));
    (*todasTabelas)[*todasTabelas_size] = *nova;
    (*todasTabelas_size)++;

    salvarTabela(*todasTabelas, *todasTabelas_size, nome);

    printf("Tabela criada com sucesso.\n");
}

void criarLinha(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            // Encontrou a tabela, agora solicita os valores
            int id;

            printf("Digite o valor da Primary key[%s]): ", todasTabelas[i].nomesColunas[0]);
            scanf("%d", &id);

            // Verificar se a primary key já existe
            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (*((int *)todasTabelas[i].listaValores[j][0]) == id) {
                    printf("Já existe uma linha com a Primary key fornecida.\n");
                    return;
                }
            }

            // A Primary key não existe, então criamos uma nova linha
            todasTabelas[i].numeroLinhas++;

            // Alocar memória para a nova linha
            todasTabelas[i].listaValores = (void ***)realloc(todasTabelas[i].listaValores,
                                                 sizeof(void **) * todasTabelas[i].numeroLinhas);

            int linha = todasTabelas[i].numeroLinhas - 1;
            todasTabelas[i].listaValores[linha] = (void **)malloc(todasTabelas[i].nCol * sizeof(void *));
            
            // preencha o valor do IDcoluna 0 com o valor fornecido
            todasTabelas[i].listaValores[linha][0] = (void *)malloc(sizeof(int));
            *((int *)todasTabelas[i].listaValores[linha][0]) = id;

            // Preencher os valores para cada coluna de acordo com o tipo de dado
            for (int k = 1; k < todasTabelas[i].nCol; k++) {
                switch (todasTabelas[i].tiposColunas[k]) {
                    case 1: // int
                        todasTabelas[i].listaValores[linha][k] = (void *)malloc(sizeof(int));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf("%d", (int *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 2: // float
                        todasTabelas[i].listaValores[linha][k] = (void *)malloc(sizeof(float));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf("%f", (float *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 3: // char
                        todasTabelas[i].listaValores[linha][k] = (char *)malloc(sizeof(char));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf(" %c", (char *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 4: // string
                        todasTabelas[i].listaValores[linha][k] = (char *)malloc(100 * sizeof(char));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    default:
                        // Lida com tipos de dados desconhecidos
                        break;
                }
            }
            salvarTabela(todasTabelas, todasTabelas_size, nomeDaTabela);
            printf("Linha criada com sucesso.\n");
            return;
        }
    }

    // Se chegou aqui, a tabela não foi encontrada
    printf("Tabela não encontrada.\n");
}