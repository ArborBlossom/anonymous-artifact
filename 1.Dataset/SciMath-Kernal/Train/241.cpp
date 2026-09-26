#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double npv(double cashflow[], int n, double rate) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += cashflow[i] / pow(1.0 + rate, i);
    return sum;
}

int main() {
    double cashflow[] = {-5000.0, 1500.0, 2000.0, 2500.0};
    int n = sizeof(cashflow) / sizeof(cashflow[0]);
    double rate0 = 0.12;  // 折现率
    double result = npv(cashflow, n, rate0);
    cout << "NPV = " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}