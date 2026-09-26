#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return x * x * x + 1.0;
}

double simpsons38(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 3 == 0 ? 2.0 : 3.0) * f(x);
    }
    return sum * 3.0 * h / 8.0;
}

int main() {
    double aa = 0.0;
    double bb = 1.0;
    int n = 12;  // n 必须是 3 的倍数
    double res = simpsons38(aa, bb, n);
    cout << "Composite Simpson's 3/8 ≈ " << std::scientific << std::setprecision(16) << res << endl;
    return 0;
}