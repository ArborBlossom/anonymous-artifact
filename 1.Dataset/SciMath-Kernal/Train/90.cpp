#include <stdio.h>
#define EPSILON_0 8.854e-12
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double A = 0.01; // 平行板面积 m²
    double d = 0.001; // 距离 m
    double C = EPSILON_0 * A / d;
    cout << "电容 C = " << std::scientific << std::setprecision(16) << C << endl;
    return 0;
}