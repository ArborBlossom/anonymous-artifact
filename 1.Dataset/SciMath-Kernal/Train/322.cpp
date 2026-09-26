#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void mahalanobis(double x[], double mean[], double invCov[][2], int n, double *d) {
    double diff[2];
    double temp[2] = {0.0, 0.0};
    for (int i = 0; i < n; i++)
        diff[i] = x[i] - mean[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i] += diff[j] * invCov[j][i];
    *d = 0.0;
    for (int i = 0; i < n; i++)
        *d += temp[i] * diff[i];
    *d = sqrt(*d);
}

int main() {
    double x[]      = {2.0, 3.0};
    double mean[]   = {1.0, 1.5};
    double invCov[2][2] = {{ 0.5, -0.2},
                           {-0.2,  0.7}}; // 预先求好的逆协方差矩阵
    double d;
    mahalanobis(x, mean, invCov, 2, &d);
    cout << "Mahalanobis distance = " << std::scientific << std::setprecision(16) << d << endl;
    return 0;
}