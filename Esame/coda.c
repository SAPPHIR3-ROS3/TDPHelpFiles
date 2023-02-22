#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "coda.h"

// genera una coda vuota
Coda * codaVuota() {
	//Coda *c = (Coda *)malloc(sizeof(Coda));
	//*c = NULL;
	return NULL;
}

// genera una coda di lunghezza length con min<=elementi<=max
Coda * queue_gen(int Length, int min, int max)
{
	Coda *c = codaVuota(); //genera una coda vuota (placeholder)

	for (int i = 0; i < Length; i++) 
		inCoda(c, rand() % (max + 1) + min);

	return c;
}

// controlla se la coda è vuota
bool estCodaVuota(Coda *c) {
	if (!c) {
		puts("errore: null input");
		exit(1);
	}
  return *c == NULL;
}

// aggiunge un elemento alla fine
void inCoda(Coda *c , T e) {
	if (!c)
	{
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL) 
	{
		*c = (TipoNodo *)malloc(sizeof(TipoNodo));
		(*c)->info = e;
		(*c)->next = NULL;
	} else {
		inCoda(&((*c)->next), e);
	}
}

// rimuove il primo elemento dalla coda
T outCoda(Coda *c) 
{
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
	TipoNodo *primo = *c;
	T primo_valore = primo->info;
	*c = (*c)->next;
	free(primo);

	return primo_valore;
}

// restituisce il primo elemento della coda
T primoCoda(Coda* c) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
  return (*c)->info;
}
