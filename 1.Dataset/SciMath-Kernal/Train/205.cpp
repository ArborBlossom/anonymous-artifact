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

double taylorSin(double x, int terms) {
    double sum = 0.0;
    for (int n = 0; n < terms; n++) {
        double term = ((n % 2 == 0) ? 1.0 : -1.0)
            * pow(x, 2*n+1) / factorial(2*n+1);
        sum += term;
    }
    return sum;
}

int main() {
    double xx = 1.0;      // 弧度
    int terms = 10;
    double result = taylorSin(xx, terms);
    cout << "sin(x) ≈ " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}