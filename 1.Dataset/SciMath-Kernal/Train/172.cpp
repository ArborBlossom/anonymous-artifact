#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x * x + 1.0;
}

double compositeTrapezoidal(double a1, double b1, int n) {
    double h = (b1 - a1) / n;
    double sum = f(a1) + f(b1);
    for (int i = 1; i < n; i++) {
        sum += 2.0 * f(a1 + i * h);
    }
    return (h / 2.0) * sum;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 100;
    double integral = compositeTrapezoidal(a, b, n);
    cout << "复合梯形法计算积分结果 = " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}