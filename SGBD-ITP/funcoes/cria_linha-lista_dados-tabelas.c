#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[15];
    char tDado[7];
} dadosTb;

int criaLTb(FILE *doc) {
    int cond = 1, // Condição
        chave = 0,
        qColunas = 0;

    dadosTb tabela;

    char c, quebra = '\n';
    int l = 0; // Quantidade de linhas da tabela

    char txt[250];
    char *temp = 0;
    char **resul = 0;
    unsigned int tam = 0; // valor inteiro-sem-sinal, onde tam = tamanho

    char nomeTB[20];
    printf("\nNome da tabela: ");
    scanf("%s", nomeTB);

    char nomeDoc[20] = "tb_";
    strcat(nomeDoc, nomeTB);
    strcat(nomeDoc, ".txt");

    char caminhoDoc[100] = "documentos/";
    strcat(caminhoDoc, nomeDoc);

    FILE *documento = fopen(caminhoDoc, "a+");

    if (documento == NULL) {
        system("clear");
        printf("\nERRO! Não foi possível abrir o arquivo.\n");
        return 0;
    } else {
        while (fread(&c, sizeof(char), 1, documento)) {
            if (c == quebra) {
                l++;
            }
        }

        rewind(documento);
        while (fgets(txt, 250, documento) != NULL) {
            printf("\nColunas:\n");

            temp = strtok(txt, " ");

            if (temp) {
                resul = malloc((tam + 1) * sizeof(char **));
                resul[tam++] = temp;
            }

            while ((temp = strtok(0, " ")) != 0) {
                resul = realloc(resul, (tam + 1) * sizeof(char **));
                resul[tam++] = temp;
            }

            // break para parar quando terminar de ler e alocar a primeira linha que é a linha das colunas
            break;
        }

        for (unsigned int i = 0; i < tam - 1; i++) {
            printf("%d. %s\n", i + 1, resul[i]);
        }

        // tirando 1 do valor do tamanho, pois ele incrementa 1 valor a mais
        qColunas = tam - 1;

        // Lembrete: a tabela da chave primária é AI, por isso insira valores para as outras colunas.

        do {
            int cont = 0;
            char str[1000];
            int ids[1000]; // As chaves cadastradas serão armazenadas em um vetor

            rewind(documento);
            while (fgets(str, 1000, documento) != NULL) {
                if (cont != 0) {
                    ids[cont - 1] = atoi(strcat(str, " "));
                }
                cont++;
            }

            fprintf(documento, "%d ", ids[cont - 2] + 1); // Definindo a chave primária automaticamente.

            for (int i = 1; i <= qColunas - 1; i++) {
                printf("\nColuna %d: \n", i + 1); // Definindo os valores presentes nas colunas.

                printf("Insira o tipo de dados: ");
                scanf("%s", tabela.tDado);

                if (!strcmp(tabela.tDado, "char")) {
                    char vc; // vc = Valor do Char.
                    printf("Valor do Char: ");
                    scanf(" %c", &vc); // Adicione um espaço antes de %c para ignorar espaços em branco.

                    fprintf(documento, "%c ", vc);
                } else if (!strcmp(tabela.tDado, "string")) {
                    char vs[25]; // vs = Valor do String
                    printf("Valor da String: ");
                    scanf("%s", vs);

                    fprintf(documento, "%s ", vs);
                } else if (!strcmp(tabela.tDado, "float")) {
                    float vf; // Valor do Float
                    do {
                        printf("Valor do Float: ");
                        scanf("%f", &vf);

                        if (vf <= chave) {
                            printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
                        }

                    } while (vf <= chave);

                    fprintf(documento, "%.2f ", vf);
                } else if (!strcmp(tabela.tDado, "int")) {
                    int vi; // vi = Valor do Int
                    do {
                        printf("Valor do Int: ");
                        scanf("%d", &vi);

                        if (vi <= chave) {
                            printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
                        }

                    } while (vi <= chave);

                    fprintf(documento, "%d ", vi);
                } else if (!strcmp(tabela.tDado, "double")) {
                    double vd; // Valor do Double
                    do {
                        printf("Valor do Double: ");
                        scanf("%lf", &vd);

                        if (vd <= chave) {
                            printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
                        }

                    } while (vd <= chave);

                    fprintf(documento, "%.2lf ", vd);
                } else {
                    printf("ERRO! Tipo de dados inválido. Padrão: NULL\n"); // NULL, caso Default
                    fprintf(documento, "NULL ");
                }
            }

            printf("\nDeseja adicionar mais uma tupla? (Linha) [1-Sim 0-Não]\n");
            scanf("%d", &cond); // Alterado para scanf("%d", &cond) para ler um inteiro.

            if (cond != 0 && cond != 1) {
                printf("ERRO! Selecione uma opção válida.");
                cond = 0;
            }
        } while (cond != 0);

        // Adicione uma nova linha após a última tupla
        fprintf(documento, "\n");
    }

    system("clear");
    printf("\nA %s foi atualizada.\n", nomeDoc);

    fclose(documento);
    return 1;
}

int listaDadosTB(FILE *doc) {
    char nomeTB[20];
    printf("\nNome da tabela: ");
    scanf("%s", nomeTB);

    char nomeDoc[20] = "tb_";
    strcat(nomeDoc, nomeTB);
    strcat(nomeDoc, ".txt");

    char caminhoDoc[100] = "documentos/";
    strcat(caminhoDoc, nomeDoc);

    FILE *documento;
    char caractere;

    // Abre o arquivo para leitura
    documento = fopen(caminhoDoc, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (documento == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Código de erro
    }

    // Lê e imprime o conteúdo do arquivo
    while ((caractere = fgetc(documento)) != EOF) {
        printf("%c", caractere);
    }

    fclose(documento);
}