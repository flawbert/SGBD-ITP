#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pesquisaV(FILE *doc){
	int op, op_cl;
	int maior = 0, vIgual = 0, vMenor = 0, vProximo = 0;

	char c1[10], c2[10], c3[10], c4[10];

	//nome tabela
	char nomeTb[20];
	printf("\nNome da tabela (que será realizada a busca): \n");
	scanf("%s", nomeTb);

	char nomeDoc[20] = "tb_";
	strcat(nomeDoc, nomeTb);
	strcat(nomeDoc, ".txt");

	//Path
	char caminhoDoc[100] = "documentos/";
	strcat(caminhoDoc, nomeTb);

	FILE *documento = fopen(caminhoDoc, "w");

	if(documento==NULL){
		printf("ERRO! Não foi possível abrir o arquivo!\n");
		return 0;
	} else {
		printf("\nColuna:\n");
		rewind(documento);
		fscanf(documento, "%s %s %s %s", c1, c2, c3, c4);

		printf("1.%s \n2.%s \n3.%s \n4.%s \n\nOpção: ", c1, c2, c3, c4);

		do {
			scanf("%d", &op_cl);

			if(op_cl>4 || op_cl<1){
				printf("\nERRO NA OP! Tente novamente: ");
			}

		} while(op_cl>4 || op_cl<1);

		printf("\nOpções de Busca: \n");
		printf("1. Valores maiores que o informado.\n");
		printf("2. Valores iguais ao informado.\n");
		printf("3. Valores menores que o informado.\n");
		printf("4. Valores próximos ao informado. (Se aplica a colunas do tipo String)\n");

		printf("\nOpção: ");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("\nValor para a busca::\n");
				scanf("%d", &maior);
				break;

			case 2:
				printf("\nValor para a busca\n");
				scanf("%d", &vIgual);
				break;

			case 3:
				printf("\nValor para a busca:\n");
				scanf("%d", &vMenor);
				break;

			case 4:
				printf("\nValor para a busca:\n");
				scanf("%d", &vProximo);
				break;

			default:
				system("clear");
				printf("\nERRO! Opção inválida.\n");
		}
	}
}