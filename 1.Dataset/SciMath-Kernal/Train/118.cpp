#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double q = 1.6e-19;  // 电荷量 C
    double E = 100.0;    // 电场强度 V/m
    double v = 1e6;      // 速度 m/s
    double B = 0.5;      // 磁场强度 T
    double theta = 30.0; // 角度 °
    double rad = theta * M_PI / 180.0;
    double F = q * (E + v * B * sin(rad)); // 洛伦兹力 N
    cout << "洛伦兹力: " << std::scientific << std::setprecision(16) << F << endl;
    return 0;
}