#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double arithmeticSum(double a1, double d1, int n) {
    return n * (2 * a1 + (n - 1) * d1) / 2;
}

int main() {
    double a = 1.5;
    double d = 2.5;
    int n = 10;
    arithmeticSum(a, d, n);
    cout << "前 a 项和 =" << std::scientific << std::setprecision(16) << arithmeticSum(a, d, n) << endl;
    return 0;
}