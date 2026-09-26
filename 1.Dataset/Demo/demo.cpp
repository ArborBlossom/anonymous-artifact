#include <stdio.h>
#include <iostream>
#include <iomanip> 
using namespace std;


double f(double x) {
    return 1.0/(1.0+x*x);
}

double compositeSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    double x0;
    for (int i = 1; i < n; i++) {
        x0 = a + i * h;
        sum += (i % 2 == 0 ? 2.0 : 4.0) * f(x0);
    }
    return sum * h / 3.0;
}

int main() {
    double aa = 0.0;
    double bb = 1.0;
    int n = 10;  // 偶数
    double res = compositeSimpson(aa, bb, n);
    cout << "compositeSimpson ≈ " << std::scientific << std::setprecision(16) << res << endl;
    return 0;
}