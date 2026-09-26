#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x * x + 1.0;
}

double compositeTrap(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += 2.0 * f(a + i * h);
    return sum * h / 2.0;
}

int main() {
    double aa = 0.0;
    double bb = 1.0;
    int n = 100;
    double integral = compositeTrap(aa, bb, n);
    cout << "复合梯形法积分 ≈ " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}