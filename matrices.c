#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "matrices.h"


Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (float**)malloc(rows * sizeof(float*));
  for(int i = 0; i < m->rows; ++i) {
    m->row_ptrs[i] = (float*)malloc(m->cols * sizeof(float));
  }
  return m;
}

Mat* Mat_gen(int rows, int cols, int min, int max)
{
  
  Mat* m = Mat_alloc(rows, cols);
  for(int i = 0; i < m->rows; i++)
    for(int j = 0; j < m->cols; j++)
      m->row_ptrs[i][j] = rand() % (max + 1) + min;

  return m;
}

Mat* Mat_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    fclose(fp);
    return NULL;
  }

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

void Mat_print(Mat *m) {
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      printf("%.1lf ", m->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

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

Mat* Mat_clone(Mat *m) {
  Mat *copy = Mat_alloc(m->rows, m->cols);
  
  for(int r = 0; r < copy->rows; ++r) {
    for(int c = 0; c < copy->cols; ++c) {      
      copy->row_ptrs[r][c] = m->row_ptrs[r][c];
    }
  }

  return copy;
}

void Mat_free(Mat *m) {  
  for(int i = 0; i < m->rows; ++i) {
    free(m->row_ptrs[i]);
  }
  free(m->row_ptrs);
  free(m);
}

Mat* Mat_sum(Mat *m1, Mat *m2){

  if( m1->rows != m2->rows || m1->cols != m2->cols){
    printf("Operazione di somma non consensita!\n");
    return NULL;
  }

  Mat *output = Mat_alloc(m1->rows, m1->cols);

  for(int r = 0; r < output->rows; ++r) {
    for(int c = 0; c < output->cols; ++c) {     
      output->row_ptrs[r][c] = m1->row_ptrs[r][c] + m2->row_ptrs[r][c];
    }
  }

  return output;
}


Mat* Mat_product(Mat *m1, Mat *m2){

  if( m1->cols != m2->rows){
    printf("Operazione di prodotto matriciale non consensita!\n");
    return NULL;
  }

  Mat *output = Mat_alloc(m1->rows, m2->cols);

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
