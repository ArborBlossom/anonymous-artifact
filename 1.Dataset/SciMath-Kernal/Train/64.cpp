#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double R = 10000.0; // 电阻 Ω
    double C = 0.000047; // 电容 F
    double tau = R * C;
    cout << "时间常数 τ = " << std::scientific << std::setprecision(16) << tau << endl;
    return 0;
}