#pragma once

#include <stdbool.h>

// Struttura tipo matrice
typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

// Operazioni su matrici
Mat* Mat_alloc(int rows, int cols);
Mat* Mat_gen(int rows, int cols, int min, int max);
Mat* Mat_read(const char *filename);
void Mat_print(Mat *m);
void Mat_write(const char *filename, Mat *m);
void Mat_free(Mat *m);

// Funzioni ausiliarie
bool Mat_is_symmetric(Mat *m);
void Mat_normalize_rows(Mat *m);
Mat* Mat_clone(Mat *m);
Mat* Mat_sum(Mat *m1, Mat *m2);
Mat* Mat_product(Mat *m1, Mat *m2);
