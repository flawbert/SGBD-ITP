# Makefile para compilar o projeto

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Nome do executável
TARGET = executar

# Lista de arquivos fonte
SOURCES = main.c exclusao.c criacao.c visualizacao.c edicao.c estruturas.c

# Lista de arquivos objeto gerados a partir dos fontes
OBJECTS = $(SOURCES:.c=.o)

# Regra padrão para construir o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra para cada arquivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos gerados durante a compilação
clean:
	rm -f $(TARGET) $(OBJECTS)
