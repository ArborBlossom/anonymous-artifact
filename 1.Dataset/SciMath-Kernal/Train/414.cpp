#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void gammaPDF(double x[], int n, double k, double theta, double pdf[]) {
    for (int i = 0; i < n; i++) {
        double xi = x[i];
        if (xi > 0) {
            pdf[i] = pow(xi, k-1)*exp(-xi/theta) / (tgamma(k)*pow(theta, k));
        } else {
            pdf[i] = 0.0;
        }
    }
}

int main() {
    double x[] = {1.0,2.0,3.0,4.0,5.0};
    int n = sizeof(x)/sizeof(x[0]);
    double pdf[5];
    gammaPDF(x, n, 2.0, 1.0, pdf);
    cout << "GammaPDF(x[3]) = " << std::scientific << std::setprecision(16) << pdf[3] << endl;
    return 0;
}