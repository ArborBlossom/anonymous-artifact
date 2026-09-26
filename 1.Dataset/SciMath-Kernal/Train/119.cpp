#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho_fluid = 1025.0; // 流体密度 kg/m³
    double g = 9.81;          // 重力加速度 m/s²
    double V = 0.03;          // 排水体积 m³
    double Fb = rho_fluid * g * V; // 浮力 N
    cout << "浮力: " << std::scientific << std::setprecision(16) << Fb << endl;
    return 0;
}