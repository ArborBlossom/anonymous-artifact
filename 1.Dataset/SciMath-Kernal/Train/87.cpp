#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double Kb = 0.512;     // 水的沸点常数 °C·kg/mol
    double m = 1.5;        // 质量摩尔浓度 mol/kg
    double delta_T = Kb * m;
    cout << "沸点提升 ΔT = " << std::scientific << std::setprecision(16) << delta_T << endl;
    return 0;
}