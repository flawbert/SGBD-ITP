#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[15];
	char tDado[7];
} dadosTb;

int criaLTb(FILE *doc){

	int cond = 1, //Condição
	chave = 0,
	qColunas = 0;
	
	dadosTb tabela;

	char c, quebra = '\n'; 
	int l = 0; // Quantidade de linhas da tabela

	char txt[250];
	char* temp = 0;
	char** resul = 0;
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

	if(documento==NULL){
		system("clear");
		printf("\nERRO! Não foi possível abrir o arquivo.\n");
		return 0;
	} else {	
		while(fread(&c, sizeof(char), 1, documento)) {
			if(c == quebra) {
				l++;
			}
		}

		rewind(documento);
		while(fgets(txt, 250, documento)!=NULL){
                        printf("\nColunas:\n");

                        temp = strtok(txt, " ");

                        if(temp){
                                resul = malloc((tam+1)*sizeof(char**));
                                resul[tam++] = temp;
                        }

                        while((temp=strtok(0, " "))!=0){
                                resul = realloc(resul, (tam+1)*sizeof(char**));
                                resul[tam++] = temp;
                        }
			//break para parar quando terminar de ler e alocar a primeira linha que eh a linha das colunas
                        break;
                }	

		for(unsigned int i=0; i<tam-1; i++){
			printf("%d. %s\n", i+1, resul[i]);
		}

		//tirando 1 do valor do tamanho, pois ele incrementa 1 valor a mais
		qColunas = tam-1;

		//Lembrete: a tabela da chave primaria é AI, por isso insira valores para as outras colunas.

		do{
			int cont = 0;
			char str[1000];
			int ids[1000]; //As chaves cadastradas serão armazenadas em um vetor

			rewind(documento);
			while(fgets(str, 1000, documento) != NULL){
				if(cont != 0){
					ids[cont-1] = atoi(strcat(str, " "));
				}
				cont++;
			}
		
			fprintf(documento, "%d ", ids[cont-2]+1); //Definindo a chave primária automaticamente.

			for(int i=1; i<=qColunas-1; i++){
				printf("\nColuna %d: \n", i+1); // Definindo os valores presentes nas colunas.

				printf("Insir o tipo de dados: ");
				scanf("%s", tabela.tDado);

				if(!strcmp(tabela.tDado, "char")){
					char vc; //vc = Valor do Char.
					printf("Valor: ");
					scanf("%s", &vc);

					fprintf(documento, "%c ", vc);
				}
				else if(!strcmp(tabela.tDado, "string")){
					char vs[25]; //vs = Valor do String
					printf("Valor (sem espaços): ");
					scanf("%s", vs);

					fprintf(documento, "%s ", vs);
				}
				else if(!strcmp(tabela.tDado, "float")){
					float vf; //Valor do Float
					do{
						printf("Valor: ");
						scanf("%f", &vf);

						if(vf<=chave){
							printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
						}

					} while(vf<=chave);

					fprintf(documento, "%f ", vf);
				}
				else if(!strcmp(tabela.tDado, "int")){
					int vi; //vi = Valor do Int
					do{
						printf("Valor: ");
						scanf("%d", &vi);

						if(vi<=chave){
							printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
						}

					} while(vi<=chave);

					fprintf(documento, "%d ", vi);
				}
				else if(!strcmp(tabela.tDado, "double")){
					double vd; //Valor do Double
					do{
						printf("Valor:");
						scanf("%lf", &vd);

						if(vd<=chave){
							printf("\nERRO! Mesmo valor da chave inserido. Tente novamente.\n");
						}

					} while(vd<=chave);

					fprintf(documento, "%lf ", vd);

				} else {
					printf("ERRO!Tipo de dados inválido. Padrão: NULL\n"); //NULL, caso Default
					fprintf(documento, "NULL ");
				}

				fprintf(documento, "\n");	
			}

			printf("\nDeseja adicionar mais uma tupla? (Linha) [1-Sim 0-Não]\n");
			scanf("%c", &c);

			if(c!=0 && c!=1){
				printf("ERRO! Selecione uma opção válida.");
				c = 0;
			}

		} while(c!=0);
	}

	system("clear");
	printf("\nA %s foi atualizada.\n", nomeDoc);
	
	fclose(documento);
	return 1;
}

int listaDadosTB(FILE *doc){
	char nomeTB[20];
	printf("\nNome da tabela: ");
	scanf("%s", nomeTB);

	char nomeDoc[20] = "tb_";
	strcat(nomeDoc, nomeTB);
	strcat(nomeDoc, ".txt");

	char caminhoDoc[100] = "documentos/";
	strcat(caminhoDoc, nomeDoc);

	FILE *documento = fopen(caminhoDoc, "r");

	char cmd[15]; //Comando Cat
	strcat(cmd, " documentos/");
	strcat(cmd, nomeDoc);

	if(documento==NULL){
		system("clear");
		printf("\nERRO! Não foi possível abrir o documento. \n");
		return 0;
	} else {
		system("clear");
		printf("\n%s: \n\n", nomeDoc);
		system(cmd);
	}

	return 1;
}