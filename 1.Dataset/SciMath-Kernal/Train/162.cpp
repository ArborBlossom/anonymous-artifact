#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double gamma = 1.4;   // 比热比
    double P1 = 100000.0; // 初始压强 Pa
    double P2 = 200000.0; // 最终压强 Pa
    double rho1 = 1.2;    // 初始密度 kg/m³
    double rho2 = rho1 * pow(P2 / P1, 1 / gamma);
    cout << "最终密度: " << std::scientific << std::setprecision(16) << rho2 << endl;
    return 0;
}