#ifndef POISXAPI_H
#define POISXAPI_H

#include "undermath.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 高级数学API */
typedef struct {
    double real;
    double imag;
} poi_complex_t;

/* 复数运算 */
poi_complex_t poi_complex_add(poi_complex_t a, poi_complex_t b);
poi_complex_t poi_complex_mul(poi_complex_t a, poi_complex_t b);
double poi_complex_abs(poi_complex_t z);

/* 矩阵运算 */
typedef struct {
    int rows, cols;
    double *data;
} poi_matrix_t;

poi_matrix_t* poi_matrix_create(int rows, int cols);
void poi_matrix_free(poi_matrix_t *mat);
poi_matrix_t* poi_matrix_multiply(const poi_matrix_t *A, const poi_matrix_t *B);

#ifdef __cplusplus
}
#endif

#endif /* POISXAPI_H */
