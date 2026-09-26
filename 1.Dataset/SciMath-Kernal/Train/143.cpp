#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 1000.0;   // 密度 kg/m³
    double v = 1.0;        // 流速 m/s
    double D = 0.05;       // 特征长度 m
    double mu = 0.001;     // 动力粘度 Pa·s
    double Re = rho * v * D / mu;
    cout << "雷诺数: " << std::scientific << std::setprecision(16) << Re << endl;
    return 0;
}