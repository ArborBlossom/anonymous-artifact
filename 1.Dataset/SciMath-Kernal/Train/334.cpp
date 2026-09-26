#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) { return x*x*x - x - 1.0; }

double secant(double x0, double x1, int maxIt, double tol) {
    double x2;
    for (int i = 0; i < maxIt; i++) {
        double fx0 = f(x0);
        double fx1 = f(x1);
        x2 = x1 - fx1*(x1 - x0)/(fx1 - fx0);
        if (fabs(x2 - x1) < tol) break;
        x0 = x1; x1 = x2;
    }
    return x2;
}

int main() {
    double root = secant(1.0, 2.0, 20, 1e-6);
    cout << "Root ≈ " << std::scientific << std::setprecision(16) << root << endl;
    return 0;
}