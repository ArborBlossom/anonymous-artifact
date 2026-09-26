#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double gaussianIntegral(double upper, int n) {
    double h = upper / n;
    double sum = 0.0;
    double x;
    for (int i = 0; i <= n; i++) {
        x = i * h;
        double coeff = (i==0)?1.0: (i==n)?1.0:2.0;
        sum += coeff * exp(-x*x);
    }
    return sum * h / 2.0;
}

int main() {
    double I = gaussianIntegral(5.0, 10000);
    cout << "∫₀^∞ e^(–x²) dx ≈ " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}