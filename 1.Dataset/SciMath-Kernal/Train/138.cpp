#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double C1 = 0.0001;  // 电容1 F
    double C2 = 0.0002;  // 电容2 F
    double C3 = 0.0003;  // 电容3 F
    double C_eq = 1.0 / (1.0/C1 + 1.0/C2 + 1.0/C3);
    cout << "串联等效电容: " << std::scientific << std::setprecision(16) << C_eq << endl;
    return 0;
}