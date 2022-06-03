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

TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
TipoAlbero bin_tree_gen(int depth, int min, int max);
bool estVuoto(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);
void assegnaRadice(TipoAlbero a, TipoInfoAlbero info);
void stampaParentetica(TipoAlbero a);
void Bin_Tree_Free(TipoAlbero a);
