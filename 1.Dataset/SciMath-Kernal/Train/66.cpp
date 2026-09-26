#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double L = 0.01; // 电感 H
    double I = 2.0;  // 电流 A
    double E = 0.5 * L * I * I;
    cout << "储存能量 = " << std::scientific << std::setprecision(16) << E << "J\n" << endl;
    return 0;
}