#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "matrices.h"

// alloca dinamicamente lo spazio per la matrice
Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat)); // alloca la memoria per la struct della matrice
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (float**)malloc(rows * sizeof(float*)); // alloca la memoria per gli array di array
  for(int i = 0; i < m->rows; ++i) {
    m->row_ptrs[i] = (float*)malloc(m->cols * sizeof(float)); // alloca la memoria per righe array
  }
  return m;
}

// riempie la matrice di valori causali comprasi tra min e max
Mat* Mat_gen(int rows, int cols, int min, int max)
{
  
  Mat* m = Mat_alloc(rows, cols); // alloca la matrice
  for(int i = 0; i < m->rows; i++) 
    for(int j = 0; j < m->cols; j++)
      m->row_ptrs[i][j] = rand() % (max + 1) + min; // asseggna il valore randomico

  return m;
}

// legge valori dal nome di un file
Mat* Mat_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    fclose(fp);
    return NULL;
  }

  // la matrice viene allocata
  int rows = 0;
  if(fscanf(fp, "%d", &rows) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di righe... esco!\n", filename);
    fclose(fp);
    return NULL;
  }
  if(rows == 0) {
    return NULL;
  }

  int cols = 0; 
  if(fscanf(fp, "%d", &cols) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di colonne... esco!\n", filename);
    fclose(fp);
    return NULL;
  }
  if(cols == 0) {
    return NULL;
  }

  // la matrice viene inizializata
  Mat *m = Mat_alloc(rows, cols);
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      float valore = 0.0f;
      if(fscanf(fp, "%f", &valore) != 1) {
        printf("Errore durante la lettura del file %s, non riesco a leggere tutti gli elementi... esco!\n", filename);
        fclose(fp);
        return NULL;
      }
      m->row_ptrs[r][c] = valore;
    }
  }

  fclose(fp);
  return m;
}

// stampa della matrice in console
void Mat_print(Mat *m) {
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      printf("%.1lf ", m->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

// scrive i valori della matrice su un file
void Mat_write(const char *filename, Mat *m) {
  FILE *fp = fopen(filename, "w");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    return;
  }
  
  fprintf(fp, "%d ", m->rows);
  fprintf(fp, "%d\n", m->cols);
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      fprintf(fp, "%f ", m->row_ptrs[r][c]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

// controlla se la matrice è simmetrica
bool  Mat_is_symmetric(Mat *m) {
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {      
      if(m->row_ptrs[r][c] != m->row_ptrs[c][r]) {
	return false;
      }
    }
  }
  return true;
}

// normalizza gli elementi della matrice in base alla riga in cui si trovano
void Mat_normalize_rows(Mat *m) {
  for(int r = 0; r < m->rows; ++r) {
    float squared_sum = 0.0f;
    for(int c = 0; c < m->cols; ++c) {      
      squared_sum += m->row_ptrs[r][c] * m->row_ptrs[r][c];
    }
    if(fabs(squared_sum) > 1e-3) {
      for(int c = 0; c < m->cols; ++c) {      
      	m->row_ptrs[r][c] /= sqrtf(squared_sum);
      }
    }
  }
}

// copia la matrice
Mat* Mat_clone(Mat *m) {
  Mat *copy = Mat_alloc(m->rows, m->cols); // alloca la stessa quantità di memoria della matrice
  
  for(int r = 0; r < copy->rows; ++r) {
    for(int c = 0; c < copy->cols; ++c) {      
      copy->row_ptrs[r][c] = m->row_ptrs[r][c]; // copia il valore nella copia
    }
  }

  return copy;
}

// dealloca la memmoria assegnata alla matrice 
void Mat_free(Mat *m) {  
  for(int i = 0; i < m->rows; ++i) {
    free(m->row_ptrs[i]);
  }
  free(m->row_ptrs);
  free(m);
}

// somma gli elementi di 2 matrici
Mat* Mat_sum(Mat *m1, Mat *m2){

  if( m1->rows != m2->rows || m1->cols != m2->cols){
    printf("Operazione di somma non consensita!\n");
    return NULL;
  }

  Mat *output = Mat_alloc(m1->rows, m1->cols); // alloca memoria per la matrice risultato per non modificare le matrici originali

  for(int r = 0; r < output->rows; ++r) {
    for(int c = 0; c < output->cols; ++c) {     
      output->row_ptrs[r][c] = m1->row_ptrs[r][c] + m2->row_ptrs[r][c];
    }
  }

  return output;
}

// prodotto di matrici
Mat* Mat_product(Mat *m1, Mat *m2){

  if( m1->cols != m2->rows){
    printf("Operazione di prodotto matriciale non consensita!\n");
    return NULL;
  }

  Mat *output = Mat_alloc(m1->rows, m2->cols); // alloca memoria per la matrice risultato per non modificare le matrici originali

  for(int r = 0; r < output->rows; ++r) {
    for(int c = 0; c < output->cols; ++c) {     
      output->row_ptrs[r][c] = 0.f;
        for(int k=0; k<output->rows; k++){
          output->row_ptrs[r][c] += m1->row_ptrs[r][k] * m2->row_ptrs[k][c];
        }

    }
  }

  return output;
}
