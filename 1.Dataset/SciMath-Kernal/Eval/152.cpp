#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double I = 0.5;     // 电流 A
    double R = 24.0;    // 电阻 Ω
    double P = I * I * R; // 功率 W
    cout << "电阻功率: " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}