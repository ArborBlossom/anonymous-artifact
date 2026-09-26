#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double horner(double coeffs[], int degree, double x1) {
    double result = coeffs[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x1 + coeffs[i];
    }
    return result;
}

int main() {
    // 多项式 2x^3 - 6x^2 + 2x - 1
    double coeffs[] = {2.0, -6.0, 2.0, -1.0};
    int deg = 3;
    double x = 3.0;
    double val = horner(coeffs, deg, x);
    cout << "P(x) = " << std::scientific << std::setprecision(16) << val << endl;
    return 0;
}