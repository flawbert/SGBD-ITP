//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcao pesquisar valor em uma tabela
int pesquisar_valor(FILE *arq){
	int op, op_coluna;
	int valor_maior = 0, valor_maior_igual = 0, valor_igual = 0, valor_menor = 0, valor_menor_igual = 0, valor_proximo = 0;

	char c1[10], c2[10], c3[10], c4[10];

	//nome tabela
	char nome_tabela[20];
	printf("\nInsira o nome da tabela para realizar a busca: \n");
	scanf("%s", nome_tabela);

	//nome padrao para o arquivo da tabela
	char nome_arquivo[20] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");

	if(arquivo==NULL){
		printf("Opa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		printf("\nColunas disponiveis:\n");
		rewind(arquivo);
		fscanf(arquivo, "%s %s %s %s", c1, c2, c3, c4);

		printf("1.%s \n2.%s \n3.%s \n4.%s \n\nEscolha uma opcao: ", c1, c2, c3, c4);

		do {
			scanf("%d", &op_coluna);

			if(op_coluna>4 || op_coluna<1){
				printf("\nOpcao invalida! Tente novamente: ");
			}

		} while(op_coluna>4 || op_coluna<1);

		printf("\nOpcoes disponiveis para busca:\n");
		printf("1. valores maior que o valor informado\n");
		printf("2. valores maior ou igual quer o valor informado\n");
		printf("3. valores igual o valor informado\n");
		printf("4. valores menor que o valor informado\n");
		printf("5. valores menor ou igual que o valor informado\n");
		printf("6. valores proximo ao valor informado [se aplica apenas se a coluna for do tipo string]\n");

		printf("\nInforme a opcao: ");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_maior);
				break;

				//fazer busca
			case 2:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_maior_igual);
				break;

				//fazer busca
			case 3:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_igual);
				break;

				//fazer busca			
			case 4:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_menor);
				break;

				//fazer busca
			case 5:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_menor_igual);
				break;

				//fazer busca
			case 6:
				printf("\nInforme o valor para a busca:\n");
				scanf("%d", &valor_proximo);
				break;

				//fazer busca

			default:
				system("clear");
				printf("\nOpa! Opcao invalida!\n");
		}
	}
}