#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x0) {
    return x0 * x0 * x0 + 2.0 * x0;
}

double forwardDiff(double x1, double h1) {
    return (f(x1 + h1) - f(x1)) / h1;
}

int main() {
    double x = 2.0;
    double h = 0.001;
    double d = forwardDiff(x, h);
    cout << "f'(x) ≈ " << std::scientific << std::setprecision(16) << d << endl;
    return 0;
}