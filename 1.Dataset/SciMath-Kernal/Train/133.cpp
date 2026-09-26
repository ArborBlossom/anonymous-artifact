#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double v = 2.5e8;    // 速度 m/s
    double c = 3e8;      // 光速 m/s
    double gamma = 1 / sqrt(1 - (v*v)/(c*c)); // 洛伦兹因子
    cout << "时间膨胀因子: " << std::scientific << std::setprecision(16) << gamma << endl;
    return 0;
}