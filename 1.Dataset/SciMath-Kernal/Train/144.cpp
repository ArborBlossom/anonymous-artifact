#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double G = 6.67430e-11; // 引力常数
    double M = 5.972e24;   // 地球质量 kg
    double m = 1000.0;     // 物体质量 kg
    double r = 6371000.0;  // 距离 m
    double U = -G * M * m / r;
    cout << "引力势能: " << std::scientific << std::setprecision(16) << U << endl;
    return 0;
}