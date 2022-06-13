CC = gcc
OPT = -g -lm -o

EXEC = es
	
all : compile


compile : es.c
	$(CC) es.c albero_binario.c coda.c lista.c matrices.c pila.c $(OPT) $(EXEC)
