#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double v = 2.5e8;    // 速度 m/s
    double c = 3e8;      // 光速 m/s
    double t0 = 1.0;     // 本征时间 s
    double gamma = 1 / sqrt(1 - (v*v)/(c*c)); // 洛伦兹因子
    double t = gamma * t0; // 观测时间 s
    cout << "观测时间: " << std::scientific << std::setprecision(16) << t << endl;
    return 0;
}