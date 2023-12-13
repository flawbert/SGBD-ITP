// exclusao.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exclusao.h"
#include "estruturas.h"
#include "visualizacao.h"

// funcao para apagar o arquivoi.txt de uma tabela do computador apartir do seu nome
void apagarArquivo(char *nomeTabela) {
    char nomeArquivo[100];
    strcpy(nomeArquivo, nomeTabela);

    if (remove(nomeArquivo) == 0) {
        printf("Arquivo %s apagado com sucesso.\n", nomeArquivo);
    } else {
        printf("Erro ao apagar o arquivo %s.\n", nomeArquivo);
    }
}

void deletarTabela(Tabela *todasTabelas, int *todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);
    apagarArquivo(nomeDaTabela);
}

void deletarLinha(Tabela *todasTabelas, int todasTabelas_size){
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            // Encontrou a tabela, agora solicita os valores
            int id;
            printf("Digite o valor da primeira coluna (ID): ");
            scanf("%d", &id);

            // Encontrar a linha correspondente ao ID fornecido
            int linha = -1;
            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (*((int *)todasTabelas[i].listaValores[j][0]) == id) {
                    linha = j;
                    break;
                }
            }

            if (linha == -1) {
                printf("ID não encontrado na tabela.\n");
                return;
            }

            for (int j = linha; j < todasTabelas[i].numeroLinhas - 1; j++) {
                todasTabelas[i].listaValores[j] = todasTabelas[i].listaValores[j + 1];
            }
            todasTabelas[i].numeroLinhas--;
            printf("Linha deletada com sucesso.\n");
            break;
        }
    }

    salvarTabela(todasTabelas, todasTabelas_size, nomeDaTabela);

}

