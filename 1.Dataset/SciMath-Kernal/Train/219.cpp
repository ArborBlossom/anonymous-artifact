#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) {
    return x1 * x1 * x1 + 2 * x1 + 1;
}

double centralDifference(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    double xx = 2.0;
    double hh = 0.001;
    double derivative = centralDifference(xx, hh);
    cout << "f'(x) ≈ " << std::scientific << std::setprecision(16) << derivative << endl;
    return 0;
}