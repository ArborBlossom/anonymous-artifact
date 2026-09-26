#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double arcLength(int n) {
    double a = 0.0;
    double b = 1.0;
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double ds = sqrt(1 + (2.0*x)*(2.0*x));
        if (i == 0 || i == n) sum += ds;
        else sum += 2 * ds;
    }
    return (h / 2.0) * sum;
}

int main() {
    int n = 100000;
    double length = arcLength(n);
    cout << "Arc length ≈ " << std::scientific << std::setprecision(16) << length << endl;
    return 0;
}