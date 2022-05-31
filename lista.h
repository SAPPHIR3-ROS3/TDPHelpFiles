#pragma once

#include "scl.h"

typedef TipoNodo *TipoLista;

// Operazioni
TipoLista listaVuota();             // crea lista vuota
int estVuota(TipoLista l);          // controllo se vuota
TipoLista list_gen(int Length, int min, int max); 
TipoLista cons(T e, TipoLista l);   // creo lista aggiungendo per primo
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno coda della lista

void printlist(TipoLista l);
