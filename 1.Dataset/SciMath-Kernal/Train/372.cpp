#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double normCDFapprox(double x) {
    // Abramowitz-Stegun 7.1.26 近似
    double t = 1.0 / (1.0 + 0.2316419 * fabs(x));
    double d = 0.3989423 * exp(-x*x/2.0);
    double p = d * t * (0.3193815 + t*(-0.3565638 + t*(1.781478 + t*(-1.821256 + t*1.330274))));
    return x > 0 ? 1.0 - p : p;
}

int main() {
    double xx[] = {-2.0,-1.0,0.0,1.0,2.0};
    int n = sizeof(xx)/sizeof(xx[0]);
    normCDFapprox(xx[2]);
    cout << "Φ(x[i]) ≈ " << std::scientific << std::setprecision(16) << normCDFapprox(xx[2]) << endl;
    return 0;
}