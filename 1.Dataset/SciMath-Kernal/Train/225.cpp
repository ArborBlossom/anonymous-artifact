#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double gaussLegendre(int iter) {
    double a = 1.0;
    double b = 1.0/sqrt(2.0);
    double t = 0.25;
    double p = 1.0;
    double an;
    double bn;
    double tn;
    double pn;
    for (int i = 0; i < iter; i++) {
        an = (a + b)/2.0;
        bn = sqrt(a*b);
        tn = t - p*(a - an)*(a - an);
        pn = 2.0*p;
        a = an; b = bn; t = tn; p = pn;
    }
    return (a + b)*(a + b)/(4.0*t);
}

int main() {
    gaussLegendre(5);
    cout << "Gauss-Legendre PI ≈ " << std::scientific << std::setprecision(16) << gaussLegendre(5) << endl;
    return 0;
}