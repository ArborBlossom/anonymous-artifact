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
    double rad = theta * M_PI / 180.0;
    double t = 2.0;      // 时间 s
    double y = v0 * sin(rad) * t - 0.5 * g * t * t;
    cout << "位置y: " << std::scientific << std::setprecision(16) << y << endl;
    return 0;
}