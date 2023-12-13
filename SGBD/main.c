#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criacao.h"
#include "edicao.h"
#include "exclusao.h"
#include "visualizacao.h"


// funcao para salvar uma tabela em formato txt no computador, escolha o nome do arquivo para que possa ser recuperada depois
int main() {
    Tabela *todasTabelas = NULL;
    int todasTabelas_size = 0;
    int op = 10;
    printf("\nBem vindo ao sistema de gerenciamento de tabelas\n");
    while (op != 0) {

		printf("\n");
		printf("+=+=+=+=+=+=+=+ SGBD - ITP +=+=+=+=+=+=+=+=\n");
		printf("| 1 - Criar uma tabela                    |\n");
		printf("| 2 - Listar todas as tabela              |\n");
		printf("| 3 - Criar Linha                         |\n");
		printf("| 4 - Mostar tabela                       |\n");
        printf("| 5 - Pesquisar valor em uma tabela       |\n");
		printf("| 6 - Editar coluna da tabela             |\n");
		printf("| 7 - Apagar linha                        |\n");
        printf("| 8 - Apagar tabela                       |\n");
		printf("| 0 - Sair                                |\n");
		printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
		printf("\n");
        
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        if (op < 0 || op > 8) {
            printf("Opção inválida.\n");
            continue;
        }

        switch (op) {
            case 1:
                criarTabela(&todasTabelas, &todasTabelas_size);
                break;
            case 2:
                mostarTodas(todasTabelas, todasTabelas_size);
                break;
            case 3:
                criarLinha(todasTabelas, todasTabelas_size);
                break;
            case 4:
                mostrarTabela(todasTabelas, todasTabelas_size);
                break;
            case 5:
                pesquisaValor(todasTabelas, todasTabelas_size);
                break;
            case 6:
                editarValorTabela(todasTabelas, todasTabelas_size);
                break;
            case 7:
                deletarLinha(todasTabelas, todasTabelas_size);
                break;
            case 8:
                deletarTabela(todasTabelas, &todasTabelas_size);
                break;
        } 
    }
    return 0;
}