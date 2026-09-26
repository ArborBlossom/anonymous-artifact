#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) { return exp(-x1*x1); }

double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += (i%2==0 ? 2.0 : 4.0)*f(x);
    }
    return sum * h / 3.0;
}

int main() {
    double I = simpson(-1.0, 1.0, 1000);
    cout << "∫₋₁¹ e^(–x²) dx ≈ " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}