#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double m = 250.0; // 质量 g
    double V = 200.0; // 体积 cm³
    double rho = m / V; // g/cm³
    cout << "密度 = " << std::scientific << std::setprecision(16) << rho << endl;
    return 0;
}