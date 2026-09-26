#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void planckRadiance(double lambda[], int n, double T, double B[]) {
    const double h = 6.62607015e-34;
    const double c = 2.99792458e8;
    const double k = 1.380649e-23;
    for (int i = 0; i < n; i++) {
        double L = lambda[i];
        double num = 2.0*h*c*c / pow(L,5);
        double den = exp(h*c/(L*k*T)) - 1.0;
        B[i] = num / den;
    }
}

int main() {
    double lambda[] = {500e-9, 600e-9, 700e-9, 800e-9, 900e-9}; // m
    int n = sizeof(lambda)/sizeof(lambda[0]);
    double B[5];
    planckRadiance(lambda, n, 5800.0, B); // 太阳表面温度 ~5800K
    cout << "B(lambda[1]*1e9 nm) = B[i] W·sr⁻¹·m⁻³\n" << std::scientific << std::setprecision(16) << B[1] << endl;
    return 0;
}