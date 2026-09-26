#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double simpleInterest(double principal, double rate, double time) {
    return principal * rate * time / 100.0;
}

int main() {
    double P = 1200.0;
    double R = 5.5;
    double T = 2.0;
    double SI = simpleInterest(P, R, T);
    cout << "本金=P, 年利率=R, 时间=T年, 简单利息= \n" << std::scientific << std::setprecision(16) << SI << endl;
    return 0;
}