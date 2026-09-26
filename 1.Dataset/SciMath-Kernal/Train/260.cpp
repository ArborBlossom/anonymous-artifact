#include <stdio.h>
#ifndef M_PI//
#define M_PI 3.14159265358979323846//
#endif//
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x * x;  // y = x^2
}

double volumeRevolution(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double y = f(a + i * h);
        double coeff = (i == 0 || i == n) ? 1.0 : 2.0;
        sum += coeff * y * y;
    }
    return M_PI * h / 2.0 * sum;
}

int main() {
    double a0 = 0.0;
    double b0 = 1.0;
    int n = 1000;
    double vol = volumeRevolution(a0, b0, n);
    cout << "Volume of revolution = " << std::scientific << std::setprecision(16) << vol << endl;
    return 0;
}