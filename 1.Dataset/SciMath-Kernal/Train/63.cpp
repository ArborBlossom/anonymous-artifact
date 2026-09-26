#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double P1 = 100000; // 初始压强 Pa
    double V1 = 1.0;    // 初始体积 m^3
    double V2 = 0.5;    // 终止体积 m^3
    double gamma = 1.4; // 空气绝热指数
    double P2 = P1 * pow(V1 / V2, gamma);
    cout << "终压强 P2 = " << std::scientific << std::setprecision(16) << P2 << endl;
    return 0;
}