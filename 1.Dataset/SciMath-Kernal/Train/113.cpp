#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double V0 = 12.0;     // 电源电压 V
    double R = 1000.0;    // 电阻 Ω
    double C = 0.001;     // 电容 F
    double t = 1.0;       // 时间 s
    double tau = R * C;   // 时间常数 s
    double I = (V0 / R) * exp(-t/tau);   // 电流 A
    cout << "电流: " << std::scientific << std::setprecision(16) << I << endl;
    return 0;
}