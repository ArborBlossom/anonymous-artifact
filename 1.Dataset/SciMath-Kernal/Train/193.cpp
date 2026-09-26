#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double chebyshevApprox(double x, int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        sum += cos(k * acos(x)) / (k*k);
    }
    return (M_PI*M_PI)/8 - sum;
}

int main() {
    double x = 0.5;
    int n = 10;
    chebyshevApprox(x, n);
    cout << "切比雪夫逼近值: " << std::scientific << std::setprecision(16) << chebyshevApprox(x, n) << endl;
    return 0;
}