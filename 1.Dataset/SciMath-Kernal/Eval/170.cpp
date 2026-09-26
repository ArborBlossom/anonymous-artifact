#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double f0 = 440.0;   // 源频率 Hz
    double c = 343.0;    // 声速 m/s
    double vs = 30.0;    // 源速度 m/s
    double vo = 10.0;    // 观察者速度 m/s
    double f = f0 * (c + vo) / (c - vs); // 观测频率 Hz
    cout << "观测频率: " << std::scientific << std::setprecision(16) << f << endl;
    return 0;
}