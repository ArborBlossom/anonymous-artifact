#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) {
    return sin(x1);
}

double secondDerivative(double x, double h) {
    return (-f(x+2*h) + 16*f(x+h) - 30*f(x) + 16*f(x-h) - f(x-2*h)) / (12*h*h);
}

int main() {
    double x0 = 1.0;
    double h0 = 0.01;
    double d2 = secondDerivative(x0, h0);
    cout << "f''(x) ≈ " << std::scientific << std::setprecision(16) << d2 << endl;
    return 0;
}