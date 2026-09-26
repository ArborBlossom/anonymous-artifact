#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double f = 0.02;    // 摩阻系数
    double L = 50.0;    // 管道长度 m
    double D = 0.1;     // 管径 m
    double rho = 1000.0; // 流体密度 kg/m^3
    double v = 2.0;     // 流速 m/s
    double dp = f * (L / D) * 0.5 * rho * v * v;
    cout << "压降 ΔP = " << std::scientific << std::setprecision(16) << dp << "Pa" << endl;
    return 0;
}