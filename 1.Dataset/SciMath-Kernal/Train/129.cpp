#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 1000.0; // 流体密度 kg/m³
    double v1 = 2.0;     // 点1速度 m/s
    double v2 = 5.0;     // 点2速度 m/s
    double P1 = 100000.0; // 点1压强 Pa
    double h1 = 0.0;     // 点1高度 m
    double h2 = 2.0;     // 点2高度 m
    double g = 9.81;     // 重力加速度 m/s²
    double P2 = P1 + 0.5*rho*(v1*v1 - v2*v2) + rho*g*(h1 - h2);
    cout << "点2压强: " << std::scientific << std::setprecision(16) << P2 << endl;
    return 0;
}