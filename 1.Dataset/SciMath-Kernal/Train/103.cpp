#include <stdio.h>
#define G 9.81
#include <iostream>//
#include <iomanip> //
using namespace std;//

double buoyantForce(double rho, double volume) {
    return rho * G * volume;
}

int main() {
    double fluidDensity = 1000.0;
    double objectVolume = 0.03;
    buoyantForce(fluidDensity, objectVolume);
    cout << "浮力 = " << std::scientific << std::setprecision(16) << buoyantForce(fluidDensity, objectVolume) << endl;
    return 0;
}