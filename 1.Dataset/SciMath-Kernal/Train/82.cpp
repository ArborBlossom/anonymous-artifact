#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double P = 101325.0;  // 压强 Pa
    double V = 0.1;       // 体积 m³
    double n = 1.0;       // 摩尔数
    double R = 8.314;     // 通用气体常数 J/mol·K
    double T = P * V / (n * R);
    cout << "气体温度 T = " << std::scientific << std::setprecision(16) << T << endl;
    return 0;
}