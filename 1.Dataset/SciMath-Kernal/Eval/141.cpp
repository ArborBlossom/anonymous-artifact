#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double P = 101325.0; // 压强 Pa
    double V = 0.0224;   // 体积 m³ (1 mol at STP)
    double n = 1.0;      // 摩尔数 mol
    double R = 8.314;    // 气体常数 J/(mol·K)
    double T = P * V / (n * R);
    cout << "温度: " << std::scientific << std::setprecision(16) << T << endl;
    return 0;
}