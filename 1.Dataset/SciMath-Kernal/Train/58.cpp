#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 2.5; // 质量 kg
    double cp = 4.18; // 比热容 kJ/kg·K
    double t1 = 25.0;
    double t2 = 80.0; // 初末温度 °C
    double deltaT = t2 - t1;
    double q = m * cp * deltaT; // 热量
    cout << "吸收热量 Q = " << std::scientific << std::setprecision(16) << q << endl;
    return 0;
}
