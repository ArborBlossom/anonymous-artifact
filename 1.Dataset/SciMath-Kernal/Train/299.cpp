#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double taylorLn1p(double x, int terms) {
    double sum = 0.0;
    for (int n = 1; n <= terms; n++) {
        double term = pow(-1.0, n-1) * pow(x, n) / n;
        sum += term;
    }
    return sum;
}

int main() {
    double xx = 0.5;
    int terms = 20;
    double approx = taylorLn1p(xx, terms);
    cout << "ln(1+x) ≈ " << std::scientific << std::setprecision(16) << approx << endl;
    return 0;
}