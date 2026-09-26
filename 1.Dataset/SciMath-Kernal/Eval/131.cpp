#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double epsilon0 = 8.854e-12; // 真空介电常数 F/m
    double mu0 = 1.2566e-6;     // 真空磁导率 H/m
    double c = 1 / sqrt(epsilon0 * mu0); // 光速 m/s
    cout << "光速计算值: " << std::scientific << std::setprecision(16) << c << endl;
    return 0;
}