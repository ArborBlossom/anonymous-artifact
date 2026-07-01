#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip> 
using namespace std;

double incGamma(double s, double x) {
    double sum = 1.0/x;
    double term = sum;
    for (int k = 1; k < 20; k++) {
        term *= x / (s + k);
        sum += term;
    }
    return pow(x, s) * exp(-x) * sum;
}

int main() {
    double ss = 2.5;
    double xx = 3.0;

    incGamma(ss, xx);
    cout << "γ(s,x) ≈ " << std::scientific << std::setprecision(16) << incGamma(ss, xx) << endl;
    return 0;
}