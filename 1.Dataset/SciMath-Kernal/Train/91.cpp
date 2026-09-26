#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double rho_liquid = 950.0; // 液体密度 kg/m³
    double rho_water = 1000.0; // 水的密度
    double sg = rho_liquid / rho_water;
    cout << "液体比重 SG = " << std::scientific << std::setprecision(16) << sg << endl;
    return 0;
}