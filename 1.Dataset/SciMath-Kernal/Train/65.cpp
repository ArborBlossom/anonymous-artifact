#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double I0 = 1000.0; // 初始强度 W/m^2
    double d1 = 2.0;
    double I1 = I0 / (d1 * d1);
    cout << "强度 = " << std::scientific << std::setprecision(16) << I1 << endl;
    return 0;
}