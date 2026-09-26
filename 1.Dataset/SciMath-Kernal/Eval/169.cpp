#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double r = 0.001;    // 球体半径 m
    double v = 0.01;     // 速度 m/s
    double mu = 0.001;   // 粘度 Pa·s
    double F = 6 * M_PI * mu * r * v; // 阻力 N
    cout << "斯托克斯阻力: " << std::scientific << std::setprecision(16) << F << endl;
    return 0;
}