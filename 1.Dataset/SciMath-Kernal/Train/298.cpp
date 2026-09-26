#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) { return exp(-x*x); }

double compositeTrapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5*(f(a) + f(b));
    for (int i = 1; i < n; i++)
        sum += f(a + i*h);
    return sum * h;
}

int main() {
    double integral = compositeTrapezoid(0.0, 2.0, 1000);
    cout << "∫₀² e^(–x²) dx ≈ " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}