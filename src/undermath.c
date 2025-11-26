#include "../include/undermath.h"
#include <math.h>
#include <stdio.h>

double um_add(double a, double b) { return a + b; }
double um_sub(double a, double b) { return a - b; }
double um_mul(double a, double b) { return a * b; }
double um_div(double a, double b) { return b != 0 ? a / b : 0; }

double um_pow(double base, double exp) { return pow(base, exp); }
double um_sqrt(double x) { return x >= 0 ? sqrt(x) : -1; }
double um_sin(double x) { return sin(x); }
double um_cos(double x) { return cos(x); }
double um_tan(double x) { return tan(x); }

void um_mat_multiply(int m, int n, int p, double *A, double *B, double *C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i * p + j] = 0;
            for (int k = 0; k < n; k++) {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}
