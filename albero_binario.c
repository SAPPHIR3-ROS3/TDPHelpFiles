#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "albero_binario.h"


// Valore di errore
TipoInfoAlbero ERRORE_InfoAlbBin='*';


// Implementazioni del tipo astratto

TipoAlbero albBinVuoto() {
  return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) {
  TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
  a->info = info;
  a->sinistro = sx;
  a->destro = dx;
  return a;
}

TipoAlbero bin_tree_gen(int depth, int min, int max)
{
  if(depth == 0) return albBinVuoto();
  else
  {
    TipoAlbero a = creaAlbBin(rand() % (max + 1) + min, bin_tree_gen(depth - 1, min, max), bin_tree_gen(depth - 1, min, max));
    int Nodes = rand() % (2 + 1);

    // if(Nodes == 0)
    // {
    //   Bin_Tree_Free(sinistro(a));
    //   Bin_Tree_Free(destro(a));
    // } 
    // else if(Nodes == 1) (rand() % 2 == 0) ? Bin_Tree_Free(sinistro(a)) : Bin_Tree_Free(destro(a));
    
    return a;
  }
}

bool estVuoto(TipoAlbero a) {
  return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } else {
    return a->info;
  }
}


TipoAlbero sinistro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->sinistro;
  }
}

TipoAlbero destro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->destro;
  }
}


void assegnaRadice(TipoAlbero a, TipoInfoAlbero info) {
	if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return;
	}
	a->info = info;
}


// Funzioni esterne

void stampaParentetica(TipoAlbero a) {
    if (estVuoto(a)) {
        printf("");
    }
    else {
        printf("( %d ", radice(a));
        stampaParentetica(sinistro(a));
        printf(" ");
        stampaParentetica(destro(a));
        printf(" )");
    }
}


void Bin_Tree_Free(TipoAlbero a)
{ // la funzione causa errore motivo ignoto
  if(!estVuoto(a)) 
  {
    Bin_Tree_Free(a->sinistro);
    Bin_Tree_Free(a->destro);
    free(a);
  }
}
