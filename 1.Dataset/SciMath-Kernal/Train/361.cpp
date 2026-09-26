#include <stdio.h>
#include <math.h>
#ifndef M_PI//
#define M_PI 3.14159265358979323846//
#endif//
#include <iostream>//
#include <iomanip> //
using namespace std;//

double ellipsoidVolume(double a, double b, double c) {
    return 4.0/3.0 * M_PI * a * b * c;
}

int main() {
    double axes[][3] = {{1,2,3},{2,3,4},{0.5,1,1.5}};
    double v = ellipsoidVolume(axes[2][0], axes[2][1], axes[2][2]);
    cout << "Axes(axes[i][0],axes[i][i],axes[i][2]) Vol = " << std::scientific << std::setprecision(16) << v << endl;
    return 0;
}