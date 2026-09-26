#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double f(double x) {
    return (x == 0.0) ? 1.0 : sin(x)/x;
}

double compositeSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x1 = a + i*h;
        sum += (i % 2 == 0 ? 2.0 : 4.0) * f(x1);
    }
    return sum * h / 3.0;
}

int main() {
    double result = compositeSimpson(0.0, M_PI, 1000);
    cout << "∫₀^π sin(x)/x dx ≈ " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}