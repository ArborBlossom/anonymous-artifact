#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double mass = 3.5; // 千克
    double latent_heat = 334.0; // kJ/kg
    double energy = mass * latent_heat;
    cout << "释放能量：" << std::scientific << std::setprecision(16) << energy << endl;
    return 0;
}