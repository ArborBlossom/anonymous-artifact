#include <stdio.h>
#include <math.h>
#define M 5  // 数据点数
#define DEG 2 // 多项式次数
#include <iostream>//
#include <iomanip> //
using namespace std;//

void polyFit(double x[], double y[], int m, int deg, double coef[]) {
    double X[2*DEG+1];
    for (int i = 0; i < 2*deg+1; i++) {
        X[i] = 0.0;
        for (int j = 0; j < m; j++)
            X[i] += pow(x[j], i);
    }
    double B[DEG+1][DEG+2];
    for (int i = 0; i <= deg; i++) {
        for (int j = 0; j <= deg; j++)
            B[i][j] = X[i+j];
        B[i][deg+1] = 0.0;
        for (int j = 0; j < m; j++)
            B[i][deg+1] += pow(x[j], i) * y[j];
    }
    // Gaussian Elimination
    for (int i = 0; i < deg; i++) {
        for (int k = i+1; k <= deg; k++) {
            double t = B[k][i] / B[i][i];
            for (int j = 0; j <= deg+1; j++)
                B[k][j] -= t * B[i][j];
        }
    }
    for (int i = deg; i >= 0; i--) {
        coef[i] = B[i][deg+1];
        for (int j = i+1; j <= deg; j++)
            coef[i] -= B[i][j] * coef[j];
        coef[i] /= B[i][i];
    }
}

int main() {
    double x[M] = {1,2,3,4,5};
    double y[M] = {5,9,15,23,35};
    double coef[DEG+1];
    polyFit(x, y, M, DEG, coef);
    cout << "x[2] = " << std::scientific << std::setprecision(16) << x[2] << endl;
    return 0;
}