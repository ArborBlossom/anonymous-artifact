#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k = 8.98755e9; // 库仑常数 N·m²/C²
    double q1 = 1e-6;     // 电荷1 C
    double q2 = 1e-6;     // 电荷2 C
    double r = 0.1;       // 距离 m
    double F = k * q1 * q2 / (r * r);
    cout << "库仑力: " << std::scientific << std::setprecision(16) << F << endl;
    return 0;
}