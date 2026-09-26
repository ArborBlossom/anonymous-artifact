#include <stdio.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double k_WmK = 0.026; // W/(m·K)
    double k_cal = k_WmK * 0.2388459; // kcal/(m·h·°C)
    cout << "热导率转换为：" << std::scientific << std::setprecision(16) << k_cal << endl;
    return 0;
}