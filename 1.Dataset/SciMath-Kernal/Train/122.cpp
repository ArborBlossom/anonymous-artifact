#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    const double G = 6.67430e-11;   // 引力常数 m³/kg/s²
    const double M_earth = 5.972e24; // 地球质量 kg
    double h = 400000.0;            // 轨道高度 m
    double R_earth = 6371000.0;     // 地球半径 m
    double r = R_earth + h;         // 轨道半径 m
    double v = sqrt(G * M_earth / r); // 轨道速度 m/s
    cout << "轨道速度: " << std::scientific << std::setprecision(16) << v << endl;
    return 0;
}