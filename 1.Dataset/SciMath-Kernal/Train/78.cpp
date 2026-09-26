#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double angle = 35.0; // 入射角度 °
    double intensity = 1000.0; // 入射强度 W/m²
    double effective = intensity * cos(angle * M_PI / 180.0);
    cout << "有效强度 = " << std::scientific << std::setprecision(16) << effective << endl;
    return 0;
}