#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double newtonSqrt(double n, double tolerance) {
    double x = n;
    double root;
    int iter = 0;
    do {
        root = x;
        x = 0.5 * (x + n / x);
        iter++;
    } while ((root - x > tolerance) || (x - root > tolerance));
    return x;
}

int main() {
    double number = 25.0;
    double tol = 0.00001;
    double result = newtonSqrt(number, tol);
    cout << "Newton迭代法计算 25.00 的平方根：" << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}