#pragma once

#include "scl.h"

typedef TipoNodo *TipoLista;

// Operazioni
TipoLista listaVuota(); // crea lista vuota
int estVuota(TipoLista l); // controllo se vuota
TipoLista list_gen(int Length, int min, int max); // genera una lista di elementi randomici
TipoLista cons(T e, TipoLista l); // creo lista aggiungendo per primo
T car(TipoLista l); // leggo valore del primo
TipoLista cdr(TipoLista l); // ritorno coda della lista
void printlist(TipoLista l); // stampa la lista in console
