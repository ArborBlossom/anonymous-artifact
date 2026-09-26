#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 10.0;    // 质量 kg
    double v = 5.0;     // 速度 m/s
    double KE = 0.5 * m * v * v;
    cout << "动能: " << std::scientific << std::setprecision(16) << KE << endl;
    return 0;
}