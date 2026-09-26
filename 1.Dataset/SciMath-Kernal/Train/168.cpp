#include <stdio.h>
#ifndef M_PI//
#define M_PI 3.14159265358979323846//
#endif//
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double mu0 = 4 * M_PI * 1e-7; // 真空磁导率 H/m
    double N1 = 100;      // 线圈1匝数
    double N2 = 200;      // 线圈2匝数
    double A = 0.001;    // 截面积 m²
    double l = 0.1;      // 长度 m
    double M = (mu0 * N1 * N2 * A) / l; // 互感 H
    cout << "互感: " << std::scientific << std::setprecision(16) << M << endl;
    return 0;
}