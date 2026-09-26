#include <stdio.h>
#define PI 3.14159
#include <iostream>//
#include <iomanip> //
using namespace std;//

double sphereSurface(double r) {
    return 4 * PI * r * r;
}

int main() {
    double radius = 3.0;
    sphereSurface(radius);
    cout << "表面积 = " << std::scientific << std::setprecision(16) << sphereSurface(radius) << endl;
    return 0;
}