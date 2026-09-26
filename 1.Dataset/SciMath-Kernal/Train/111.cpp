#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k1 = 401.0;     // 铜的热导率 W/m·K
    double k2 = 0.026;     // 空气的热导率 W/m·K
    double k3 = 0.18;      // 木材的热导率 W/m·K
    double A = 0.01;       // 截面积 m²
    double dT = 100.0;     // 温差 K
    double d1 = 0.02;      // 铜层厚度 m
    double d2 = 0.03;      // 空气层厚度 m
    double d3 = 0.01;      // 木材层厚度 m
    double Q = dT / (d1/(k1*A) + d2/(k2*A) + d3/(k3*A)); // 热传导率 W
    cout << "热传导率: " << std::scientific << std::setprecision(16) << Q << endl;
    return 0;
}