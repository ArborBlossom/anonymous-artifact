#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k_w = 401.0; // W/m·K（铜）
    double k_cal = k_w * 0.2388459; // kcal/m·h·°C
    cout << "热导率 = " << std::scientific << std::setprecision(16) << k_cal << endl;
    return 0;
}