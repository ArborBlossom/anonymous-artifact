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
    double theta = 45.0;  // 角度 °
    double g = 9.81;     // 重力加速度 m/s²
    double rad = theta * M_PI / 180.0;
    double H = (v0 * v0 * sin(rad) * sin(rad)) / (2 * g); // 最大高度 m
    cout << "最大高度: " << std::scientific << std::setprecision(16) << H << endl;
    return 0;
}