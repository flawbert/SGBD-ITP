#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes/cria-lista-tabelas.h"
#include "funcoes/pesquisa-tabela.h"
#include "funcoes/cria_linha-lista_dados-tabelas.h"
#include "funcoes/apaga_linha-apaga_tabela.h"

int main(void){
	int op_menu;

	system("clear");

	do{

		printf("\n");
		printf("+=+=+=+=+=+=+=+ SGBD - ITP +=+=+=+=+=+=+=+=\n");
		printf("| 1 - Criar uma tabela                       |\n");
		printf("| 2 - Listar as tabelas criadas                   |\n");
		printf("| 3 - Listar os dados de uma tabela        |\n");
		printf("| 4 - Criar nova linha em uma tabela         |\n");
		printf("| 5 - Apagar valor da tabela        |\n");
		printf("| 6 - Apagar uma tabela			 |\n");
		printf("| 0 - Sair                           |\n");
		printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
		printf("\n");

		printf("Selecione uma opção do Menu: \n");
		scanf("%d", &op_menu);

		FILE *documento = fopen("documentos/menu.txt", "r");

		if(op_menu==0){
			break;
		} else if(op_menu==1){
			criaTab(documento);
		} else if(op_menu==2){
			listaTabelas(documento);
		} else if(op_menu==3){
			criaLTb(documento);
		} else if(op_menu==4){
			listaDadosTB(documento);
		} else if(op_menu==5){
			apagaLinhaTB(documento);
		} else if(op_menu==6){
			apagaTb(documento);
		} else {
			system("clear");
			printf("\nERRO! Opção selecionada é inválida.\n");	
		} 
    
	} while(op_menu!=0);

	return 0;
}