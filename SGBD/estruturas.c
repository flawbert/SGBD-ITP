// estruturas.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

void salvarTabela(const Tabela *todasTabelas, int todasTabelas_size, const char *nomeTabela) {

    // Procurar a tabela pelo nome
    int tabelaIndex = -1;
    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeTabela) == 0) {
            tabelaIndex = i;
            break;
        }
    }

    if (tabelaIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }


    char nomeArquivo[100];
    strcpy(nomeArquivo, nomeTabela);
    // printf("Digite o nome do arquivo .txt que será criado: ");
    // scanf(" %[^\n]", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // Escrever os nomes das colunas no arquivo
    for (int i = 0; i < todasTabelas[tabelaIndex].nCol; i++) {
        fprintf(arquivo, "%s \t|", todasTabelas[tabelaIndex].nomesColunas[i]);
    }
    fprintf(arquivo, "\n");

    // Escrever os valores das colunas no arquivo
    for (int i = 0; i < todasTabelas[tabelaIndex].numeroLinhas; i++) {
        for (int j = 0; j < todasTabelas[tabelaIndex].nCol; j++) {
            // verificamos o tipo de cada coluna para printar o valor
            switch (todasTabelas[tabelaIndex].tiposColunas[j]) {
                case 1: // int
                    fprintf(arquivo, "%d \t|", *(int *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 2: // float
                    fprintf(arquivo, "%.2f \t|", *(float *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 3: // char
                    fprintf(arquivo, "%c \t|", *(char *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 4: // string
                    fprintf(arquivo, "%s \t|", (char *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                default:
                    // Handle unknown data type
                    break;
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Tabela salva com sucesso no arquivo %s.\n", nomeArquivo);
}

void exibirValorFormatado(const Tabela tabela, int linha, int coluna) {
    switch (tabela.tiposColunas[coluna]) {
        case 1: // int
            printf("%d \t|", *(int *)tabela.listaValores[linha][coluna]);
            break;
        case 2: // float
            printf("%.2f \t|", *(float *)tabela.listaValores[linha][coluna]);
            break;
        case 3: // char
            printf("%c \t|", *(char *)tabela.listaValores[linha][coluna]);
            break;
        case 4: // string
            printf("%s \t|", (char *)tabela.listaValores[linha][coluna]);
            break;
        default:
            // Lidar com outros tipos, se necessário
            break;
    }
}

void pesquisarStrings(const Tabela tabela, int coluna, const char *valor) {
    // Verificar se a coluna é do tipo string
    if (tabela.tiposColunas[coluna] != 4) {
        printf("A pesquisa de entrada se aplica apenas a colunas do tipo string.\n");
        return;
    }

    // Percorrer as linhas da tabela
    for (int i = 0; i < tabela.numeroLinhas; i++) {
        const char *valorNaColuna = (const char *)tabela.listaValores[i][coluna];

        // Verificar se o valor na coluna contém a entrada
        if (strstr(valorNaColuna, valor) != NULL) {
            // Imprimir toda a linha
            for (int j = 0; j < tabela.nCol; j++) {
                exibirValorFormatado(tabela, i, j);
            }
            printf("\n");
        }
    }
}

