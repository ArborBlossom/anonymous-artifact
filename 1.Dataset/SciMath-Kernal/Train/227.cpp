#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

// 2-point Gauss-Legendre nodes and weights
const double x0 = -0.5773502692;
const double x1 = 0.5773502692;
const double w0 = 1.0;
const double w1 = 1.0;

double f(double x) {
    return 1.0 / (1.0 + x*x);
}

double gaussianQuadrature(double a, double b) {
    double m = (a + b)/2.0;
    double h = (b - a)/2.0;
    return h * (w0*f(m + h*x0) + w1*f(m + h*x1));
}

int main() {
    double res = gaussianQuadrature(0.0, 1.0);
    cout << "2-point Gaussian Quadrature ≈ " << std::scientific << std::setprecision(16) << res << endl;
    return 0;
}