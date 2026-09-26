#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double A = 0.1;      // 振幅 m
    double omega = 2.0;  // 角频率 rad/s
    double t = 1.0;      // 时间 s
    double phi0 = 0.0;   // 初相位 rad
    double v = -A * omega * sin(omega * t + phi0);
    cout << "速度: " << std::scientific << std::setprecision(16) << v << endl;
    return 0;
}