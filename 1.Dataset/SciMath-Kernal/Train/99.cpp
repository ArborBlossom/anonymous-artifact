#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double g0 = 9.80665; // m/s²
    double h = 1000.0;   // 高度 m
    double R = 6371000.0; // 地球半径 m
    double g = g0 * pow(R / (R + h), 2);
    cout << "重力 = " << std::scientific << std::setprecision(16) << g << endl;
    return 0;
}