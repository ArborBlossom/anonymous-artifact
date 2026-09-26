#include <stdio.h>
#include <cmath>   //
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lnTaylor(double x, int terms) {
    double sum = 0.0;
    for (int n = 1; n <= terms; n++) {
        double term = (n % 2 == 0 ? -1.0 : 1.0) * pow(x, n) / n;
        sum += term;
    }
    return sum;
}

int main() {
    double xx = 0.5;    // 计算 ln(1 + x)
    int terms = 20;
    double result = lnTaylor(xx, terms);
    cout << "ln(x) ≈ " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}