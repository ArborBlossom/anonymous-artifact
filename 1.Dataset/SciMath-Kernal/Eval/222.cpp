#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x*x*x - x - 2;
}

double bisection(double a, double b, double tol) {
    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return c;
}

int main() {
    double root = bisection(1.0, 2.0, 1e-6);
    cout << "Root = " << std::scientific << std::setprecision(16) << root << endl;
    return 0;
}