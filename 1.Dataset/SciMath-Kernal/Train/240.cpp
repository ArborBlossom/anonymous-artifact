#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double npv(double cashflow[], int n, double rate1) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += cashflow[i] / pow(1.0 + rate1, i);
    return sum;
}

double irr(double cashflow[], int n) {
    double rate = 0.1;
    double h;
    for (int iter = 0; iter < 20; iter++) {
        double f = npv(cashflow, n, rate);
        // 数值微分近似
        h = 1e-6;
        double f1 = npv(cashflow, n, rate + h);
        rate = rate - f * h / (f1 - f);
    }
    return rate;
}

int main() {
    double cashflow[] = {-10000.0, 3000.0, 4200.0, 6800.0};
    int n = sizeof(cashflow) / sizeof(cashflow[0]);
    double result = irr(cashflow, n);
    cout << "IRR ≈ " << std::scientific << std::setprecision(16) << result << endl;
    return 0;
}