#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double h = 6.626e-34; // 普朗克常数 J·s
    double m = 9.11e-31;  // 电子质量 kg
    double v = 1e6;       // 速度 m/s
    double lambda = h / (m * v); // 德布罗意波长 m
    cout << "德布罗意波长: " << std::scientific << std::setprecision(16) << lambda << endl;
    return 0;
}