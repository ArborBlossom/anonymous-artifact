#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//
#define MAX 5

double f(double x) { return log(x); }

double romberg(double a, double b) {
    double R[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        int n = 1 << i;
        double h = (b - a) / n;
        double sum = 0.0;
        if (i == 0) R[i][0] = 0.5 * (f(a) + f(b)) * (b - a);
        else {
            for (int k = 1; k < n; k += 2)
                sum += f(a + k*h);
            R[i][0] = 0.5 * R[i-1][0] + sum * h;
        }
        for (int j = 1; j <= i; j++)
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4.0, j) - 1.0);
    }
    return R[MAX-1][MAX-1];
}

int main() {
    double I = romberg(1.0, 2.0);
    cout << "∫₁² ln(x) dx ≈ " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}