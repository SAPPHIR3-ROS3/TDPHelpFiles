CC = gcc
OPT = -lm -o

EXEC = es.exe

ifeq ($(OS),Windows_NT)
	EXEC = .\es.exe
else
	EXEC = ./es.exe
	
endif
	
all : compile run


compile : es.c
	$(CC) es.c albero_binario.c coda.c lista.c matrices.c pila.c $(OPT) es.exe

run : es.exe
	clear
	$(EXEC)