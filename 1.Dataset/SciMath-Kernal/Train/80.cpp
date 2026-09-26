#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 1000.0; // 水密度 kg/m³
    double g = 9.81;     // 重力加速度 m/s²
    double h = 5.0;      // 高度差 m
    double P = rho * g * h;
    cout << "液柱压强差 ΔP = " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}