#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double n1 = 1.0;      // 第一介质折射率
    double n2 = 1.5;      // 第二介质折射率
    double theta1 = 30.0; // 入射角 °
    double rad1 = theta1 * M_PI / 180.0;
    double rad2 = asin(n1 * sin(rad1) / n2); // 折射角 rad
    double theta2 = rad2 * 180.0 / M_PI;     // 折射角 °
    cout << "折射角: " << std::scientific << std::setprecision(16) << theta2 << endl;
    return 0;
}