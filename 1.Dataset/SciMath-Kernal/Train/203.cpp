#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double mySqrt(double x) {
    double l = 0.0;
    double r = x;
    double mid;
    double res = 0.0;
    while (r - l > 1e-6) {
        mid = (l + r) / 2.0;
        if (mid * mid <= x) {
            res = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    return res;
}

int main() {
    double num = 10.0;
    double root;
    root = mySqrt(num);
    cout << "sqrt(num) ≈ " << std::scientific << std::setprecision(16) << root << endl;
    return 0;
}