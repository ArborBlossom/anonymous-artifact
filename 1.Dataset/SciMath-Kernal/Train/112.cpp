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
    double Vc = V0 * (1 - exp(-t/tau)); // 电容电压 V
    cout << "电容电压: " << std::scientific << std::setprecision(16) << Vc << endl;
    return 0;
}