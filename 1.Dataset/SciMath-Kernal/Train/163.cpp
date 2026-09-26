#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double mu0 = 4 * M_PI * 1e-7; // 真空磁导率 H/m
    double I = 10.0;       // 电流 A
    double r = 0.1;        // 距离 m
    double B = (mu0 * I) / (2 * M_PI * r); // 磁场强度 T
    cout << "磁场强度: " << std::scientific << std::setprecision(16) << B << endl;
    return 0;
}