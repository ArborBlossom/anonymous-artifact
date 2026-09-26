#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double cubeRoot(double x) {
    double low = 0.0;
    double high = x > 1 ? x : 1.0;
    double mid;
    while (high - low > 1e-6) {
        mid = (low + high) / 2.0;
        if (mid * mid * mid < x)
            low = mid;
        else
            high = mid;
    }
    return (low + high) / 2.0;
}

int main() {
    double num = 27.0;
    cubeRoot(num);
    cout << "Cube root of num ≈ " << std::scientific << std::setprecision(16) << cubeRoot(num) << endl;
    return 0;
}