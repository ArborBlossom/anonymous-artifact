#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double simpsonSqrt(int n) {
    double a = 0.0;
    double b = 1.0;
    double h = (b - a) / n;
    double sum = sqrt(a) + sqrt(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i%2==0 ? 2.0 : 4.0) * sqrt(x);
    }
    return sum * h / 3.0;
}

int main() {
    int n = 100; // 必须为偶数
    double area = simpsonSqrt(n);
    cout << "∫₀¹ √x dx ≈ " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}