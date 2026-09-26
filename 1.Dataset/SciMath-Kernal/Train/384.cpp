#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void rayleighPDF(double x[], int n, double sigma, double pdf[]) {
    for (int i = 0; i < n; i++) {
        double xi = x[i];
        pdf[i] = (xi / (sigma*sigma)) * exp(-xi*xi / (2.0*sigma*sigma));
    }
}

int main() {
    double x[] = {0.5, 1.0, 1.5, 2.0, 2.5};
    int n = sizeof(x)/sizeof(x[0]);
    double pdf[5];
    rayleighPDF(x, n, 1.0, pdf);
    cout << "PDF(x[1]) = " << std::scientific << std::setprecision(16) <<pdf[1] << endl;
    return 0;
}