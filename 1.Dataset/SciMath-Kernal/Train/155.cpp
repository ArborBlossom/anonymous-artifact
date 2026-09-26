#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double B = 0.5;     // 磁场强度 T
    double A = 0.01;    // 面积 m²
    double theta = 30.0; // 角度 °
    double rad = theta * M_PI / 180.0;
    double phi = B * A * cos(rad);
    cout << "磁通量: " << std::scientific << std::setprecision(16) << phi << endl;
    return 0;
}