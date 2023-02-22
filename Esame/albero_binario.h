#pragma once

#include <stdbool.h>


// Tipo info dell'albero
typedef int TipoInfoAlbero;

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;


// funzioni varie
TipoAlbero albBinVuoto(); // restituisce un null a simboleggiare un albero binario vuoto (placeholder)
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx); // restituisce un TipoAlbero con valore info e figli sx e dx, che possono essere anche null
TipoAlbero bin_tree_gen(int depth, int min, int max); // genera un albero binario casuale con min <= info <= max di profondità depth, utile per testare il proprio codice senza dover manualmente creare gli alberi
bool estVuoto(TipoAlbero a); // controlla se l'albero è vuoto
bool estFoglia(TipoAlbero a); // controlla se l'albero ha tutti i figli uguali a null, un albero con figli null è una foglia
TipoInfoAlbero radice(TipoAlbero a); // restituisce il valore dell'albero info
TipoAlbero sinistro(TipoAlbero a); // restituisce il figlio sinistro dell'albero
TipoAlbero destro(TipoAlbero a); // restituisce il figlio destro dell'albero
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info); // cambia il valore dell'albero
void stampaParentetica(TipoAlbero a); // stampa l'albero in console
void Bin_Tree_Free(TipoAlbero * a); //la funzione causa erra motivo ignoto
