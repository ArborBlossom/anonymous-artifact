#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 10.0;    // 质量 kg
    double g = 9.81;    // 重力加速度 m/s²
    double h = 5.0;     // 高度 m
    double GPE = m * g * h;
    cout << "重力势能: " << std::scientific << std::setprecision(16) << GPE << endl;
    return 0;
}