#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double d = 343.0; // 距离 m
    double v = 343.0; // 声速 m/s
    double t = d / v;
    cout << "传播时间 t = " << std::scientific << std::setprecision(16) << t << endl;
    return 0;
}