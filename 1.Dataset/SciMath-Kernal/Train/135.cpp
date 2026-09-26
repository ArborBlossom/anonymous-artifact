#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double G = 6.67430e-11; // 引力常数 m³/kg/s²
    double c = 3e8;         // 光速 m/s
    double M = 1e31;        // 天体质量 kg
    double Rs = (2 * G * M) / (c * c); // 史瓦西半径 m
    cout << "史瓦西半径: " << std::scientific << std::setprecision(16) << Rs << endl;
    return 0;
}