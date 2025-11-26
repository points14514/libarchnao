#ifndef UNDERMATH_H
#define UNDERMATH_H

#ifdef __cplusplus
extern "C" {
#endif

/* 基础数学运算 */
double um_add(double a, double b);
double um_sub(double a, double b);
double um_mul(double a, double b);
double um_div(double a, double b);

/* 高级数学函数 */
double um_pow(double base, double exp);
double um_sqrt(double x);
double um_sin(double x);
double um_cos(double x);
double um_tan(double x);

/* 线性代数 */
void um_mat_multiply(int m, int n, int p, double *A, double *B, double *C);

#ifdef __cplusplus
}
#endif

#endif /* UNDERMATH_H */
