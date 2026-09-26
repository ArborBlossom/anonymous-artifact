#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double C = 0.0001;    // 电容 F
    double V = 12.0;      // 电压 V
    double Q = C * V;     // 电荷量 C
    double E2 = 0.5 * Q * V;     // 能量公式2
    cout << "电容储存能量 (公式2): " << std::scientific << std::setprecision(16) << E2 << endl;
    return 0;
}