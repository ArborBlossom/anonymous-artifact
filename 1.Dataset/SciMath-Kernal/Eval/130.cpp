#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double mu0 = 1.2566e-6;     // 真空磁导率 H/m
    double E = 100.0;           // 电场强度 V/m
    double B = 0.001;           // 磁场强度 T
    double S = (E * B) / mu0;   // 坡印廷矢量 W/m²
    cout << "坡印廷矢量: " << std::scientific << std::setprecision(16) << S << endl;
    return 0;
}