#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double C = 0.0001;    // 电容 F
    double V = 12.0;      // 电压 V
    double E1 = 0.5 * C * V * V; // 能量公式1
    cout << "电容储存能量 (公式1): " << std::scientific << std::setprecision(16) << E1 << endl;
    return 0;
}