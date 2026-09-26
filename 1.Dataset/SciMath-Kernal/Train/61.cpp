#include <stdio.h>
#include <math.h>
#include <iostream>//
#include <iomanip> //
using namespace std;//

int main() {
    double T = 25.0; // 温度 °C
    double gamma = 1.4;
    double R = 287.05; // 空气气体常数 J/kg·K
    double temp_K = T + 273.15;
    double speed = sqrt(gamma * R * temp_K);
    cout << "声速 = " << std::scientific << std::setprecision(16) << speed << endl;
    return 0;
}
