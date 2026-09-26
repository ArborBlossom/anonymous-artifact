#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 1.225; // 空气密度 kg/m^3
    double Cd = 0.3;    // 阻力系数
    double A = 2.2;     // 迎风面积 m^2
    double v = 45.0;    // 速度 m/s
    double drag = 0.5 * rho * Cd * A * v * v;
    cout << "空气阻力 = " << std::scientific << std::setprecision(16) << drag << endl;
    return 0;
}