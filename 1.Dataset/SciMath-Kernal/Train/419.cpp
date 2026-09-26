#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void weibullPDF(double x[], int n, double k, double lambda, double pdf[]) {
    for (int i = 0; i < n; i++) {
        double xi = x[i];
        pdf[i] = (k/lambda) * pow(xi/lambda, k-1) * exp(-pow(xi/lambda, k));
    }
}

int main() {
    double x[] = {0.5,1.0,1.5,2.0,2.5};
    int n = sizeof(x)/sizeof(x[0]);
    double pdf[5];
    weibullPDF(x, n, 1.5, 1.0, pdf);
    cout << "WeibullPDF(x[i]) = " << std::scientific << std::setprecision(16) << pdf[0] << endl;
    return 0;
}