#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double gamma = 1.4;   // 比热比
    double P1 = 100000.0; // 初始压强 Pa
    double T1 = 300.0;    // 初始温度 K
    double P2 = 200000.0; // 最终压强 Pa
    double T2 = T1 * pow(P2 / P1, (gamma - 1) / gamma);
    cout << "最终温度: " << std::scientific << std::setprecision(16) << T2 << endl;
    return 0;
}