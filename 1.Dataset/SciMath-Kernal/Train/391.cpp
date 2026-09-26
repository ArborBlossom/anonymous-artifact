#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

void maxwellPDF(double v[], int n, double m, double T, double PDF[]) {
    const double k = 1.380649e-23;
    double a = sqrt(m/(2.0*k*T));
    double C = 4.0 * sqrt(M_PI) * pow(k*T/m, 1.5);
    for (int i = 0; i < n; i++) {
        double vi = v[i];
        PDF[i] = C * vi*vi * exp(-m*vi*vi/(2.0*k*T));
    }
}

int main() {
    double v[] = {500, 1000, 1500, 2000, 2500}; // m/s
    int n = sizeof(v)/sizeof(v[0]);
    double PDF[5];
    maxwellPDF(v, n, 4.65e-26, 300.0, PDF); // 氮分子质量、T=300K
    cout << "f(v[3]) = " << std::scientific << std::setprecision(16) << PDF[3] << endl;
    return 0;
}