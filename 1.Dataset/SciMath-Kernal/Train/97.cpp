#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double Vp = 220.0; // 原边电压 V
    double Np = 1000.0;
    double Ns = 100.0;
    double Vs = Vp * (Ns / Np);
    cout << "副边电压 Vs = " << std::scientific << std::setprecision(16) << Vs << endl;
    return 0;
}