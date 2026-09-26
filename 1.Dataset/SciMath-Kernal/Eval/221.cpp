#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double gpSum(double aa, double rr, int n) {
    // S = a * (1 - r^n) / (1 - r)
    return aa * (1.0 - pow(rr, n)) / (1.0 - rr);
}

int main() {
    double a = 2.0;   // 首项
    double r = 0.5;   // 公比
    int n = 10;       // 项数
    double sum = gpSum(a, r, n);
    cout << "GP Series Sum = " << std::scientific << std::setprecision(16) << sum << endl;
    return 0;
}