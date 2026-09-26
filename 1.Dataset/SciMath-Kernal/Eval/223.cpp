#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double xf) { return xf*xf - 612.0; }
double df(double xdf) { return 2*xdf; }

double newtonRaphson(double x0, int iter) {
    double x = x0;
    for (int i = 0; i < iter; i++) {
        x = x - f(x)/df(x);
    }
    return x;
}

int main() {
    double root = newtonRaphson(10.0, 20);
    cout << "Square root of 612 ≈ " << std::scientific << std::setprecision(16) << root << endl;
    return 0;
}