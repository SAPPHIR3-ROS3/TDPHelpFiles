CC = gcc
OPT = -o

all : compile run


compile : es.c
	$(CC) es.c albero_binario.c coda.c lista.c matrices.c pila.c $(OPT) es.exe

run : es.exe
	clear
	.\es.exe
