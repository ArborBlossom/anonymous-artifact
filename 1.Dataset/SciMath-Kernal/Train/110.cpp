#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    const double G = 6.67430e-11;   // 引力常数 m³/kg/s²
    const double M_earth = 5.972e24; // 地球质量 kg
    double h = 400000.0;            // 轨道高度 m
    double R_earth = 6371000.0;     // 地球半径 m
    double a = R_earth + h;         // 半长轴 m
    double T = 2 * M_PI * sqrt(pow(a, 3) / (G * M_earth)); // 轨道周期 s
    cout << "轨道周期:  " << std::scientific << std::setprecision(16) << T << endl;
    return 0;
}