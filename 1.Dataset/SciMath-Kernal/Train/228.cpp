#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x0) {
    return 1.0 / (1.0 + x0*x0);
}

double trapezoid(double a1, double b1, int n) {
    double h = (b1 - a1) / n;
    double sum = (f(a1)+f(b1))/2.0;
    for (int i = 1; i < n; i++) sum += f(a1 + i*h);
    return sum * h;
}

double romberg(double a, double b, int m) {
    double R[m][m];
    for (int i = 0; i < m; i++) {
        int n = 1 << i;
        R[i][0] = trapezoid(a, b, n);
        for (int j = 1; j <= i; j++) {
            R[i][j] = (pow(4.0, j)*R[i][j-1] - R[i-1][j-1])/(pow(4.0, j)-1);
        }
    }
    return R[m-1][m-1];
}

int main() {
    double res = romberg(0.0, 1.0, 4);
    cout << "Romberg ∫0→1 1/(1+x²) dx ≈ " << std::scientific << std::setprecision(16) << res << endl;
    return 0;
}