#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double sigma = 5.6703e-8; // Stefan-Boltzmann 常数 W/(m²·K⁴)
    double A = 2.0;     // 表面积 m²
    double T = 500.0;   // 温度 K
    double P = sigma * A * pow(T, 4);
    cout << "总辐射功率 P = " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}