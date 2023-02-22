#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "albero_binario.h"
#include "coda.h"
#include "lista.h"
#include "matrices.h"
#include "pila.h"

void MatTest()
{
    srand(time(0));

    for(int i = 0; i < 10; i++)
    {
        printf("=====================================\n");
        printf("test n%d\n", i + 1);
        Mat * m = Mat_gen(rand() % 5 + 2, rand() % 5 + 2, -5, 5);
        printf("%d %d\n", m->rows, m->cols);
        //Mat_print(m);
        // do stuff here
        printf("\n");
        printf("=====================================\n");

    }
}

void SCLTest()
{
     for(int i = 0; i < 10; i++)
    {
        printf("=====================================\n");
        printf("test n%d\n", i + 1);
        int length = rand() % (10 + 1);
        TipoLista Lista = list_gen(length, 0, 9);
        //printlist(Lista);
        // do stuff here
        printf("\n");
        printf("=====================================\n");
    }
}

void BinTreeTest()
{
    for(int i  = 0; i < 10; i++)
    {
        printf("=====================================\n");
        printf("test n%d\n", i + 1);
        int depth = rand() % (10 + 1);
        printf("depth %d\n", depth);
        TipoAlbero a = bin_tree_gen(depth, 0, 9);
        //stampaParentetica(a);
        // do stuff here
        printf("\n");
        printf("=====================================\n");
    }
}

int main()
{
// simplest input
// play around with examples and visualize
// relate to hard cases to simpler cases
// generalize patterns
// write code combining patterns with base case
    srand(time(0));
    //MatTest();
    //SCLTest();
    //BinTreeTest();
}