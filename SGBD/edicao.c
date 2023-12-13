// edicao.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edicao.h"
#include "estruturas.h"
#include "visualizacao.h"

//todasTabelas_size: índice de todas tabelas criadas, usada no loop para contar a quantidade de tabelas. Um ponteiro que representa o tamanho de todas as tabelas. Inicia-se no 0.

void editarValorTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            // Encontrou a tabela, agora solicita os valores
            int id;
            printf("Digite o valor da primary key [%s]: ", todasTabelas[i].nomesColunas[0]);
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

            char nomeColuna[100];
            printf("Digite o nome da coluna que deseja editar: ");
            scanf(" %[^\n]", nomeColuna);

            // Encontrar a coluna correspondente ao nome fornecido
            int coluna = -1;
            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                if (strcmp(todasTabelas[i].nomesColunas[j], nomeColuna) == 0) {
                    coluna = j;
                    break;
                }
            }

            if (coluna == -1) {
                printf("Coluna não encontrada na tabela.\n");
                return;
            }

            // Solicitar o novo valor
            switch (coluna) {
                case 0: // Coluna ID (pode ser de qualquer tipo)
                    printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                    scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][coluna]);
                    break;
                default:
                    // Editar valores de acordo com o tipo da coluna
                    switch (todasTabelas[i].tiposColunas[coluna]) {
                        case 1: // int
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf("%d", (int *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 2: // float
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf("%f", (float *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 3: // char
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf(" %c", (char *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 4: // string
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        default:
                            // Tratar outros tipos de coluna aqui, se necessário
                            break;
                    }
                    break;
            }
            
            salvarTabela(todasTabelas, todasTabelas_size, nomeDaTabela);
            printf("Valor editado com sucesso.\n");
            return;
        }
    }

    printf("Tabela não encontrada.\n");
}

void editarNomeTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            char novoNome[100];
            printf("Digite o novo nome da tabela: ");
            scanf(" %[^\n]", novoNome);
            strcpy(todasTabelas[i].nomeTabela, novoNome);
            break;
        }
    }
}