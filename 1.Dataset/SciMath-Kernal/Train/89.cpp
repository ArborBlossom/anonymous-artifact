#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k = 8.9875e9; // N·m²/C²
    double q = 1e-6;     // C
    double r = 0.2;      // m
    double E = k * q / (r * r);
    cout << "电场强度 E = " << std::scientific << std::setprecision(16) << E << endl;
    return 0;
}