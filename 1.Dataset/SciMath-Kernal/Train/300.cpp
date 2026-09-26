#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x*x + x + 1.0;
}

double midpointRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double xi = a + (i + 0.5)*h;
        sum += f(xi);
    }
    return sum * h;
}

int main() {
    double integral = midpointRule(0.0, 2.0, 1000);
    cout << "Midpoint ∫₀² (x²+x+1) dx ≈ " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}