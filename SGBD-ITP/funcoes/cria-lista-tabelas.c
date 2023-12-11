#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>


typedef struct{
	char nome[15];
	char tDado[7];
} dadosT;

int criaTab(FILE *doc){

	int c = 1, chave = 0, coluna = 1, qColunas = 0; //c == Condição
	char cPrimaria[15];
	dadosT tabela;

	char nTabela[30];
	printf("\nNome da tabela:");
	scanf("%s", nTabela);

    char nomeDoc[30] = "tb_";
	strcat(nomeDoc, nTabela);
	strcat(nomeDoc, ".txt");

    char caminhoDoc[100] = "documentos/";
	strcat(caminhoDoc, nomeDoc);

	FILE *documento = fopen(caminhoDoc, "w");

	if(documento==NULL){
		system("clear");
		printf("\nERRO! Não foi possível abrir o arquivo!\n");
		return 0;
	} else {
		printf("\nNome da coluna da chave primária: ");
		scanf("%s", cPrimaria);
		//printf("Valor da chave: \n");
		fprintf(documento, "%s ", cPrimaria);
		
		//colunas
		printf("\nQuantidade de colunas: ");
		scanf("%d", &qColunas);

		printf("Nome da 1º coluna: %s\n", cPrimaria);
		for(int i=1; i<=qColunas; i++){
			printf("Nome da %d coluna: ", i+1);
			scanf("%s", tabela.nome);
			fprintf(documento, "%s ", tabela.nome);
		}

		chave++;
		fprintf(documento, "\n%d ", chave);

		for(int i=1; i<=qColunas; i++){
			printf("\n %d Coluna: \n", i+1);

			printf("Insira o tipo de dados: ");
			scanf(" %s", tabela.tDado);

			if(!strcmp(tabela.tDado, "string")){ //Caso o tipo de dados inserido seja uma String

				char vs[25]; //vs = Valor de String
				printf("Valor do String: ");
				scanf("%sS", vs);

				fprintf(documento, "%s ", vs);
			}

			else if(!strcmp(tabela.tDado, "float")){ //Caso o tipo de dados inserido seja Float
				float vf; //vf = Valor do Float
				do{
					printf("Valor do Float: ");
					scanf("%f", &vf);

					if(vf<=chave){
						printf("\nERRO! Você inseriu o mesmo valor da Chave. Tente novamente.\n");
					}

				} while(vf<=chave);

				fprintf(documento, "%.2f ", vf);
			}

			else if(!strcmp(tabela.tDado, "int")){ // Caso o tipo de dados inserido seja Int
				int vi; //vi = Valor do Int
				do{
					printf("Valor do Int: ");
					scanf("%d", &vi);

					if(vi<=chave){
						printf("\nERRO! Você inseriu o mesmo valor da Chave. Tente novamente.\n");
					}

				} while(vi<=chave);

				fprintf(documento, "%d ", vi);
			}

			else if(!strcmp(tabela.tDado, "char")){ //Caso o tipo de dados inserido seja Char
				char vc; //vc = Valor do Char
				printf("Valor do Char: ");
				scanf("%s", &vc);

				fprintf(documento, "%c ", vc);
			}

			else if(!strcmp(tabela.tDado, "double")){ //Caso o tipo de dados inserido seja Double
				double vd; //vd = Valor do Double
				do{
					printf("Valor do Double: ");
					scanf("%lf", &vd);

					if(vd<=chave){
						printf("\nERRO! Você inseriu o mesmo valor da Chave. Tente novamente.\n");
					}

				} while(vd<=chave);

				fprintf(documento, "%.2lf ", vd);
			} else {
				printf("ERRO!Tipo de dados inválido. Padrão: NULL\n");
				fprintf(documento, "NULL ");
			}
		}
		fprintf(documento, "\n");

	system("clear");
	printf("\n A %s foi criada.\n", nomeDoc);
	}

	fclose(documento);
	return 1;
}

int listaTabelas(FILE *doc){
	int c = 0;
	struct dirent *entrada;
	DIR *dir;

	dir = opendir("documentos");

	if(dir==NULL){
		system("clear");
		printf("\nERRO! Não foi possível abrir o diretório!\n");
		return 0;
	}

	system("clear");
	printf("\nTabelas:\n");

	while(entrada = readdir(dir)){
		c++;
		if(c>=1){
			printf("%s\n", entrada-> d_name);
		}
	}

	if(c==2){
		printf("\nNão há tabelas cadastradas o sistema.\n"); //Se a quantidade do contador for 2 significa que não há tabelas cadastradas no sistema.
	}

	closedir(dir);
	return 1;
}