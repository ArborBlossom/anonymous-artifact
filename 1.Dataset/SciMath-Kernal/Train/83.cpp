#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m0 = 1.0;      // 静质量 kg
    double v = 2.0e8;     // 速度 m/s
    double c = 3.0e8;     // 光速 m/s
    double m = m0 / sqrt(1 - (v * v) / (c * c));
    cout << "相对论质量 m = " << std::scientific << std::setprecision(16) << m << endl;
    return 0;
}