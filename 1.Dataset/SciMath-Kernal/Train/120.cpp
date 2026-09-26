#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double E = 200e9;      // 弹性模量 Pa
    double alpha = 1.2e-5; // 热膨胀系数 /°C
    double deltaT = 100.0;  // 温度变化 °C
    double sigma = E * alpha * deltaT; // 热应力 Pa
    cout << "热应力: " << std::scientific << std::setprecision(16) << sigma << endl;
    return 0;
}