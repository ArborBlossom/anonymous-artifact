#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k = 8.9875e9; // 静电常数 N·m²/C²
    double q1 = 1e-6;    // C
    double q2 = 2e-6;    // C
    double r = 0.05;     // m
    double U = k * q1 * q2 / r;
    cout << "势能 U = " << std::scientific << std::setprecision(16) << U << endl;
    return 0;
}