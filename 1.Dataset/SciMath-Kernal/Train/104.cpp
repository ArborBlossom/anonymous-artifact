#include <stdio.h>
#define PI 3.14159
#include <iostream>//
#include <iomanip> //
using namespace std;//

double sphereVolume(double r) {
    return (4.0 / 3.0) * PI * r * r * r;
}

int main() {
    double radius = 3.0;
    sphereVolume(radius);
    cout << "体积 = " << std::scientific << std::setprecision(16) << sphereVolume(radius) << endl;
    return 0;
}