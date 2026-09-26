#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 1.225;   // 空气密度 kg/m³
    double Cl = 1.2;       // 升力系数
    double A = 10.0;       // 机翼面积 m²
    double v = 60.0;       // 速度 m/s
    double L = 0.5 * rho * Cl * A * v * v; // 升力 N
    cout << "升力: " << std::scientific << std::setprecision(16) << L << endl;
    return 0;
}