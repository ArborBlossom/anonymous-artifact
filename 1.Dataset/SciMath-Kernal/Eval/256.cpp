#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

#define N 3
#define ITER 20

void matVecMul(double A[N][N], double x[], double y[]) {
    for (int i = 0; i < N; i++) {
        y[i] = 0.0;
        for (int j = 0; j < N; j++)
            y[i] += A[i][j] * x[j];
    }
}

double powerMethod(double A[N][N], double x[]) {
    double y[N];
    double lambda = 0.0;
    for (int it = 0; it < ITER; it++) {
        matVecMul(A, x, y);
        lambda = fabs(y[0]);
        for (int i = 1; i < N; i++)
            if (fabs(y[i]) > lambda) lambda = fabs(y[i]);
        for (int i = 0; i < N; i++)
            x[i] = y[i] / lambda;
    }
    return lambda;
}

int main() {
    double A[N][N] = {
        {4.0, 1.0, 1.0},
        {1.0, 3.0, 0.0},
        {1.0, 0.0, 2.0}
    };
    double x[N] = {1.0, 1.0, 1.0};  // 初始向量
    double dominant = powerMethod(A, x);
    cout << "最大特征值 ≈ " << std::scientific << std::setprecision(16) << dominant << endl;
    return 0;
}