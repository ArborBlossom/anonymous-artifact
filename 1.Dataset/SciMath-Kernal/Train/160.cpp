#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double v0 = 20.0;    // 初速度 m/s
    double theta = 45.0;  // 发射角度 °
    double g = 9.81;     // 重力加速度 m/s²
    double k = 0.01;     // 空气阻力系数
    double m = 0.1;      // 质量 kg
    double t = 2.0;      // 时间 s
    double rad = theta * M_PI / 180.0;
    double vy = (v0 * sin(rad) - (m * g) / k) * exp(-k * t / m) + (m * g) / k;
    cout << "速度vy: " << std::scientific << std::setprecision(16) << vy << endl;
    return 0;
}