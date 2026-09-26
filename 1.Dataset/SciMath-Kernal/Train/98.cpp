#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double V = 400.0; // 相电压 V
    double I = 10.0;  // 电流 A
    double pf = 0.9;  // 功率因数
    double P = sqrt(3.0) * V * I * pf;
    cout << "三相功率 P = " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}