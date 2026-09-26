#include <stdio.h>
#define MU0 4 * 3.1416e-7
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double I = 10.0;  // 电流 A
    double r = 0.01;  // 距离 m
    double B = MU0 * I / (2 * 3.1416 * r);
    cout << "磁感应强度 B = " << std::scientific << std::setprecision(16) << B << endl;
    return 0;
}