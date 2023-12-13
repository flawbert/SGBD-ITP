// visualizacao.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visualizacao.h"
#include "estruturas.h"

void mostrarTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
            printf("====================================================\n");

            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                printf("%s \t", todasTabelas[i].nomesColunas[j]);
            }

            printf("\n");
            printf("----------------------------------------------------\n");

            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                for (int k = 0; k < todasTabelas[i].nCol; k++) {
                    // verificamos o tipo de cada coluna para printar o valor
                    exibirValorFormatado(todasTabelas[i], j, k);
                }
                printf("\n");
            }

            break;
        }
    }
}


void mostarTodas(Tabela *todasTabelas, int todasTabelas_size) {
    printf("Todas as tabelas:\n");
    for (int i = 0; i < todasTabelas_size; i++) {
        printf("%d - %s\n", i+1,todasTabelas[i].nomeTabela);
    }
}

void pesquisaValor(Tabela *todasTabelas, int todasTabelas_size){
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    // mostra o nome de todas as colunas da tabela
    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            printf("Colunas da tabela %s:\n", todasTabelas[i].nomeTabela);
            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                printf("%d - %s\n", j+1,todasTabelas[i].nomesColunas[j]);
            }
        }
    }

    char nomeColuna[100];
    printf("\nDigite o nome da coluna: ");
    scanf(" %[^\n]", nomeColuna);

    // Encontrar a coluna correspondente ao nome fornecido
    int coluna = -1;
    for (int j = 0; j < todasTabelas[0].nCol; j++) {
        if (strcmp(todasTabelas[0].nomesColunas[j], nomeColuna) == 0) {
            coluna = j;
            break;
        }
    }
    if (coluna == -1) {
        printf("Coluna não encontrada na tabela.\n");
        return;
    }

    printf("Buscas\n");
    printf("1 - Valores maior que o informado\n");
    printf("2 - Valores maior ou igual que o informado\n");
    printf("3 - Valores igual ao informado\n");
    printf("4 - Valores menor que o informado\n");
    printf("5 - Valores menor ou igual que o informado\n");
    printf("6 - Valores proximos ao informado (apenas para colunas de strings)\n");
    printf("\n");

    int opColuna;
    printf("Digite a opcao desejada: ");
    scanf("%d", &opColuna);
    if (opColuna < 1 || opColuna > 6) {
        printf("Opção inválida.\n");
        return;
    }


    // primeira opcao de pesquisa
    if (opColuna == 1) {
        int valor;
        printf("Digite o valor para a pesquisa: ");
        scanf("%d", &valor);
        printf("\nEntradas maiores que %d na coluna %s\n", valor, nomeColuna);

        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao maiores que o valor informado
                for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                    if (*((int *)todasTabelas[i].listaValores[j][coluna]) > valor) {
                        for (int k = 0; k < todasTabelas[i].nCol; k++) {
                            // verificamos o tipo de cada coluna para printar o valor
                            exibirValorFormatado(todasTabelas[i], j, k);
                        }
                        printf("\n");
                    }
                }
                
            }
        }            
    }
    else if(opColuna == 2){
        int valor;
        printf("Digite o valor para a pesquisa: ");
        scanf("%d", &valor);
        printf("\nEntradas maiores ou iguais que %d na coluna %s\n", valor, nomeColuna);

        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao maiores ou iguais que o valor informado
                for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                    if (*((int *)todasTabelas[i].listaValores[j][coluna]) >= valor) {
                        for (int k = 0; k < todasTabelas[i].nCol; k++) {
                            // verificamos o tipo de cada coluna para printar o valor
                            exibirValorFormatado(todasTabelas[i], j, k);
                        }
                        printf("\n");
                    }
                }
                
            }
        }            
    }
    else if (opColuna == 3){
        int valor;
        printf("Digite o valor para a pesquisa: ");
        scanf("%d", &valor);
        printf("\nEntradas iguais a %d na coluna %s\n", valor, nomeColuna);

        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao iguais que o valor informado
                for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                    if (*((int *)todasTabelas[i].listaValores[j][coluna]) == valor) {
                        for (int k = 0; k < todasTabelas[i].nCol; k++) {
                            // verificamos o tipo de cada coluna para printar o valor
                            exibirValorFormatado(todasTabelas[i], j, k);
                        }
                        printf("\n");
                    }
                }
                
            }
        }            
    }
    else if (opColuna == 4){
        int valor;
        printf("Digite o valor para a pesquisa: ");
        scanf("%d", &valor);
        printf("\nEntradas menores que %d na coluna %s\n", valor, nomeColuna);

        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao menores que o valor informado
                for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                    if (*((int *)todasTabelas[i].listaValores[j][coluna]) < valor) {
                        for (int k = 0; k < todasTabelas[i].nCol; k++) {
                            // verificamos o tipo de cada coluna para printar o valor
                            exibirValorFormatado(todasTabelas[i], j, k);
                        }
                        printf("\n");
                    }
                }
                
            }
        }            
    }
    else if (opColuna == 5){
        int valor;
        printf("Digite o valor para a pesquisa: ");
        scanf("%d", &valor);
        printf("\nEntradas menores ou iguais que %d na coluna %s\n", valor, nomeColuna);

        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao menores ou iguais que o valor informado
                for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                    if (*((int *)todasTabelas[i].listaValores[j][coluna]) <= valor) {
                        for (int k = 0; k < todasTabelas[i].nCol; k++) {
                            // verificamos o tipo de cada coluna para printar o valor
                            exibirValorFormatado(todasTabelas[i], j, k);
                        }
                        printf("\n");
                    }
                }
                
            }
        }            
    }
    else if (opColuna == 6){
        char valor[100];
        printf("Digite o valor para a pesquisa: ");
        scanf(" %[^\n]", valor);
        printf("\nEntradas proximas a '%s' na coluna '%s'\n", valor, nomeColuna);
        
        for (int i = 0; i < todasTabelas_size; i++) {
            if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
                printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
                printf("====================================================\n");

                for (int j = 0; j < todasTabelas[i].nCol; j++) {
                    printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
                }

                printf("\n");
                printf("----------------------------------------------------\n");

                // print todas as linhas em que os valores da coluna escolhida sao proximos ao valor informado
                pesquisarStrings(todasTabelas[i], coluna, valor);     
            }
        }            
    } 
    
}

