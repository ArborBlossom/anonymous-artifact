#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double lyapunov(double r, double x0, int N) {
    double x = x0;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        x = r * x * (1.0 - x);
        sum += log(fabs(r - 2.0*r*x));
    }
    return sum / N;
}

int main() {
    double r = 3.9;
    double x0 = 0.5;
    int N = 10000;
    double L = lyapunov(r, x0, N);
    cout << "Lyapunov exponent ≈ " << std::scientific << std::setprecision(16) << L << endl;
    return 0;
}