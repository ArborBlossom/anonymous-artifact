#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x1) { return sin(x1); }

double simpson38(double a, double b, int n) {
    double h = (b - a)/n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += (i % 3 == 0 ? 2.0 : 3.0)*f(x);
    }
    return sum * 3.0*h/8.0;
}

int main() {
    double aa = 0.0;
    double bb = M_PI;
    int n = 12;  // 必须为 3 的倍数
    double integral = simpson38(aa,bb,n);
    cout << "∫₀^π sin(x) dx ≈ " << std::scientific << std::setprecision(16) << integral << endl;
    return 0;
}