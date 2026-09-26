#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho = 998.0; // 水密度 kg/m^3
    double v = 2.0;     // 流速 m/s
    double D = 0.05;    // 管径 m
    double mu = 0.001;  // 动态粘度 Pa·s
    double Re = rho * v * D / mu;
    cout << "雷诺数 Re = " << std::scientific << std::setprecision(16) << Re << endl;
    return 0;
}