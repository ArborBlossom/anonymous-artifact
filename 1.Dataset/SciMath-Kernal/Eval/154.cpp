#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double C = 0.0001;  // 电容 F
    double V = 12.0;    // 电压 V
    double E = 0.5 * C * V * V;
    cout << "电容储能: " << std::scientific << std::setprecision(16) << E << endl;
    return 0;
}