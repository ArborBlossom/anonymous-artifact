#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double a = 0.364;     // 分子间吸引力参数 Pa·m⁶/mol²
    double b = 4.27e-5;   // 分子体积参数 m³/mol
    double n = 1.0;       // 摩尔数 mol
    double V = 0.024;     // 体积 m³
    double T = 300.0;     // 温度 K
    double R = 8.314;     // 气体常数 J/mol·K
    double P = (n * R * T) / (V - n * b) - (a * n * n) / (V * V);
    cout << "压强: " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}