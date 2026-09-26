#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x * x + 1.0;
}

double midpointRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x_mid = a + h * (i + 0.5);
        sum += f(x_mid);
    }
    return sum * h;
}

int main() {
    double aa = 0.0;
    double bb = 1.0;
    int n = 1000;
    double integral = midpointRule(aa, bb, n);
    cout << "Midpoint Rule Integral = " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}