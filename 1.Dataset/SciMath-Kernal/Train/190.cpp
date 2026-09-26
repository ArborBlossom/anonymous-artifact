#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double compoundInterest(double principal1, double rate1, double time1, int n) {
    return principal1 * pow(1 + rate1/(n*100), n*time1);
}

int main() {
    double principal = 10000.0;
    double rate = 5.0; // 年利率5%
    double time = 5.0; // 5年
    int n = 12; // 每月复利
    double amount = compoundInterest(principal, rate, time, n);
    cout << "复利计算后的金额: " << std::scientific << std::setprecision(16) << amount << endl;
    return 0;
}