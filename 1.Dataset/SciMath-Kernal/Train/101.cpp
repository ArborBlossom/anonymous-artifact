#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double c = 3e8;      // 光速 m/s
    double f = 5e14;     // 频率 Hz
    double lambda = c / f;
    cout << "波长 λ = " << std::scientific << std::setprecision(16) << lambda << endl;
    return 0;
}