#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double calculateEMI(double principal, double annualRate, int months) {
    double monthlyRate = annualRate / (12 * 100);
    double factor = pow(1 + monthlyRate, months);
    return principal * monthlyRate * factor / (factor - 1);
}

int main() {
    double P = 500000.0;     // 贷款本金
    double R = 7.5;          // 年利率 %
    int N = 240;             // 期数（月）
    double emi = calculateEMI(P, R, N);
    cout << "EMI = " << std::scientific << std::setprecision(16) << emi << endl;
    return 0;
}