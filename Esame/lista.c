#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

// restituisce una lista vista vuota (placeholder)
TipoLista listaVuota() { return NULL; }

// controlla se la lista è vuota
int estVuota(TipoLista l) { return (l == NULL); }

// genera una lista di lunghezza length con min<=elemento<=max
TipoLista list_gen(int Length, int min, int max)
{
  TipoLista l = listaVuota(); // inizializza la lista (placeholder)

  for (int i = 0; i < Length; i++)
    l = cons(rand() % (max + 1) + min, l); // aggiunge un valore compreso tra min e max
  
  return l;
}

// aggiunge un elemento all'inizio della lista
TipoLista cons(T e, TipoLista l)
{
  TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo)); // alloca la memoria per l'emento nella lista
  nuovo->info = e; // assegna l'elemento
  nuovo->next = l; // assegna la lista come "elemento successivo"
  return nuovo;
}

// restituisce l'elemento corrente della lista
T car(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->info;
}

// restituisce l'elemento  successivo della lista
TipoLista cdr(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->next;
}

// funzione ausiliaria della stampa
void printlist_aux(TipoLista l)
{
	if (estVuota(l)) return;
	printf("%d, ", car(l));
	printlist_aux(cdr(l));
}

// rappresentazione in console della lista
void printlist(TipoLista l)
{
	printlist_aux(l);
	printf("\n\n");
}
