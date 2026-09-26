#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double factorial(int n) {
    double res = 1.0;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

double taylorCos(double x1, int terms) {
    double sum = 0.0;
    for (int n = 0; n < terms; n++) {
        double term = pow(-1.0, n) * pow(x1, 2*n) / factorial(2*n);
        sum += term;
    }
    return sum;
}

int main() {
    double x = 1.0;    // 弧度
    int terms = 10;
    double result = taylorCos(x, terms);
    cout << "cos(x) ≈ " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}