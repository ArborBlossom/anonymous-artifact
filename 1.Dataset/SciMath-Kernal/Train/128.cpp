#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 2.0;      // 质量 kg
    double v = 5.0;      // 速度 m/s
    double r = 0.5;      // 半径 m
    double I = m * r * r; // 转动惯量 kg·m²
    double omega = v / r; // 角速度 rad/s
    double L = I * omega; // 角动量 kg·m²/s
    cout << "角动量: " << std::scientific << std::setprecision(16) << L << endl;
    return 0;
}