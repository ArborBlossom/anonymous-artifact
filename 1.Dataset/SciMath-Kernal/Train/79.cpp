#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double I = 5.0;      // 电流 A
    double A = 2.0e-6;   // 横截面积 m²
    double J = I / A;    // 电流密度 A/m²
    cout << "电流密度 J = " << std::scientific << std::setprecision(16) << J << endl;
    return 0;
}