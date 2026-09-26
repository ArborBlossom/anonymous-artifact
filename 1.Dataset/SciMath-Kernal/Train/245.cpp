#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double compoundInterest(double principal, double rate, int time, int n) {
    // A = P * (1 + r/n)^(n*t)
    return principal * pow(1.0 + rate / n, n * time);
}

int main() {
    double P = 10000.0;  // 本金
    double r = 0.05;     // 年利率
    int t = 5;           // 年数
    int n = 4;           // 每年复利次数
    double amount = compoundInterest(P, r, t, n);
    cout << "复利后金额 = " << std::scientific << std::setprecision(16) << amount << endl;
    return 0;
}