#include <math.h>
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

TipoAlbero bin_tree_regen(int depth, int min, int max, int leaves, int leavespernode)
{
  if(depth == 0) return albBinVuoto();
  else
  {
    int Value = rand() % (max + 1) + min;
    	TipoAlbero sx = albBinVuoto();
    	TipoAlbero dx = albBinVuoto();
	 	if(leaves < 2)
		{
			if(rand() % 2 == 0) sx = bin_tree_regen(depth - 1, min, max, leaves, leavespernode / 2);
			else dx = bin_tree_regen(depth - 1, min, max, leaves, leavespernode / 2);
		}
		else
		{
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
			
			leavespernode = (leaves % 2 == 1) ? leavespernode + 1: leavespernode;
			sx = bin_tree_regen(depth - 1, min, max, leavessx, (int) leavespernode / 2);
			dx = bin_tree_regen(depth - 1, min, max, leavesdx, (int) leavespernode / 2);
			
		}
    return creaAlbBin(Value, sx, dx);
  }
}

TipoAlbero bin_tree_gen(int depth, int min, int max)
{
	int leaves = (depth > 0 ) ? rand() % (int) pow(2, depth - 1) + 1 : 0;
	int leavespernode = (leaves > 1) ? (int) leaves / 2 : 1;
	leavespernode = (leaves % 2 == 1) ? leavespernode + 1 : leavespernode;
  //printf("depth: %d leaves: %d leavespernode: %d\n", depth, leaves, leavespernode);
  return bin_tree_regen(depth, min, max, leaves,leavespernode);
}

bool estVuoto(TipoAlbero a) {
  return (a == NULL);
}

bool estFoglia(TipoAlbero a)
{
	return (!estVuoto(a) && estVuoto(a->sinistro) && estVuoto(a->destro)) ? true : false;
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


void Bin_Tree_Free(TipoAlbero * a)
{ // la funzione causa errore motivo ignoto
  if(!estVuoto(*a)) 
  {
    Bin_Tree_Free(&((*a)->sinistro));
    Bin_Tree_Free(&((*a)->destro));
    free(*a);
  }
}
