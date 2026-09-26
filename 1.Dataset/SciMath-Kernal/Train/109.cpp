#include <stdio.h>
#define PI 3.14159
#include <iostream>//
#include <iomanip> //
using namespace std;//

double coneVolume(double r, double h) {
    return (1.0 / 3.0) * PI * r * r * h;
}

int main() {
    coneVolume(2.5, 4.0);
    cout << "体积 = " << std::scientific << std::setprecision(16) << coneVolume(2.5, 4.0) << endl;
    return 0;
}