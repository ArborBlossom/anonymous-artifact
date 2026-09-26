#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double W = 500.0;   // 功 J
    double t = 10.0;    // 时间 s
    double P = W / t;   // 功率 W
    cout << "功率: " << std::scientific << std::setprecision(16) << P << endl;
    return 0;
}