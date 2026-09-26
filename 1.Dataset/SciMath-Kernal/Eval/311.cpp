#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) { return x1*x1*x1 + x1; }

double gauss3(double a, double b) {
    const double x[3] = {-0.7745966692,0.0,0.7745966692};
    const double w[3] = {0.5555555556,0.8888888889,0.5555555556};
    double m = 0.5*(a+b);
    double h = 0.5*(b-a);
    double sum = 0.0;
    for (int i = 0; i < 3; i++)
        sum += w[i] * f(m + h*x[i]);
    return h * sum;
}

int main() {
    double I = gauss3(0.0, 1.0);
    cout << "3-point Gauss-Legendre ∫₀¹ (x³+x)dx ≈ " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}