#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double P = 10000.0; // 本金
    double r = 0.05;     // 年利率
    double t = 5.0;      // 年
    double A = P * exp(r * t); // 连续复利总额
    cout << "连续复利总额: " << std::scientific << std::setprecision(16) << A << endl;
    return 0;
}