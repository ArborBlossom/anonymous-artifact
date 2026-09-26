#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void solveBessel(double x[], double J[], int n, double h) {
    J[0] = 1.0; J[1] = 1.0 - (h*h)/4.0;
    for (int i = 2; i < n; i++) {
        double xi = x[i-1];
        J[i] = (2*(i-1)/xi)*J[i-1] - J[i-2];
    }
}

int main() {
    int n = 5;
    double x[5];
    double J[5];
    double hh = 0.5;
    for (int i = 0; i < n; i++) x[i] = i*hh;
    solveBessel(x, J, n, hh);
    cout << "J0(x[0]) ≈ " << std::scientific << std::setprecision(16) << J[0] << endl;
    return 0;
}