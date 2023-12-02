#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int apagaTb(FILE *doc){
	char nomeTb[20];

	printf("Nome da tabela (que será apagada): ");
	scanf("%s", nomeTb);

	char nomeDoc[50] = "tb_";
	strcat(nomeDoc, nomeTb);
	strcat(nomeDoc, ".txt");

	char caminhoDoc[100] = "documentos/";
	strcat(caminhoDoc, nomeDoc);

	FILE *documento = fopen(caminhoDoc, "r");

	if(documento==NULL){
		system("clear");
		printf("\nERRO! O arquivo não foi localizado.\n");
		return 0;
	} else {
		remove(caminhoDoc);
		system("clear");
		printf("\nDocumento deletado.\n");
	}

	fclose(documento);
	return 0;
}

int apagaLinhaTB(FILE *doc){
	char nomeTb[20];
	char c, quebra = '\n';
	int l = 0, count = 1; //l = linhas

	printf("\nNome da tabela (A qual a linha será apagada): ");
	scanf("%s", nomeTb);

	char nomeDoc[50] = "tabela_";
	strcat(nomeDoc, nomeTb);
	strcat(nomeDoc, ".txt");

	char caminhoDoc[100] = "documentos/";
	strcat(caminhoDoc, nomeDoc);

	FILE *documento = fopen(caminhoDoc, "r");
	FILE *newdoc = fopen("documentos/newdoc.txt", "w"); //Criando novo arquivo para copiar o conteúdo

	if(documento==NULL){
		system("clear");
		printf("\nERRO! Não foi encontrado este arquivo.\n");    
		return 0;
	} else {
             
                while(fread(&c, sizeof(char), 1, documento)) { //Obtendo o número de linhas do arquivo
                        if(c == quebra) {
                                l++;
                        }
                }

		int cPrimaria;
		printf("Valor da chave primária: ");
		scanf("%d", &cPrimaria);

		rewind(documento);
		count= 1;
		char txtlin[100];
		char ch = getc(documento);

		while(ch != EOF){ //Ao verificar o documento até o final, se o valor da chave for encontrado, escreve esta nova linha.
			if(count!=(cPrimaria+1)){
				putc(ch, newdoc);
			}
			ch = getc(documento);

			if(ch == '\n'){
				count++;
			}
		}

		fclose(newdoc);
		remove(caminhoDoc);
		rename("documentos/newdoc.txt", caminhoDoc);

		system("clear");
		printf("\nOperação bem sucedida!\n");

		fclose(documento);
		return 0;
	}
}

