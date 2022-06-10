#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "albero_binario.h"
#include "coda.h"
#include "lista.h"
#include "matrices.h"
#include "pila.h"

void max_row_col(Mat * m, int * row, int * col)
{
    int sum = 0;
    int temp = 0;

    for(int i = 0; i < m->rows; i++)
    {
        temp = 0;

        for(int j = 0; j < m->cols; j++) temp += m->row_ptrs[i][j];

        if(temp > sum) 
        {
            *row = i;
            sum = temp;
        }
    }

    sum = 0;
    
    for(int i = 0; i < m->cols; i++)
    {
        temp = 0;
        for(int j = 0; j < m->rows; j++) temp += m->row_ptrs[j][i];

        if(temp > sum) 
        {
            *col = i;
            sum = temp;
        }
    }
}

float * massimi(Mat * m)
{
    float * ret = (float *)malloc(m->cols * sizeof(float));
    for(int i = 0; i < m->cols; i++) ret[i] = m->row_ptrs[0][i];

    for(int i = 0; i < m->cols; i++)
    {
        for(int j = 0; j < m->rows; j++)
            if(m->row_ptrs[j][i] > ret[i]) ret[i] = m->row_ptrs[j][i];
    }
    return ret;
}

int len(TipoLista l)
{ return (estVuota(l)) ? 0 : 1 + len(cdr(l)); }

TipoLista iniziali(TipoLista list, int k)
{
    if(estVuota(list) || k == 0) return listaVuota();
    else
    {
        if(k >= len(list)) return list;
        else return cons(car(list), iniziali(cdr(list), k - 1)); 
    }
}

TipoLista * liste_iniziali(TipoLista list)
{
    TipoLista * liste = (TipoLista*) malloc(len(list) * sizeof(TipoLista));

    for(int i = 0; i < len(list); i++)
        liste[i] = iniziali(list, i + 1);

    return liste;
}

TipoLista reverse_list(TipoLista output, TipoLista input)
{
    if(estVuota(input)) return output;
    else
    {
        output = cons(car(input), output);
        return reverse_list(output, cdr(input));
    }
}

TipoLista append_almeno_5(T e, TipoLista l)
{
    if(e < 5) return l;
    else
    {
        TipoLista reverse = reverse_list(listaVuota(), l);
        TipoLista result = cons(e, reverse);
        
        return reverse_list(listaVuota(), result);
    }
}

TipoLista inverti_numeri_alti(TipoLista l)
{
    if(estVuota(l)) return listaVuota();
    else
    {
        TipoLista result = listaVuota();
        while(!estVuota(l))
        {
            result = append_almeno_5(car(l), result);
            l = cdr(l);
        }

        return reverse_list(listaVuota(),result);
    }
}

void MatTest()
{
    srand(time(0));

    for(int i = 0; i < 10; i++)
    {
        printf("=====================================\n");
        printf("test n%d\n", i + 1);

        Mat * m = Mat_gen(rand() % 5 + 2, rand() % 5 + 2, -5, 5);
        
        printf("%d %d\n", m->rows, m->cols);
        Mat_print(m);
        // max_row_col(m, max_row, max_col);
        float * res = massimi(m);

        printf("\n");
        printf("obtained result: ");
        //printf(" %d %d\n", *max_row, *max_col)
        for(int i = 0; i < m->cols; i++) printf("%.2f ", res[i]);
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
        int elem = rand() % 10;
        printlist(Lista);
        //printf("%d \n", elem);
        printf("obtained result: \n");
        printlist(inverti_numeri_alti(Lista));
        // TipoLista * Result = liste_iniziali(Lista);
        // for(int i = 0; i < length; i++) printlist(Result[i]);
        //printlist(iniziali(Lista, newlen));

        printf("\n");
        printf("=====================================\n");
    }
}

void BinTreeTest()
{
    for(int i  = 0; i < 10; i++)
    {
        printf("test n%d\n", i + 1);
        int depth = rand() % (10 + 1);
        TipoAlbero a = bin_tree_gen(depth, 0, 9);
        //stampaParentetica(bin_tree_gen(depth, 0, 9));
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
    BinTreeTest();
}