#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 1.0;      // 静质量 kg
    double v = 2.5e8;    // 速度 m/s
    double c = 3e8;      // 光速 m/s
    double gamma = 1 / sqrt(1 - (v*v)/(c*c));
    double KE = (gamma - 1) * m * c * c;
    cout << "相对论动能: " << std::scientific << std::setprecision(16) << KE << endl;
    return 0;
}