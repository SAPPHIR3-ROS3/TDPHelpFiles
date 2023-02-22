#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "albero_binario.h"


// Valore di errore
TipoInfoAlbero ERRORE_InfoAlbBin='*';


// Implementazioni del tipo astratto

// restituisce un albero vuoto (placeholder)
TipoAlbero albBinVuoto() 
{ return NULL;}

// crea manualmente un albero binario
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) 
{
  TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero)); // memoria allocata dinamicamente
  a->info = info; // allocazione valore
  a->sinistro = sx; //allocazione figlio sinistro
  a->destro = dx; // allocazione figlio destro
  return a;
}

// funzione ausiliaria per la generazione randomica degli alberi binari
TipoAlbero bin_tree_regen(int depth, int min, int max, int leaves, int leavespernode) 
{
  if(depth == 0) return albBinVuoto(); // controlla se la funzione è alle foglie dell'albero
  else
  {
    TipoInfoAlbero Value = rand() % (max + 1) + min; // generazione randomica di un valore trail massimo e il minimo entrambi compresi
    TipoAlbero sx = albBinVuoto(); // inizializzazione figlio sinistro
  	TipoAlbero dx = albBinVuoto(); // inizializzazione figlio destro

	 	if(leaves < 2) // constrolla se rimane solo una foglia da asseganre a 1 dei 2 figli
		{ 
      // "testa o croce" per decidere se la foglia rimanente andrà al figlio destro o sinistro
			if(rand() % 2 == 0) sx = bin_tree_regen(depth - 1, min, max, leaves, leavespernode / 2);
			else dx = bin_tree_regen(depth - 1, min, max, leaves, leavespernode / 2);
		}
		else // in questo caso rimangono 2 o più foglie
		{
      // le foglie rimanenti vengono smezzate tra i 2 figli
			int delta = (leaves > leavespernode) ? leavespernode : rand() % (leaves + 1);
			int leavessx = 0;
			int leavesdx = 0;
			
			if(rand() % 2 == 0)
			{
				leavessx = delta;
				leavesdx = leaves - delta;
			}
			else
			{
				leavessx = leaves - delta;
				leavesdx =  delta;
			}
			
			leavespernode = (leaves % 2 == 1) ? leavespernode + 1: leavespernode; // rende le foglie pari per poterle poi dividere per 2
			sx = bin_tree_regen(depth - 1, min, max, leavessx, (int) leavespernode / 2); // assegna le foglie rimanenti per il figlio sinistro // chiamata ricorsiva
			dx = bin_tree_regen(depth - 1, min, max, leavesdx, (int) leavespernode / 2); // assegna le foglie rimanenti per il figlio destro // chiamata ricorsiva
			
		}
    return creaAlbBin(Value, sx, dx);
  }
}

// funzione di generazione randomica degli alberi binari
TipoAlbero bin_tree_gen(int depth, int min, int max)
{
	int leaves = (depth > 0 ) ? rand() % (int) pow(2, depth - 1) + 1 : 0; // genera il numero di foglie da assegnare all'albero
	int leavespernode = (leaves > 1) ? (int) leaves / 2 : 1; // numero massimo di foglie per per i figli
	leavespernode = (leaves % 2 == 1) ? leavespernode + 1 : leavespernode; // rende le foglie pari
  return bin_tree_regen(depth, min, max, leaves,leavespernode);
}

// controlla se l'albero è vuoto
bool estVuoto(TipoAlbero a) 
{return (a == NULL);}

// controlla se l'albero sia una "foglia" (non vuoto e con nessun figlio)
bool estFoglia(TipoAlbero a)
{return (!estVuoto(a) && estVuoto(a->sinistro) && estVuoto(a->destro)) ? true : false;}

// restituisce il valore dell'albero
TipoInfoAlbero radice(TipoAlbero a) 
{
  if (a == NULL) 
  {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } 
  else 
  {
    return a->info;
  }
}

// restituisce il figlio sinistro dell'albero
TipoAlbero sinistro(TipoAlbero a) {
  if (a == NULL) 
  {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } 
  else 
  {
    return a->sinistro;
  }
}

// restituisce il figlio destro dell'altro
TipoAlbero destro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } 
  else
  {
    return a->destro;
  }
}

// cambia il valore dell'albero
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info) {
	if (a == NULL) 
  {
    printf ("ERRORE accesso albero vuoto \n");
    return;
	}
	a->info = info;
}


// Funzioni esterne
// stampa una rappresentazione dell'albero
void stampaParentetica(TipoAlbero a) 
{
  if (estVuoto(a)) 
  { 
    printf("");
  }
  else 
  {
    printf("( %d ", radice(a));
    stampaParentetica(sinistro(a));
    printf(" ");
    stampaParentetica(destro(a));
    printf(" )");
  }
}

// dealloca l'albero
void Bin_Tree_Free(TipoAlbero *a)
{
  if(!estVuoto(*a)) 
  {
    Bin_Tree_Free(&((*a)->sinistro)); // dealloca il figlio sinistro // chiamata ricorsiva
    Bin_Tree_Free(&((*a)->destro)); // dealloca il figlio destro // chiamata ricorsiva
    free(*a);
  }
}
