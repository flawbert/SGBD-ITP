// estruturas.h
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    char *nomeTabela;
    char **nomesColunas;
    void ***listaValores;
    int nCol;
    int numeroLinhas;
    int *tiposColunas;
} Tabela;

void salvarTabela(const Tabela *todasTabelas, int todasTabelas_size, const char *nomeArquivo);
void exibirValorFormatado(const Tabela tabela, int linha, int coluna);
void pesquisarStrings(const Tabela tabela, int coluna, const char *valor);

#endif // ESTRUTURAS_H