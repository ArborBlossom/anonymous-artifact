#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double v0 = 20.0;    // 初速度 m/s
    double theta = 45.0;  // 发射角度 °
    double rad = theta * M_PI / 180.0;
    double t = 2.0;      // 时间 s
    double x = v0 * cos(rad) * t;
    cout << "位置x: " << std::scientific << std::setprecision(16) << x << endl;
    return 0;
}