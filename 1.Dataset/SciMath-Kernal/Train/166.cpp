#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double H0 = 70.0;      // 哈勃常数 km/s/Mpc
    double d = 100.0;      // 距离 Mpc
    double v = H0 * d;     // 退行速度 km/s
    cout << "退行速度: " << std::scientific << std::setprecision(16) << v << endl;
    return 0;
}