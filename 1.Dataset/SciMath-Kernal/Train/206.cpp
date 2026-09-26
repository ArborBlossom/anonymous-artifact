#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double factorial(int n) {
    double res = 1.0;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

double expSeries(double x, int terms) {
    double sum = 1.0;  // n=0 项
    for (int n = 1; n < terms; n++) {
        sum += pow(x, n) / factorial(n);
    }
    return sum;
}

int main() {
    double xx = 1.0;
    int terms = 10;
    double e = expSeries(xx, terms);
    cout << "e^x ≈ " << std::scientific << std::setprecision(16) << e << endl;
    return 0;
}