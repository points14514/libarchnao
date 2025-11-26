#include "../include/poisxapi.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

poi_complex_t poi_complex_add(poi_complex_t a, poi_complex_t b) {
    poi_complex_t result = {a.real + b.real, a.imag + b.imag};
    return result;
}

poi_complex_t poi_complex_mul(poi_complex_t a, poi_complex_t b) {
    poi_complex_t result = {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
    return result;
}

double poi_complex_abs(poi_complex_t z) {
    return um_sqrt(z.real * z.real + z.imag * z.imag);
}

poi_matrix_t* poi_matrix_create(int rows, int cols) {
    poi_matrix_t *mat = malloc(sizeof(poi_matrix_t));
    if (!mat) return NULL;
    
    mat->rows = rows;
    mat->cols = cols;
    mat->data = calloc(rows * cols, sizeof(double));
    
    if (!mat->data) {
        free(mat);
        return NULL;
    }
    
    return mat;
}

void poi_matrix_free(poi_matrix_t *mat) {
    if (mat) {
        free(mat->data);
        free(mat);
    }
}

poi_matrix_t* poi_matrix_multiply(const poi_matrix_t *A, const poi_matrix_t *B) {
    if (A->cols != B->rows) return NULL;
    
    poi_matrix_t *C = poi_matrix_create(A->rows, B->cols);
    if (!C) return NULL;
    
    um_mat_multiply(A->rows, A->cols, B->cols, A->data, B->data, C->data);
    return C;
}
