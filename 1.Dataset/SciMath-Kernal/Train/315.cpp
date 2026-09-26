#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

double sphericalTriangleArea(double A, double B, double C, double R) {
    // 球面过度 E = A+B+C - π
    double E = A + B + C - M_PI;
    return E * R * R;
}

int main() {
    // 以对边角（弧度）A,B,C 为 1.0,1.2,1.1，R=1.0
    double area = sphericalTriangleArea(1.0,1.2,1.1,1.0);
    cout << "Spherical Triangle Area ≈ " << std::scientific << std::setprecision(16) << area << endl;
    return 0;
}